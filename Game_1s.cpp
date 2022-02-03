#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <windows.h>

#define mapWi 60
#define mapHeihg 25
typedef  struct sobject { // структура хранящиеся кординаты персонажа 
	float x, y;
	float width, height; //хранит ширину и высоту 
	float vertSpeed; // добавляем вертикальную скорость 
	BOOL IsFly; // говорить находится ли персонаж воздухе 
	char cType;
}Tobject;

char map[mapHeihg][mapWi + 1]; // создание карты 
Tobject mario;     // переменая для персонажа 
Tobject* brick = NULL; // объект на которое персонаж будет приземляться 
int brickLenght;
int level = 1; // хранить номер уровня 


void ClearMap() {  // заполняем карту	
	for (int i = 0; i < mapWi; i++)
		map[0][i] = ' ';
	map[0][mapWi] = '\0';
	for (int j = 1; j < mapHeihg; j++)
		sprintf_s(map[j], map[0]);


}
void ShowWap() { // заполняем карту 
	map[mapHeihg - 1][mapWi - 1] = '\0';
	for (int j = 0; j < mapHeihg; j++)
		printf("%s", map[j]);

}
void setObject(Tobject* obj, float xpoz, float ypoz) // задает позицию персонажу 
{
	(*obj).x = xpoz;
	(*obj).y = ypoz;


}
void InitObject(Tobject* obj, float xPoz, float yPoz, float oWidth, float oHeigh, char inType) // иниализурует объект 
{
	setObject(obj, xPoz, yPoz);
	(*obj).width = oWidth;
	(*obj).height = oHeigh;
	(*obj).vertSpeed = 0; // иниализация скорости 
	(*obj).cType = inType;

}

BOOL IsCollision(Tobject o1, Tobject o2);
void CreateLevel(int lvl);

void  VertMove(Tobject* obj)	// перешитывает скорость  +
{
	(*obj).IsFly = TRUE;

	(*obj).vertSpeed += 0.05; // скорость 

	setObject(obj, (*obj).x, (*obj).y + (*obj).vertSpeed); // Задаем новую позицию		

	for (int i = 0; i < brickLenght; i++)
		if (IsCollision(*obj, brick[i]))
		{
			(*obj).y -= (*obj).vertSpeed; // если персонаж столкнется объектом он вернется назад 
			(*obj).vertSpeed = 0;
			(*obj).IsFly = FALSE; // если персонаж приземлился присваиваем значение false 
			if (brick[i].cType == '+') // проверка на столкновение объектов 
			{
				level++; // увеличивает уровень на 1 
				if (level > 3)  // если уровень больше 2 переходим снова на первый уровень так как у нас только 2 уровня 
					level = 1;
				CreateLevel(level);
				Sleep(1000);
			}
			break;
		}
}


BOOL isposMap(int x, int  y) // проверяет попадают ли кординаты в нашу карту 
{
	return((x >= 0) && (x < mapWi) && (y >= 0) && (y < mapHeihg));
}

void PutObject(Tobject obj) // отображает на карте персонажа  +
{
	int ix = (int)round(obj.x); // для round  нужен math.h
	int iy = (int)round(obj.y);
	int iWidth = (int)round(obj.width); // помещение объектов на карте   
	int iHeght = (int)round(obj.height);

	for (int i = ix; i < (ix + iWidth); i++) // устонавливаем позицию объекта 
		for (int j = iy; j < (iy + iHeght); j++)
			if (isposMap(i, j))
				map[j][i] = obj.cType;

}
void SetCur(int x, int y) // процедура для перемещение курсора 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // возращает адрес определяемым входным параметром 
}
void HorizonMove(float dx) // Перемещение  карты по гаризонтали 
{
	mario.x -= dx; // проверка на столкновение 
	for (int i = 0; i < brickLenght; i++) // для того чтобы могли пробежать по всем элементам массива brinck
		if (IsCollision(mario, brick[i]))
		{
			mario.x += dx;
			return;
		}
	mario.x += dx;

	for (int i = 0; i < brickLenght; i++)
		brick[i].x += dx;
}


BOOL IsCollision(Tobject o1, Tobject o2) // функиция которое проводит проверку на столкновение двух объектов 
{
	return((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
		((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}

void CreateLevel(int lvl) // задает уровень 
{

	InitObject(&mario, 39, 10, 3, 3, '@');
	if (lvl == 1)
	{
		brickLenght = 6;
		brick = (Tobject*)realloc(brick, sizeof(*brick) * brickLenght);
		InitObject(brick + 0, 20, 20, 40, 5, '#'); // блоки с помощью которых мы сможем ходить 
		InitObject(brick + 1, 60, 15, 10, 10, '#');
		InitObject(brick + 2, 80, 20, 20, 5, '#');
		InitObject(brick + 3, 120, 15, 10, 10, '#');
		InitObject(brick + 4, 150, 20, 40, 5, '#');
		InitObject(brick + 5, 210, 15, 10, 10, '+');
	}
	if (lvl == 2)
	{
		brickLenght = 4;
		brick = (Tobject*)realloc(brick, sizeof(*brick) * brickLenght);
		InitObject(brick + 0, 20, 20, 40, 5, '#');
		InitObject(brick + 1, 80, 20, 15, 5, '#');
		InitObject(brick + 2, 120, 15, 15, 10, '#');
		InitObject(brick + 3, 160, 10, 15, 15, '+');
	}
	if (lvl == 3)
	{
		brickLenght = 5;
		brick = (Tobject*)realloc(brick, sizeof(*brick) * brickLenght);
		InitObject(brick + 0, 30, 20, 40, 5, '#');
		InitObject(brick + 1, 80, 20, 15, 5, '#');
		InitObject(brick + 2, 100, 15, 15, 10, '#');
		InitObject(brick + 3, 120, 15, 15, 10, '#');
		InitObject(brick + 3, 145, 13, 10, 15, '+');

	}
}


int main() {

	CreateLevel(level);
	system("color 1F");


	do {
		ClearMap();

		if ((mario.IsFly == FALSE) && (GetKeyState(VK_SPACE) < 0))mario.vertSpeed = -1; // включает в программу клавишу пробелу для прыжка 
		if (GetKeyState('A') < 0)HorizonMove(1); // для перемещение карты 
		if (GetKeyState('D') < 0)HorizonMove(-1);

		if (mario.y > mapHeihg)CreateLevel(level); // чтобы персонаж после смерти оживлялся снова 

		VertMove(&mario);
		for (int i = 0; i < brickLenght; i++)  // для прохождение всех элементов(блоков)
			PutObject(brick[i]);
		PutObject(mario);// помещение персонажа 

		SetCur(0, 0); // позиция курсора 
		ShowWap();

		Sleep(10);
	} while (GetKeyState(VK_ESCAPE) >= 0);
	return 0;
}
