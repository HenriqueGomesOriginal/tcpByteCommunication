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

void Adapter::getRunning()
{

}

void Adapter::init(Object^ form)
{
	System::Windows::Forms::Form^ form1 = (System::Windows::Forms::Form^)form;
	System::Windows::Forms::RichTextBox^ rt_message = (System::Windows::Forms::RichTextBox^)form1->Controls->Find((System::String^)"rt_message", true)[0];
	System::Windows::Forms::RichTextBox^ rt_return  = (System::Windows::Forms::RichTextBox^)form1->Controls->Find((System::String^)"rt_return", true)[0];
	
	System::Windows::Forms::TextBox^ tb_host = (System::Windows::Forms::TextBox^)form1->Controls->Find((System::String^)"tb_host", true)[0];
	System::Windows::Forms::TextBox^ tb_port = (System::Windows::Forms::TextBox^)form1->Controls->Find((System::String^)"tb_port", true)[0];

	int default_port = (int)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tb_port->Text);
	const char* host = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tb_host->Text);

	WSADATA wsa;
	SOCKET master, new_socket;

	struct addrinfo *result = NULL, *ptr = NULL, hints;
	struct sockaddr_in server, address;
	int addrlen, valread;

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
		closesocket(master);

		exit(EXIT_FAILURE);
	}

	closesocket(new_socket);
	WSACleanup();

	exit(EXIT_SUCCESS);
}