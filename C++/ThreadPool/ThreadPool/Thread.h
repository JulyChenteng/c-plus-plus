#ifndef  _THREAD_H
#define _THREAD_H

#include <iostream>
#include <windows.h>

/*
װ�޹����߳��࣬ÿ��������ʵ����һ���߳�
1. �̺߳���ִ��������˳�
2. �߳�������ɺ�ռ�õ���ԴҪ��
3. �߳���Ķ�����Ҫ���Ե���ִ�е�����
4. �߳�����ִ�У������ٷ�����������
*/

//�߳�Ҫ��������
typedef unsigned int (*JobFunc)(WPARAM wParam, LPARAM lParam);
//�߳���ɺ�֪ͨ�ص�����
typedef void(*JobCallBack)(unsigned int pResult);

class CThread
{
public :
	CThread();
	~CThread();

public:
	bool isWorking();			//�ж��Ƿ���������
	void doJob(JobFunc jobFunc, WPARAM wParam, LPARAM lParam, JobCallBack jobCb);				//ָ������
	void jobDone();			//�������

public:
	bool m_bIsWorking;
	JobFunc m_jobFunc;
	JobCallBack m_jobCb;
	WPARAM m_wParam;
	LPARAM m_lParam;
	HANDLE m_hThread;
};

static DWORD WINAPI threadProc(LPARAM lParam);			//�������̺߳���
#endif