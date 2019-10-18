#pragma once

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "BioAuth.h"

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable : 4996)

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define DEFAULT_PORT "3001"
#define MAX_RECV 650000

ref class Adapter
{
public:
	Adapter();
};

