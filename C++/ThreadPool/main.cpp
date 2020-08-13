/*CreateThreadPool(); //API*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "ThreadPool.h"

unsigned int job(WPARAM wParam, LPARAM lParam)
{
	printf("job doing : %d + %d = ?\n", wParam, lParam );
	Sleep(1000);
	return wParam + lParam;
}

void cb(unsigned int pResult)
{
	printf("job result : %d\n\n", pResult);
}

int main()
{
	CThreadPool *myPool = new CThreadPool(2);
	while (true)
	{
		char cmd = _getch();
		if (cmd == 'q' || cmd == 'Q')
			break;

		printf("thread pool size: %d \n", myPool->getPoolSize());
		myPool->pushJob(job, 10, 20, cb); 
	}

	delete myPool;
	myPool = NULL;

	return 0;
}