#pragma once
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
namespace TCPClintForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		SOCKET sConnect;
		static String^ sendData;
		static bool check;
		bool connected;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		//void SendKeys();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:


	private: System::Windows::Forms::Button^  button1;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(101, 116);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textbox1_KeyDown);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyUp);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(114, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Link Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		check = new bool(false);
		sendData = gcnew String("");
		connected = false;
	}

	private: System::Void textbox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		sendData = "D" + ((int)e->KeyCode).ToString();
		SendKeys();
	}
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		//sendData = "D" + ((int)e->KeyCode).ToString();
	}
	private: System::Void textBox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		sendData = "U" + ((int)e->KeyCode).ToString();
		SendKeys();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		check = true;
		SendKeys();
	}
	private:void SendKeys()
	{
		char message[200];
		int buffer;
		String^ Send = gcnew String("");
		//開始 Winsock-DLL
		char key[4];
		int i,r;
		if (!connected)
		{
			WSAData wsaData;
			WORD DLLVersion;
			DLLVersion = MAKEWORD(2, 1);
			SOCKADDR_IN addr;
			connected = true;
			r = WSAStartup(DLLVersion, &wsaData);

			//宣告給 socket 使用的 sockadder_in 結構

			int addlen = sizeof(addr);

			//設定 socket

			//AF_INET: internet-family
			//SOCKET_STREAM: connection-oriented socket
			sConnect = socket(AF_INET, SOCK_STREAM, NULL);

			//設定 addr 資料
			addr.sin_addr.s_addr = inet_addr("127.0.0.1");
			//192.168.1.128
			addr.sin_family = AF_INET;
			addr.sin_port = htons(1234);
			if (TCPClintForm::MyForm::check != true) return;
			connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
			r = recv(sConnect, message, sizeof(message), 0);
			MessageBox::Show("you can go");
		}
		if (Send != sendData)
		{
			Send = sendData;
			for (i = 0; i < Send->Length; i++)
			{
				key[i] = Send[i];
			}
			r = send(sConnect, key, sizeof(key), 0);
		}
		//closesocket(sConnect);
	}
	};
}