#include "Adapter.h"

Adapter::Adapter()
{
}

int setRunning(bool run)
{

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

	int default_port = (char*)(void*)System::Runtime::InteropServices::Marshal(tb_port->Text);

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

	if (getaddrinfo(NULL, DEFAULT_PORT, &hints, &result) != 0)
	{
		System::Windows::Forms::MessageBox::Show("GetAddrInfo Error", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);

		WSACleanup();
		closesocket(master);

		exit(EXIT_FAILURE);
	}

	master = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (master == INVALID_SOCKET)
	{
		System::Windows::Forms::MessageBox::Show("Error on socket create!", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);

		WSACleanup();
		closesocket(master);

		exit(EXIT_FAILURE);
	}

	if (bind(master, result->ai_addr, result->ai_addrlen) == SOCKET_ERROR)
	{
		System::Windows::Forms::MessageBox::Show("Error in bind socket!", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);

		WSACleanup();
		closesocket(master);

		exit(EXIT_FAILURE);
	}

	listen(master, SOMAXCONN);
	addrlen = sizeof(struct sockaddr_in);
	fd_set readfds;
	char* fail = (char*)malloc(255);

	while (true)
	{
		//clear the socket fd set
		FD_ZERO(&readfds);
		//add master socket to fd set
		FD_SET(master, &readfds);
		if ((new_socket = accept(master, NULL, NULL)) == INVALID_SOCKET)
		{
			System::Windows::Forms::MessageBox::Show("Error accept conection with client!", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);

			WSACleanup();
			closesocket(master);

			exit(EXIT_FAILURE);
		}

		valread = recv(new_socket, buffer, MAX_RECV, 0);
		while (valread > 0)
		{
			switch (valread)
			{
			case -1:
				if (WSAGetLastError() == 10054)
					sprintf(fail, "Client desconected, ip %s , port %d", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
				else
					sprintf(fail, "recv failed with error code : %d", WSAGetLastError());

				System::Windows::Forms::MessageBox::Show(gcnew System::String(fail), "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				closesocket(new_socket);
				break;
			case 0:
				sprintf(fail, "Client desconected, ip %s , port %d", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

				System::Windows::Forms::MessageBox::Show(gcnew System::String(fail), "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				closesocket(new_socket);
				break;
			default:
				/* do stuff here */

				shutdown(new_socket, 1);
				ZeroMemory(buffer, MAX_RECV);

				break;
			}

			valread = 0;
		}
	}

	closesocket(new_socket);
	WSACleanup();

	exit(EXIT_SUCCESS);
}