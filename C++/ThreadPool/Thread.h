#ifndef  _THREAD_H
#define _THREAD_H

#include <iostream>
#include <windows.h>

/*
装修工，线程类，每个对象中实例化一个线程
1. 线程函数执行完后不能退出
2. 线程运行完成后占用的资源要少
3. 线程类的对象需要可以调整执行的任务
4. 线程正在执行，不能再分配其他任务
*/

//线程要做的事情
typedef unsigned int (*JobFunc)(WPARAM wParam, LPARAM lParam);
//线程完成后通知回调函数
typedef void(*JobCallBack)(unsigned int pResult);

class CThread
{
public :
	CThread();
	~CThread();

public:
	bool isWorking();			//判断是否正在运行
	void doJob(JobFunc jobFunc, WPARAM wParam, LPARAM lParam, JobCallBack jobCb);				//指定任务
	void jobDone();			//任务完成

public:
	bool m_bIsWorking;
	JobFunc m_jobFunc;
	JobCallBack m_jobCb;
	WPARAM m_wParam;
	LPARAM m_lParam;
	HANDLE m_hThread;
};

static DWORD WINAPI threadProc(LPARAM lParam);			//真正的线程函数
#endif