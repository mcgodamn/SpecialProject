#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <assert.h>
#include <conio.h>
#include <windows.h>

#using <System.Windows.Forms.dll>
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "user32.lib")
using namespace System::Threading;
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
		static SOCKET sConnect;
		static String^ sendData;
		static bool check;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Timer^  timer1;

	public:
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
	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
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
			// button2
			// 
			this->button2->Location = System::Drawing::Point(114, 161);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Test";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(101, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(101, 52);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 6;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
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
		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN);
		
	}
	

	private: Void timer1_Tick(System::Object ^ sender,System::EventArgs ^ e){			
			textBox2->Text = Cursor->Position.X.ToString();
			textBox3->Text = Cursor->Position.Y.ToString();
			Mouse();
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
		Connection();
	}

	private:void Connection()
	{
		char message[200];
		int buffer;
		char key[4];
		int r;
		//開始 Winsock-DLL
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
			addr.sin_addr.s_addr = inet_addr("192.168.1.131");
			//192.168.1.128
			addr.sin_family = AF_INET;
			addr.sin_port = htons(1234);
			if (TCPClintForm::MyForm::check != true) return;
			connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
			r = recv(sConnect, message, sizeof(message), 0);
			
		}
		
			//textBox1->Text = "(" + width.ToString() + "," + height.ToString() + ")";
			//char width[5],height[5];
			String^ width = gcnew String("");
			String^ height = gcnew String("");
			width = "W" + GetSystemMetrics(SM_CXSCREEN).ToString();
			height = "W" + GetSystemMetrics(SM_CYSCREEN).ToString();
			char widths[5],heights[5];
			for (int j = 0; j < width->Length; j++){
				widths[j] = width[j];
			}
			for (int j = 0; j < height->Length; j++){
				heights[j] = height[j];
			}
			r = send(sConnect,widths , sizeof(widths), 0);
			r = send(sConnect, heights, sizeof(heights), 0);
			//Thread^ thr1 = gcnew::Thread(gcnew::ThreadStart(SendKeys));
			//Thread^ thr2 = gcnew::Thread(gcnew::ThreadStart(Mouse));
			//thr1->Start();
			//thr2->Start();
		
		
		
		//closesocket(sConnect);
	}
		private:static void Mouse(){
			int r;
			String^ X = gcnew String("");
			String^ Y = gcnew String("");
			X = "M" + GetSystemMetrics(SM_CXSCREEN).ToString();
			Y = "M" + GetSystemMetrics(SM_CYSCREEN).ToString();
			char Xs[5], Ys[5];
			for (int j = 0; j < X->Length; j++){
				Xs[j] = X[j];
			}
			for (int j = 0; j < Y->Length; j++){
				Ys[j] = Y[j];
			}
			r = send(sConnect, Xs, sizeof(Xs), 0);
			r = send(sConnect, Ys, sizeof(Ys), 0);
		}

	private:static void SendKeys(){
		String^ Send = gcnew String("");
		char key[4];
		int i, r;
		if (Send != sendData)
		{
			Send = sendData;
			for (i = 0; i < Send->Length; i++)
			{
				key[i] = Send[i];
			}
			r = send(sConnect, key, sizeof(key), 0);
		}
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ width = gcnew String("");
	width = "W" + GetSystemMetrics(SM_CYSCREEN).ToString();
	char widths[5];
	for (int j = 0; j < width->Length ; j++){
		widths[j] = width[j];
	}
}
};
}