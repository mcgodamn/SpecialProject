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
		static SOCKET sConnectPos;
		static String^ sendDataPos;
		static bool check;
		static bool checkPos;
		char* ip = "192.168.1.114";
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: AxAXVLC::AxVLCPlugin2^  axVLCPlugin21;
	private: System::Windows::Forms::Button^  button3;

	public:
		bool connected;
		bool connectedPos;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->axVLCPlugin21 = (gcnew AxAXVLC::AxVLCPlugin2());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axVLCPlugin21))->BeginInit();
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
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// axVLCPlugin21
			// 
			this->axVLCPlugin21->Enabled = true;
			this->axVLCPlugin21->Location = System::Drawing::Point(277, 12);
			this->axVLCPlugin21->Name = L"axVLCPlugin21";
			this->axVLCPlugin21->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axVLCPlugin21.OcxState")));
			this->axVLCPlugin21->Size = System::Drawing::Size(320, 240);
			this->axVLCPlugin21->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(114, 258);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"play";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 300);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->axVLCPlugin21);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseWheel);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axVLCPlugin21))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		check = new bool(false);
		checkPos = new bool(false);
		sendData = gcnew String("");
		connected = false;
		connectedPos = false;
		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN);
	}


	private: Void timer1_Tick(System::Object ^ sender, System::EventArgs ^ e){
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
		checkPos = true;
		Connection();
		ConnectionPos();
	}

	private:void ConnectionPos()
	{
		char messagePos[200];
		int bufferPos;
		char keyPos[4];
		int r;
		//開始 Winsock-DLL
		if (!connectedPos)
		{
			WSAData wsaData;
			WORD DLLVersion;
			DLLVersion = MAKEWORD(2, 1);
			SOCKADDR_IN addr;
			connectedPos = true;
			r = WSAStartup(DLLVersion, &wsaData);
			//宣告給 socket 使用的 sockadder_in 結構
			
			int addlen = sizeof(addr);

			//設定 socket

			//AF_INET: internet-family
			//SOCKET_STREAM: connection-oriented socket
			sConnectPos = socket(AF_INET, SOCK_STREAM, NULL);

			//設定 addr 資料
			addr.sin_addr.s_addr = inet_addr(ip);
			//192.168.1.128
			addr.sin_family = AF_INET;
			addr.sin_port = htons(1235);
			if (TCPClintForm::MyForm::checkPos != true) return;
			connect(sConnectPos, (SOCKADDR*)&addr, sizeof(addr));
			r = recv(sConnectPos, messagePos, sizeof(messagePos), 0);
			textBox1->Text = "oooo";
		}
		//Thread^ mm = gcnew Thread(gcnew ThreadStart(Mouse));
		//mm->Start();
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
			textBox1->Text = r.ToString();
			int addlen = sizeof(addr);

			//設定 socket

			//AF_INET: internet-family
			//SOCKET_STREAM: connection-oriented socket
			sConnect = socket(AF_INET, SOCK_STREAM, NULL);

			//設定 addr 資料
			addr.sin_addr.s_addr = inet_addr(ip);
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
		char widths[5], heights[5];
		for (int j = 0; j < width->Length; j++){
			widths[j] = width[j];
		}
		for (int j = 0; j < height->Length; j++){
			heights[j] = height[j];
		}
		r = send(sConnect, widths, sizeof(widths), 0);
		r = send(sConnect, heights, sizeof(heights), 0);
		//Thread^ thr1 = gcnew::Thread(gcnew::ThreadStart(SendKeys));
		//Thread^ thr2 = gcnew::Thread(gcnew::ThreadStart(Mouse));
		//thr1->Start();
		//thr2->Start();



		//closesocket(sConnect);
	}
	private:static void Mouse(){
		//if ()
		int r;
		String^ X = gcnew String("");
		String^ Y = gcnew String("");
		POINT p;
		if (GetCursorPos(&p)){
			X = "X" + p.x.ToString();
			Y = "Y" + p.y.ToString();
			char Xs[5], Ys[5];
			for (int j = 0; j < X->Length; j++){
				Xs[j] = X[j];
			}
			for (int j = 0; j < Y->Length; j++){
				Ys[j] = Y[j];
			}
			r = send(sConnectPos, Xs, sizeof(Xs), 0);
			r = send(sConnectPos, Ys, sizeof(Ys), 0);
		}
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
		for (int j = 0; j < width->Length; j++){
			widths[j] = width[j];
		}
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		int r;
		if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0)
		{
			//MessageBox::Show("LButton pressed");
			r = send(sConnect, "L", 1, 0);
		}

		if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0)
		{
			//MessageBox::Show("RButton pressed");
			r = send(sConnect, "R", 1, 0);
		}

		if ((GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0)
		{
			
			r = send(sConnect, "M", 1, 0);
		}
	}

	private: System::Void MyForm_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int r;
		if (e->Delta == 120){
			r = send(sConnect, "Z", 1, 0);//往前滾
		}

		if (e->Delta == -120){
			r = send(sConnect, "A", 1, 0);//往後滾
		}
		
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		axVLCPlugin21->playlist->add("rtsp://192.168.1.114:8554/","",nullptr);
		axVLCPlugin21->playlist->play();
	}
	
			int updownL = 0;//滑鼠左鍵狀態
			int updownR = 2;//滑鼠右鍵狀態
private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int r;
	if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0) {
		updownL += 1;
		
		r = send(sConnect, "L", 1, 0);
	}

	if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0) {
		updownR += 1;
		//textBox1->Text = updownR.ToString();
		r = send(sConnect, "R", 1, 0);
	}
}

private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int r;
	if (updownL == 1) {
		updownL -= 1;
		r = send(sConnect, "B", 1, 0);
	}
	if (updownR == 3) {
		updownR -= 1;
		//textBox1->Text = updownR.ToString();
		r = send(sConnect, "C", 1, 0);
	}
}
};


}