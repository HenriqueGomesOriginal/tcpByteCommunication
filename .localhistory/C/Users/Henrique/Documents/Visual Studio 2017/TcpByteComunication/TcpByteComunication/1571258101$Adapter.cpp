#include "Adapter.h"

Adapter::Adapter()
{
}

int Adapter::setRunning(bool run)
{
	running = run;
	return 0;
}

bool Adapter::getRunning()
{
	return running;
}

void Adapter::init(Object^ form)
{
	System::Windows::Forms::Form^ form1 = (System::Windows::Forms::Form^)form;
	System::Windows::Forms::RichTextBox^ rt_message = (System::Windows::Forms::RichTextBox^)form1->Controls->Find((System::String^)"rt_message", true)[0];
	System::Windows::Forms::RichTextBox^ rt_return  = (System::Windows::Forms::RichTextBox^)form1->Controls->Find((System::String^)"rt_return", true)[0];
	
	System::Windows::Forms::RadioButton^ rb_hex  = (System::Windows::Forms::RadioButton^)form1->Controls->Find((System::String^)"rb_hex", true)[0];
	System::Windows::Forms::RadioButton^ rb_ascii = (System::Windows::Forms::RadioButton^)form1->Controls->Find((System::String^)"rb_ascii", true)[0];
	
	System::Windows::Forms::TextBox^ tb_host = (System::Windows::Forms::TextBox^)form1->Controls->Find((System::String^)"tb_host", true)[0];
	System::Windows::Forms::TextBox^ tb_port = (System::Windows::Forms::TextBox^)form1->Controls->Find((System::String^)"tb_port", true)[0];

	const char* aux  = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tb_port->Text);
	const char* host = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tb_host->Text);
	const char* msg  = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(rt_message->Text);

	int default_port = atoi(aux);

	//Alloc buffer memory
	buffer = (char*)malloc(MAX_RECV);
	
	char* byteArr = (char*)malloc(255);
	if (rb_hex->Checked == true)
	{
		char* byte = (char*)malloc(8);
		int j = 0;
		int pos = 0;

		for (int i = 0; i < strlen(msg); i++)
		{
			if (msg[i] == ' ')
			{
				byte[j] = 0x00;
				int aux = atoi(byte);
				byteArr[pos] = (char)aux;
				j = 0;
				pos++;
				continue;
			}
			byte[j] = msg[i];
			j++;
		}
	}

	WSADATA wsa;
	SOCKET ConnectSocket;

	struct addrinfo *result = NULL, *ptr = NULL, hints;
	struct sockaddr_in server, address;
	int addrlen, valread;
	int iResult;

	buffer = (char*)malloc(MAX_RECV);

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		System::Windows::Forms::MessageBox::Show("WsaErrorCode: " + WSAGetLastError(), "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		exit(EXIT_FAILURE);
	}
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	if (getaddrinfo(NULL, (PCSTR)default_port, &hints, &result) != 0)
	{
		System::Windows::Forms::MessageBox::Show("GetAddrInfo Error", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		WSACleanup();
		return;
	}

	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
	if (ConnectSocket == INVALID_SOCKET) 
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		return;
	}

	iResult = send(ConnectSocket, buffer, (int)strlen(buffer), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return;
	}

	closesocket(ConnectSocket);
	WSACleanup();

	return;
}