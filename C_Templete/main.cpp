//Client

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//#include "stdafx.h"
#include <WINSOCK2.H>
#include <STDIO.H>
#include <string>
#pragma  comment(lib,"ws2_32.lib")
using namespace std;
void Requery()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		system("Pause");
		//return 1;
	}

	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{

		system("Pause");
		//return 1;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(27015);
	serAddr.sin_addr.s_addr = inet_addr("192.168.1.150");
	for (int i = 0; i < 10; i++)
	{
		sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{
			printf("connect error !");
			closesocket(sclient);
			system("Pause");
			//return 1;
		}



		string sendData = "hello!!!";
		string new_data = string(sendData);

		new_data = new_data +to_string(i)+"\n";
		
		send(sclient, new_data.c_str(), strlen(new_data.c_str()), 0);

		
		
		closesocket(sclient);
		printf("zzZ....");
		Sleep(3000);

		printf("Next Turn\n");
	}
	
	
	/*
	char recData[255];
	int ret = recv(sclient, recData, 255, 0);
	if (ret > 0)
	{
		recData[ret] = 0x00;
		printf(recData);
	}

	*/
	
	
	WSACleanup();
	system("Pause");
	//return 0;
}
int main() 
{
	Requery();
	return 0;
}
