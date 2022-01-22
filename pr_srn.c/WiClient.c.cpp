#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#pragma warning(disable: 4996)
#include <string>

SOCKET Connection;

enum  Packet 
{
	P_ChatMessage
};

bool ProcessPacket(Packet packettype) // обработка приходящий пакетов
{
	switch (packettype) {// обработка типа пакета 
	case P_ChatMessage:
	{
		int msg_size;
		recv(Connection, (char*)&msg_size, sizeof(int), NULL);
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connection, msg, msg_size, NULL);
		printf("%s\n", msg);
		delete[] msg;
		break;
	}
	default:
		printf("no connected packet\n");
		break;
	}
	return true;
}

void Hendre()
{
	Packet packettype;
	while (true) {
		recv(Connection, (char*)&packettype, sizeof(Packet), NULL);
		if (!ProcessPacket(packettype))
		{
			break;
		}
	}

	closesocket(Connection);
}

int main(int argc, char* argv[]) {

	WSAData wsaData;
	WORD Lounge = MAKEWORD(2, 1);
	if (WSAStartup(Lounge, &wsaData) != 0) {
		printf("Error #1 %d\n", WSAGetLastError());
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;


	 Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		printf( "Error.\n");
		return 1;
	}
	printf("Connect!!!\n");
	
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Hendre, NULL, NULL,NULL);

	std::string msg2;

	while (true)
	{
		std::getline(std::cin, msg2);
		int msg_size = msg2.size();// размер строки 
		Packet packettype = P_ChatMessage;
		send(Connection, (char*)&packettype, sizeof(Packet), NULL); 
		send(Connection, (char*)&msg_size, sizeof(int), NULL); // посылаем строку серверу 
		send(Connection, msg2.c_str(), msg_size, NULL); // посылаем строку 

		Sleep(10);
	}
	system("pause");
	return 0;
}