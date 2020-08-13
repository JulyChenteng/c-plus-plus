#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <vector>
#include "Thread.h"

//线程管理类 作为一个包工头，管理N个线程（派发线程）
class CThreadPool
{
public:
	CThreadPool(int size);
	~CThreadPool();

public:
	bool pushJob(JobFunc jobFunc, WPARAM wParam, LPARAM lParam, JobCallBack jobCb);
	int getPoolSize();

private:
	std::vector<CThread *> m_vecThread;   //管理所有的线程
};

#endif