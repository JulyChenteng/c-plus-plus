#include "Thread.h"

CThread::CThread()
{
	m_bIsWorking = false;
	m_jobFunc = NULL;
	m_jobCb = NULL;
	m_lParam = 0;
	m_wParam = 0;
	m_hThread =CreateThread(0, 0, (LPTHREAD_START_ROUTINE)threadProc, this, 0, 0);

	std::cout << "new Thread ::  " << std::hex << m_hThread << std::endl;
}

CThread::~CThread()
{
	//if (m_hThread != INVALID_HANDLE_VALUE)
	//{
	//	TerminateThread(m_hThread, 0);			//强制停止线程
	//}
	if (m_hThread != INVALID_HANDLE_VALUE)
	{
		m_jobFunc = (JobFunc)INVALID_HANDLE_VALUE;
		m_jobCb = (JobCallBack)INVALID_HANDLE_VALUE;
		ResumeThread(m_hThread);
		WaitForSingleObject(m_hThread, INFINITE);
		CloseHandle(m_hThread);
	}
}

bool  CThread::isWorking()		//判断是否正在运行
{
	return m_bIsWorking;
}

/*执行一个具体的任务*/
void CThread::doJob(JobFunc jobFunc, WPARAM wParam, LPARAM lParam, JobCallBack jobCb)				//指定任务
{
	this->m_jobFunc = jobFunc;
	this->m_jobCb = jobCb;
	this->m_wParam = wParam;
	this->m_lParam = lParam;

	ResumeThread(m_hThread);					//恢复线程
	std::cout << "Thread :  " << std::hex << m_hThread  << " is working......"<< std::endl;
}

//任务完成后
void CThread::jobDone()
{
	m_bIsWorking = false;
	SuspendThread(m_hThread);          //挂起线程
}

//真正的线程函数
static DWORD WINAPI threadProc(LPARAM lParam)			//真正的线程函数
{
	CThread *pThis = (CThread *)lParam;
	while (true)
	{
		if (pThis->m_jobFunc == (JobFunc)INVALID_HANDLE_VALUE || pThis->m_jobCb == (JobCallBack)INVALID_HANDLE_VALUE)
		{
			std::cout << "Thread :  " << std::hex << pThis->m_hThread << " exit !" << std::endl;
			break;
		}

		//线程是在构造函数中申请的，但是第一次申请的时候并没有具体的任务
		if (pThis->m_jobFunc == NULL || pThis->m_jobCb == NULL)
		{
			pThis->jobDone();
		}

		pThis->m_bIsWorking = true;
		unsigned int result = pThis->m_jobFunc(pThis->m_wParam, pThis->m_lParam);
		pThis->m_jobCb(result);
		pThis->jobDone();
	}

	return 0;
}
