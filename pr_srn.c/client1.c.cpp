#pragma warning(disable : 4996) .
#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <winsock2.h>
#include <string.h>
#include <windows.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define PORT 666
#define SERVERADDR "127.0.0.1"
int main(int argc, char* arvg[])
{

	char buff[1024];
	printf("TC DEMO CLIENT\n");

	if (WSAStartup(0x202, (WSADATA*)&buff[0]))
	{
		printf("WSAStartup error %d\n", WSAGetLastError());
		return -1;

	}
	SOCKET my_sock;
	my_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (my_sock < 0)
	{
		printf("Socket()error %d\n", WSAGetLastError());
		return -1;
	}
	// заполнение структуры sockaddr_in
   // указание адреса и порта сервера
	sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(PORT);
	HOSTENT* hst;

	if (inet_addr(SERVERADDR) != INADDR_NONE)
		dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
	else
		if (hst =gethostbyname(SERVERADDR))
			// hst->h_addr_list содержит не массив адресов,
	 // а массив указателей на адреса
			((unsigned long*)&dest_addr.sin_addr)[0] =
			((unsigned long**)hst->h_addr_list)[0][0];
		else
		{
			printf("invalid addres %s\n", SERVERADDR);
			closesocket(my_sock);
			WSACleanup();
			return -1;
		}
	// адрес сервера получен – пытаемся установить
 // соединение 

	if (connect(my_sock, (sockaddr*)&dest_addr,
		sizeof(dest_addr)))
	{
		printf("COnnect error %d\n", WSAGetLastError());
			return -1;

	}

	printf("Соеденение %s успешно установлен \n,", SERVERADDR);
		// Шаг 4 - чтение и передача сообщений
	int nsize;
	while ((nsize = recv(my_sock, &buff[0],
		sizeof(buff) - 1, 0))
		!= SOCKET_ERROR)
		{
			// ставим завершающий ноль в конце строки 
			buff[nsize] = 0;
			// Выводим на экран 
			printf("S>=%s", buff);
			// читаем пользовательский ввод с клавиатуры

			printf("S<=C:");
			fgets(&buff[0], sizeof(buff) - 1,
				stdin);
			// проверка на quit
			if (!strcmp(&buff[0], "quit\n"))
			{
				//Корректный выход
				printf("EXIT");
				closesocket(my_sock);
				WSACleanup();
				return 0;
			}
			// передаем строку клиенту серверу
			send(my_sock, &buff[0], nsize, 0);
		}
	printf("Recv error %d\n", WSAGetLastError());
	closesocket(my_sock);
	WSACleanup;
	return -1;
}