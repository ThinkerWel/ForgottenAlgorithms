#pragma warning(disable: 4996)
#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <stdio.h>
#include <string>

SOCKET Connect[100];
int Counter = 0;

enum  Packet
{
	P_ChatMessage
};

bool ProcessPacket(int index, Packet packettype)
{
	switch (packettype) {
	case P_ChatMessage:
	{
		int msg_size;
		recv(Connect[index], (char*)&msg_size, sizeof(int), NULL);
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connect[index], msg, msg_size, NULL);
		for (int i = 0; i < Counter; i++) {
			if (i == index) {
				continue;
			}
			Packet msgtype = P_ChatMessage;
			send(Connect[i], (char*)&msgtype, sizeof(Packet), NULL);
			send(Connect[i], (char*)&msg_size, sizeof(int), NULL);
			send(Connect[i], msg, msg_size, NULL);
		}
		delete[] msg;
		break;
	}
	default:
		printf("No packet #2 !!!");
		break;
	}
	return true;
}

void Sclient(int index) {
	Packet packettype;
	
	while (true) {
		recv(Connect[index], (char*)&packettype, sizeof(Packet), NULL);
		if (!ProcessPacket(index, packettype)) {
			break;
		}

	}
	closesocket(Connect[index]); 
	
}

int main(int argc, char* argv[]) {
	
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		printf("Error #1 %d\n", WSAGetLastError());
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	

	SOCKET Client;
	for (int i = 0; i < 100; i++) {
		Client = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (Client == 0) {
			printf("Error #2\n");
		}
		else {
			printf( "Client Connected!\n");
			std::string msg = "Hello Client,i m Conencting!";
			int msg_size = msg.size();

			Packet msgtype = P_ChatMessage;
			send(Client, (char*)&msgtype, sizeof(Packet), NULL);

			send(Client, (char*)&msg_size, sizeof(int), NULL);
			send(Client, msg.c_str(), msg_size, NULL);

			Connect[i] = Client;
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Sclient, (LPVOID)(i), NULL, NULL); 

		}
	}
	
	system("pause");
	return 0;
}