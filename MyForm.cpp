#include "MyForm.h"
#include <iostream>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <assert.h>
#include <conio.h>
#using <System.Windows.Forms.dll>
#pragma comment(lib, "Ws2_32.lib")

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace TCPClintForm;
int main(array<System::String ^> ^args)
{
	//char confirm;
	//char message[200];
	//int buffer;
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	/*
	//�}�l Winsock-DLL
	int r;
	WSAData wsaData;
	WORD DLLVersion;
	DLLVersion = MAKEWORD(2, 1);
	char key[3];
	r = WSAStartup(DLLVersion, &wsaData);

	//�ŧi�� socket �ϥΪ� sockadder_in ���c
	SOCKADDR_IN addr;

	int addlen = sizeof(addr);

	//�]�w socket
	SOCKET sConnect;

	//AF_INET: internet-family
	//SOCKET_STREAM: connection-oriented socket
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	//�]�w addr ���
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//192.168.1.128
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);
	while (1)
	{
		if (TCPClintForm::MyForm::check == true) break;
	}
	/*cout << "connect to server?[Y] or [N]" << endl;
	cin >> confirm;

	if (confirm == 'N')
	{
		exit(1);
	}
	/*else{
		if (confirm == 'Y' || confirm == 'y')
		{
			connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));

			//���� server �ݪ��T��
			//ZeroMemory(message, 200);
			r = recv(sConnect, message, sizeof(message), 0);
			cout << "you can go" << endl;
			while (1)
			{
				printf("%d\n", buffer);
				itoa(buffer, key, 10);
				r = send(sConnect, key, sizeof(key), 0);
				//(buffer);
				//r = send(sConnect, to_string(buffer).c_str(), sizeof(to_string(buffer).c_str()), 0);
			}

			//�]�w closesocket �ɡA���g�L TIME-WAIT �L�{,��������socket
			//BOOL bDontLinger = FALSE;
			//setsockopt(sConnect,SOL_SOCKET,SO_DONTLINGER,(const char*)&bDontLinger,sizeof(BOOL));

			//�Y���ᤣ�A�ϥΡA�i�� closesocket �����s�u
			closesocket(sConnect);

			getchar();
			getchar();
		}
	}
	*/
}