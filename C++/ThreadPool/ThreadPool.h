#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <vector>
#include "Thread.h"

//�̹߳����� ��Ϊһ������ͷ������N���̣߳��ɷ��̣߳�
class CThreadPool
{
public:
	CThreadPool(int size);
	~CThreadPool();

public:
	bool pushJob(JobFunc jobFunc, WPARAM wParam, LPARAM lParam, JobCallBack jobCb);
	int getPoolSize();

private:
	std::vector<CThread *> m_vecThread;   //�������е��߳�
};

#endif