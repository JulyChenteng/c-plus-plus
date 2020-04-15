#include "ThreadPool.h"

CThreadPool::CThreadPool(int size)
{
	m_vecThread.clear();

	for (int i = 0; i < size; i++)
	{
		CThread *pThread = new CThread();
		m_vecThread.push_back(pThread);
	}
}

CThreadPool::~CThreadPool()
{
	auto it = m_vecThread.begin();
	for (; it != m_vecThread.end(); it++)
	{
		CThread *ptemp = *it;
		delete ptemp;
	}
}

bool CThreadPool::pushJob(JobFunc jobFunc, WPARAM wParam, LPARAM lParam, JobCallBack jobCb)
{
	auto it = m_vecThread.begin();
	for (; it != m_vecThread.end(); it++)
	{
		CThread *pThread = *it;
		if (!pThread->m_bIsWorking)
		{
			pThread->doJob(jobFunc, wParam, lParam, jobCb);
			return true;
		}
	}

	CThread *ptemp = new CThread();
	m_vecThread.push_back(ptemp);
	ptemp->doJob(jobFunc, wParam, lParam, jobCb);

	return true;
}

int CThreadPool::getPoolSize()
{
	return m_vecThread.size();
}