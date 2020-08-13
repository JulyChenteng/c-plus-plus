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
	//	TerminateThread(m_hThread, 0);			//ǿ��ֹͣ�߳�
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

bool  CThread::isWorking()		//�ж��Ƿ���������
{
	return m_bIsWorking;
}

/*ִ��һ�����������*/
void CThread::doJob(JobFunc jobFunc, WPARAM wParam, LPARAM lParam, JobCallBack jobCb)				//ָ������
{
	this->m_jobFunc = jobFunc;
	this->m_jobCb = jobCb;
	this->m_wParam = wParam;
	this->m_lParam = lParam;

	ResumeThread(m_hThread);					//�ָ��߳�
	std::cout << "Thread :  " << std::hex << m_hThread  << " is working......"<< std::endl;
}

//������ɺ�
void CThread::jobDone()
{
	m_bIsWorking = false;
	SuspendThread(m_hThread);          //�����߳�
}

//�������̺߳���
static DWORD WINAPI threadProc(LPARAM lParam)			//�������̺߳���
{
	CThread *pThis = (CThread *)lParam;
	while (true)
	{
		if (pThis->m_jobFunc == (JobFunc)INVALID_HANDLE_VALUE || pThis->m_jobCb == (JobCallBack)INVALID_HANDLE_VALUE)
		{
			std::cout << "Thread :  " << std::hex << pThis->m_hThread << " exit !" << std::endl;
			break;
		}

		//�߳����ڹ��캯��������ģ����ǵ�һ�������ʱ��û�о��������
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
