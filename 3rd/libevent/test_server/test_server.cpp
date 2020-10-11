
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
	//! ��ʼ��windows socket��
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
#elif
	//! ���Թܵ��źţ��������ݸ��ѹرյ�socket��
	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		return 1;
#endif
	//! 1.����libevent������
	event_base* base = event_base_new();
	if (base) {
		cout << "event_base_new success!" << endl;
	}

	//! 2.�����˿�(socket, bind, listen) 
	sockaddr_in sin;
	memset(&sin, 0, sizeof(sockaddr_in));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(SPORT);

	evconnlistener *ev =  evconnlistener_new_bind(base,	// libevent������
		cb,							// �������ӻص����� 
		base,						// �ص���������
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,	// ��ַ����|eventlistener�رյ�ͬʱ�ر�socket
		10,							// δ�������Ӷ��д�С��Ӧlisten����
		(sockaddr*)&sin,							// �󶨵�ip��port
		sizeof(sin));

	//! 3. �¼��ַ�����
	if (base) {
		event_base_dispatch(base);
	}

	//! 4. ��Դ�ͷ�
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
