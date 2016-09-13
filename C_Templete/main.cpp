//Client

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//#include "stdafx.h"
#include <WINSOCK2.H>
#include <STDIO.H>

#pragma  comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		system("Pause");
		return 1;
	}

	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{

		system("Pause");
		return 1;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(27015);
	serAddr.sin_addr.s_addr = inet_addr("192.168.1.150");
	if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		printf("connect error !");
		closesocket(sclient);
		system("Pause");
		return 1;
	}
	char * sendData = "hello!!!\n";
	send(sclient, sendData, strlen(sendData), 0);
	
	char recData[255];
	int ret = recv(sclient, recData, 255, 0);
	if (ret > 0)
	{
		recData[ret] = 0x00;
		printf(recData);
	}
	
	closesocket(sclient);
	WSACleanup();
	system("Pause");
	return 0;
}