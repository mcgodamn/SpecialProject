
#include "stdafx.h"
#include <string.h>
#include <sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <assert.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <tchar.h>

#using<system.dll>
#using <System.Windows.Forms.dll>
#using <System.dll>
#pragma comment (lib, "ws2_32.lib")

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Forms;
using namespace std;
void window(string key);

int main(array<System::String ^> ^args)
{
	HWND h;
	int r;
	char buffer1[3];
	WSAData wsaData;
	WORD DLLVSERION;
	int keycode;
	DLLVSERION = MAKEWORD(2, 1);//Winsocket-DLL ����

	//�� WSAStartup �}�l Winsocket-DLL
	r = WSAStartup(DLLVSERION, &wsaData);

	//�ŧi socket ��}��T(���P���q�T,�����P����}��T,�ҥH�|�����P����Ƶ��c�s��o�Ǧ�}��T)
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);

	//�إ� socket
	SOCKET sListen; //listening for an incoming connection
	SOCKET sConnect; //operating if a connection was found

	//AF_INET�G��ܫإߪ� socket �ݩ� internet family
	//SOCK_STREAM�G��ܫإߪ� socket �O connection-oriented socket 
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	//�]�w��}��T�����
	addr.sin_addr.s_addr = inet_addr("192.168.1.113");
	//192.168.1.113
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);

	//�]�w Listen
	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);//SOMAXCONN: listening without any limit

	//���ݳs�u
	SOCKADDR_IN clinetAddr;
	while (true)
	{
		cout << "waiting..." << endl;

		if (sConnect = accept(sListen, (SOCKADDR*)&clinetAddr, &addrlen))
		{
			cout << "a connection was found" << endl;
			printf("server: got connection from %s\n", inet_ntoa(addr.sin_addr));

			//�ǰe�T���� client ��
			char *sendbuf = "sending data test";
			send(sConnect, sendbuf, (int)strlen(sendbuf), 0); 
			h = FindWindow(NULL, _T("1111.txt - �O�ƥ�"));
			HWND EditClass = FindWindowEx(h, NULL, NULL, NULL);
			//Little Fighter 2
			//HWND EditClass = FindWindowEx(h, NULL, "Edit", NULL);
			if (!EditClass)
			{
				printf("%s\n","fucku");
			}
			else
			{
				printf("%d\n", EditClass);
				while (1)
				{
					int res = recv(sConnect, buffer1, sizeof(buffer1), 0);
					printf("%s\n", buffer1);
					keycode = atoi(buffer1);
					printf("%d\n", keycode);
					if (h)
					{
						SendMessage(EditClass, WM_CHAR, keycode, 0);
						//0x002C0001
					}
					else printf("%s\n", "fucku");
					memset(buffer1, '\0', sizeof(buffer1));
				}
			}
		}
	}
	//getchar();
}