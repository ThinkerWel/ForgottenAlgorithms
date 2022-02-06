
#include <stdio.h>
#define _win3_WINNT 0x0A00
#include <windows.h>

int main() {
	HWND hwnd = GetConsoleWindow();

	LPPOINT Ppnt;
	LPRECT rct;

	rct = (LPRECT)malloc(sizeof(*rct));
	GetClientRect(hwnd, rct);
	// функция GetClient получает дескриптор окна для которого надо найти размер клиентской области 
		// узнает размер  клиентской области 


	LPRECT rctScr;
	rctScr = (LPRECT)malloc(sizeof(*rctScr));
	GetClientRect(GetDesktopWindow(), rctScr); // GetDesktopWindow возращает дескриптор рабочего стола 


	Ppnt = (LPPOINT)malloc(sizeof(*Ppnt));
	do {
		system("cls");
		GetCursorPos(Ppnt); // кординаты курсора  мыши 
		printf("\n Cursor pos: %d, %d\n", Ppnt[0].x, Ppnt[0].y);

		ScreenToClient(hwnd, Ppnt); // преобразует  глобальные кординаты мыши в локальные 
		printf("\n Local cursor pos: %d, %d\n", Ppnt[0].x, Ppnt[0].y);

		printf("\n sizeof  Client:%d x %d \n", rct[0].right, rct[0].bottom );

		printf("\n Screen size :%d x %d\n", rctScr[0].right, rctScr[0].bottom);

		if (GetKeyState(VK_LBUTTON) < 0)
			printf("\n Left  Mouse\n");

		Sleep(100);
	} while (GetKeyState(VK_ESCAPE) >= 0);
}