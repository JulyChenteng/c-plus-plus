
#include <iostream>
#include <event2/event.h>
#include <event2/listener.h>

#include <string.h>

#ifndef _WIN32
#include <signal.h>
#endif

using namespace std;

#define SPORT 5001

void cb(struct evconnlistener*, evutil_socket_t, struct sockaddr*, int socklen, void*)
{
	cout << "call callback function!" << endl;
}


int main()
{
#ifdef _WIN32
	//! 初始化windows socket库
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
#elif
	//! 忽略管道信号（发送数据给已关闭的socket）
	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		return 1;
#endif
	//! 1.创建libevent上下文
	event_base* base = event_base_new();
	if (base) {
		cout << "event_base_new success!" << endl;
	}

	//! 2.监听端口(socket, bind, listen) 
	sockaddr_in sin;
	memset(&sin, 0, sizeof(sockaddr_in));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SPORT);

	evconnlistener *ev =  evconnlistener_new_bind(base,	// libevent上下文
		cb,							// 接收连接回调函数 
		base,						// 回调函数参数
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,	// 地址重用|eventlistener关闭的同时关闭socket
		10,							// 未处理连接队列大小对应listen函数
		(sockaddr*)&sin,							// 绑定的ip和port
		sizeof(sin));

	//! 3. 事件分发处理
	if (base) {
		event_base_dispatch(base);
	}

	//! 4. 资源释放
	if (ev) {
		evconnlistener_free(ev);
	}
	if (base) {
		event_base_free(base);
	}
#ifdef _WIN32
	WSACleanup();
#endif

	cout << "End." << endl;
	return 0;
}
