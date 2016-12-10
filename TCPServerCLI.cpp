
#include "stdafx.h"
#include <string.h>
#include <sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <assert.h>
#include <Windows.h>
#include <Winuser.h>
#include <iostream>
#include <string>
#include <tchar.h>
#include <queue>

#using<system.dll>
#using <System.Windows.Forms.dll>
#using <System.dll>
#pragma comment (lib, "ws2_32.lib")

using namespace System::Threading;
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Forms;
using namespace std;
char id;
std::queue<int> keyqueue;
int main(array<System::String ^> ^args)
{
	//GUITHREADINFO currentWindowGuiThreadInfo;
	//DWORD procID;
	HWND h;
	int r;
	char buffer1[4],keycodechar[3];
	WSAData wsaData;
	WORD DLLVSERION;
	int keycode;
	//INPUT Input;
	DLLVSERION = MAKEWORD(2, 1);//Winsocket-DLL 版本

	//用 WSAStartup 開始 Winsocket-DLL
	r = WSAStartup(DLLVSERION, &wsaData);

	//宣告 socket 位址資訊(不同的通訊,有不同的位址資訊,所以會有不同的資料結構存放這些位址資訊)
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);

	//建立 socket
	SOCKET sListen; //listening for an incoming connection
	SOCKET sConnect; //operating if a connection was found

	//AF_INET：表示建立的 socket 屬於 internet family
	//SOCK_STREAM：表示建立的 socket 是 connection-oriented socket 
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	//設定位址資訊的資料
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//192.168.1.113
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);

	//設定 Listen
	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);//SOMAXCONN: listening without any limit

	//等待連線
	SOCKADDR_IN clinetAddr;
	while (true)
	{
		cout << "waiting..." << endl;

		if (sConnect = accept(sListen, (SOCKADDR*)&clinetAddr, &addrlen))
		{
			cout << "a connection was found" << endl;
			printf("server: got connection from %s\n", inet_ntoa(addr.sin_addr));

			//傳送訊息給 client 端
			char *sendbuf = "sending data test";
			send(sConnect, sendbuf, (int)strlen(sendbuf), 0);
			h = 0;
			/*while (1){
			if (!h)
			{
			cout << "no" << endl;
			h = FindWindow(NULL, _T("osu!"));
			}
			else {
			cout << h << endl;
			break;
			}
			}*/
			//KeyDown->Start();
			while (1)
			{
				int res = recv(sConnect, buffer1, sizeof(buffer1), 0);
				cout << buffer1[0] << buffer1[1] << buffer1[2] << buffer1[3] << endl;
				strncpy(keycodechar, buffer1 + 1, 3);
				keycode = atoi(buffer1);
				if (buffer1[0] == 'D')
				{
					if (keycode > 96) keycode -= 32;
					if (h)
					{
						SetForegroundWindow(h);
						keybd_event(keycode, 0, 0, 0);
						keybd_event(keycode, 0, KEYEVENTF_KEYUP, 0);
					}
				}
				else
				{
					if (keycode > 96) keycode -= 32;
					if (h)
					{
						SetForegroundWindow(h);
						keybd_event(keycode, 0, KEYEVENTF_KEYUP, 0);
					}
				}
				memset(keycodechar, '\0', sizeof(keycodechar));
				memset(buffer1, '\0', sizeof(buffer1));
			}
		}
	}
	//getchar();
}