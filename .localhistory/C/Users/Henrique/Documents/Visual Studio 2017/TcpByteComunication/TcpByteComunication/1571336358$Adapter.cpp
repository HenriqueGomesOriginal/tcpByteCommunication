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
	System::Windows::Forms::RichTextBox^ rt_return = (System::Windows::Forms::RichTextBox^)form1->Controls->Find((System::String^)"rt_return", true)[0];

	System::Windows::Forms::RadioButton^ rb_hex = (System::Windows::Forms::RadioButton^)form1->Controls->Find((System::String^)"rb_hex", true)[0];
	System::Windows::Forms::RadioButton^ rb_ascii = (System::Windows::Forms::RadioButton^)form1->Controls->Find((System::String^)"rb_ascii", true)[0];

	System::Windows::Forms::TextBox^ tb_host = (System::Windows::Forms::TextBox^)form1->Controls->Find((System::String^)"tb_host", true)[0];
	System::Windows::Forms::TextBox^ tb_port = (System::Windows::Forms::TextBox^)form1->Controls->Find((System::String^)"tb_port", true)[0];

	const char* aux = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tb_port->Text);
	const char* host = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(tb_host->Text);
	const char* msg = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(rt_message->Text);

	int default_port = atoi(aux);

	//Alloc buffer memory
	buffer = (char*)malloc(MAX_RECV);

	int pos = 0;
	char* byteArr = (char*)malloc(255);
	if (rb_hex->Checked == true)
	{
		char* byte = (char*)malloc(8);
		int j = 0;

		for (int i = 0; i < strlen(msg); i++)
		{
			if (msg[i] == ' ')
			{
				int aux;
				byte[j] = 0x00;
				aux = atoi(byte);

				byteArr[pos] = (char)aux;
				j = 0;
				pos++;
				continue;
			}
			byte[j] = msg[i];
			j++;
		}
	}
	//byteArr[pos] = '\0';
	String^ debug = rt_message->Text;

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

	server.sin_addr.s_addr = inet_addr(host);			//endere�o do servidor
	server.sin_family = AF_INET;						//ipv4
	server.sin_port = htons(default_port);				//porta

	//if (getaddrinfo(NULL, (PCSTR)default_port, &hints, &result) != 0)
	//{
	//	System::Windows::Forms::MessageBox::Show("GetAddrInfo Error", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	//	WSACleanup();
	//	return;
	//}

	ConnectSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ConnectSocket == INVALID_SOCKET)
	{
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	iResult = connect(ConnectSocket, (struct sockaddr *)&server, sizeof(server));
	if (iResult == SOCKET_ERROR)
	{
		MessageBox::Show("Not possible to connect to server...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		return;
	}

	iResult = send(ConnectSocket, byteArr, pos, 0);
	if (iResult == SOCKET_ERROR)
	{
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return;
	}

	iResult = recv(ConnectSocket, buffer, MAX_RECV, 0);
	if (iResult == SOCKET_ERROR)
	{
		MessageBox::Show("Error retrieve message...", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		closesocket(ConnectSocket);
		WSACleanup();
		return;
	}
	
	buffer[iResult] = '\0';

	int auxChar;
	char* hex = (char*)malloc(32);
	for (int i = 0; i < iResult; i++)
	{
		auxChar = (int)buffer[i];
		sprintf(hex, "%x", auxChar);
		rt_return->AppendText(gcnew String(hex) + " ");
	}

	closesocket(ConnectSocket);
	WSACleanup();

	return;
}