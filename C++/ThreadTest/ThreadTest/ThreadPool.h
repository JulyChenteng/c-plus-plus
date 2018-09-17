#include <list>
#include <thread>
#include <functional>
#include <atomic>
#include <memory>	
#include "SyncQueue.h"

const int MaxTaskCount = 100;
class ThreadPool
{
public:		 														  
	using Task = std::function<void()>;												 
	ThreadPool(int numThread = std::thread::hardware_concurrency()) : m_queue(MaxTaskCount)
	{
		Start(numThread);
	}		

	~ThreadPool(void)
	{
		Stop();
	}

	void Stop()
	{																				
		//��֤���߳������ֻ����һ��StopThreadGroup
		std::call_once(m_flag, [this]{StopThreadGroup(); });
	}

	void AddTask(Task&& task)
	{
		m_queue.Put(std::forward<Task>(task));
	}

	void AddTask(const Task& task)
	{
		m_queue.Put(task);
	}

private:
	void Start(int numThread)
	{
		m_running = true;
		//�����߳���
		for (int i = 0; i < numThread; ++i)
		{
			m_threadgroup.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
		}
	}

	void RunInThread()
	{
		while (m_running)
		{
			//ȡ����ֱ�ִ��
			std::list<Task> list;
			m_queue.Take(list);

			for (auto& task : list)
			{
				if (!m_running)
					return;

				task();
			}
		}
	}

	void StopThreadGroup()
	{
		m_queue.Stop();							//��ͬ�������е��߳�ֹͣ							 
		m_running = false;							//��Ϊfalse, ���ڲ��߳�����ѭ�����˳�

		for (auto thread : m_threadgroup)	//�ȴ��߳̽���
		{
			if (thread)
				thread->join();
		}		 
		m_threadgroup.clear();
	}

private: 
	std::list<std::shared_ptr<std::thread>> m_threadgroup;  //����������߳���
	SyncQueue<Task> m_queue;								// ͬ������
	std::atomic_bool m_running;							   //�Ƿ�ֹͣ�ı�־
	std::once_flag m_flag;							
};