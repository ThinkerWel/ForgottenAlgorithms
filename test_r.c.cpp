#include <stdio.h>
int min(int* array, int greatl);
int max(int* array, int greatl);
int main(void)
{
	int lour[6] = { 10,20,30,17,90,49 };
	min(lour, 6);
	int num[6] = { 967,890,1001,773,325,1 };
	max(num, 6);
}
int min(int* array, int greatl)
{
	int minInt = array[0]; // принимаем 1 элемент за минимальный //
	for (int i = 1; i < greatl; i++){ // проходим по цилку и сравнимаем с нашим минимальным числом,
       // и если число меньше то присваиваем его minInt


		if (array[i] < minInt) {
			minInt = array[i];
		}
	}
	printf("*min=%d*\n", minInt);
	return minInt;
}
int max(int* array, int greatl)
{
	int maxInt = array[0]; // принимаем 1 элемент максимальный 
	for (int i = 0; i < greatl; i++) { // проходим по цилку и сравнимаем с нашим максимальным числом,
       // и если число больше то присваиваем его maxInt
		if (array[i] > maxInt) {
			maxInt = array[i];
		}
		
	}
	printf("*max=%d*\n", maxInt);
	return maxInt;
		
}