#include "ThreadPool.h"			   

void TestPool()
{
	ThreadPool pool(2);
	
	std::thread thd1([&pool]{
		for (int i = 0; i < 10; ++i)
		{
			auto thdId = std::this_thread::get_id();
			pool.AddTask([thdId, i]{
				std::cout << i <<  "ͬ�����߳�1���߳�ID: " << thdId << std::endl;
			});
		}
	});

	std::thread thd2([&pool]{
		for (int i = 0; i < 10; ++i)
		{
			auto thdId = std::this_thread::get_id();
			pool.AddTask([thdId, i](){
				std::cout << i << "ͬ�����߳�2���߳�ID: " << thdId << std::endl;
			});
		}
	});

	std::this_thread::sleep_for(std::chrono::seconds(5));
	getchar();

	pool.Stop();
	thd1.join();
	thd2.join();
}

int main()
{
	TestPool();

	return 0;
}