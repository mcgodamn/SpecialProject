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
	char buffer1[5], keycodechar[3];
	WSAData wsaData;
	WORD DLLVSERION;
	int keycode;
	//INPUT Input;
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
	addr.sin_addr.s_addr = inet_addr("192.168.1.115");
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
			h = 0;
			while (1){
				if (!h)
				{
					cout << "no" << endl;
					h = FindWindow(NULL, _T("VisualBoyAdvance-100%"));
				}
				else {
					cout << h << endl;
					break;
				}
			}
			//KeyDown->Start();
			int wwh = 0, windowsWH[2];
			char whbuffer[5],whchar[4];
			for (int h = 0; h < 2; h++){//client�ݪ��ѪR��
				int res = recv(sConnect, whbuffer, sizeof(whbuffer), 0);
				if (whbuffer[0] == 'W'){
					strncpy(whchar, whbuffer + 1, sizeof(whbuffer) - 1);
					windowsWH[wwh] = atoi(whchar);
					wwh += 1;
					memset(whchar, '\0', sizeof(whchar));
					memset(whbuffer, '\0', sizeof(whbuffer));
				}
			}
			double rateW = 1920.0f / windowsWH[0];//�ù��e����
			double rateH = 1080.0f / windowsWH[1];//�ù�������
			cout << "(" << rateW << "," << rateH << ")" << endl;
			int MousePos[2];
			char Mchar[4];
			while (1)
			{
				int res = recv(sConnect, buffer1, sizeof(buffer1), 0);
				
				if (buffer1[0] == 'X'){
					strncpy(Mchar, buffer1 + 1, sizeof(buffer1) - 1);
					MousePos[0] = atoi(Mchar) * rateW;
					memset(buffer1, '\0', sizeof(buffer1));
					memset(Mchar, '\0', sizeof(Mchar));
				}
				else if (buffer1[0] == 'Y'){
					strncpy(Mchar, buffer1 + 1, sizeof(buffer1) - 1);
					MousePos[1] = atoi(Mchar) * rateH;
					if (h)
					{
						SetForegroundWindow(h);
						SetCursorPos(MousePos[0], MousePos[1]);
					}
					memset(buffer1, '\0', sizeof(buffer1));
					memset(Mchar, '\0', sizeof(Mchar));
				}
				else if (buffer1[0] != 'W' && buffer1[0] != 'M'){
					
					//printf("%d\n", keycode);
					if (buffer1[0] == 'D')
					{
						strncpy(keycodechar, buffer1 + 1, sizeof(buffer1));
						keycode = atoi(keycodechar);
						cout << buffer1[0] << buffer1[1] << buffer1[2] << buffer1[3] << buffer1[4] << endl;
						if (keycode > 96) keycode -= 32;
						if (h)
						{
							SetForegroundWindow(h);
							keybd_event(keycode, 0, 0, 0);
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
	}
}