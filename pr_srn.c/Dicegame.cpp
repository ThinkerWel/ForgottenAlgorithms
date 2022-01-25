#include <stdio.h>
#include <locale.h>
#include "diceroll.h"
#include <time.h>
#include <stdlib.h>
static int rollem(int sides);
int roll_n_dice(int dice, int sides);
int roll_count = 0;
int main() {
	setlocale(LC_ALL, "Russian");
	int dice, roll;
	int sides;
	srand((unsigned int)time(0)); // рандомизация начального числа 
	printf("Введите количество граней кости или 0 для завершения программы\n");
	while (scanf_s("%d", &sides) == 1 && sides > 0)
	{
		printf("Сколько костей ?\n");
		if ((scanf_s("%d", &dice)) != 1)
		{
			if (roll== EOF)
				break;
			else
			{
				printf("Вы должны вести целое число\n");
				printf("Давайте начнем сначала");
				while (getchar() != '\n')
					continue;
				printf("Сколько граней ?Для прекращения введите \n");
				continue;
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("Вы бросали %d раз используя %d кости с %d гранями\n",
			roll, dice, sides);
		printf("Сколько граней ?для прекращения введите 0\n");
	}
	printf("Функиця rollem была вызвана %d\n", roll_count);
	printf("Пусть удача не покидает вас\n");
	return 0;
}
static int rollem(int sides)
{
	int roll;
	roll = rand() % sides +1 ;
	++roll_count;
	return roll;
}
int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if (sides < 2)
	{
		printf("Требуется пр меньшей мере 2 грани\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("Требуется по меньшей мере 1 кость\n");
		return -1;

	}
	for (d = 0; d < dice; d++)
		total += rollem(sides);
	return total;
}
