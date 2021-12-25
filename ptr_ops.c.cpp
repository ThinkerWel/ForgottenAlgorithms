#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int coun[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int* p1, * p2, * p3, * p4;
	p1 = coun;
	p2 = &coun[8];
	printf("\n Значение \n");
	printf("Адрес %p is %p is %d\n",
		p1, &p1, p1[9]);

	p3 = p1 + 5;
	printf("\nЗначение\n");
	printf("%p is %p\n",
		p1, &p1);
	p1++;
	printf("\nЗначение\n");
	printf("%p is %d is %p\n",
		p1, *p1, &p1);
	printf("\nЗначение\n");
	--p2;
	printf("%p is %d is %p\n",
		p2, *p2, &p2);
	p3[4] = p2[1] + p1[8];
	p3++;
	printf("\nЗначение\n");
	printf("%p is %d is %p\n",
		p3, *p3, &p3);
	printf("\nЗначение\n");
	printf("%d is %d is %d\n",
		p1[1],p2[1],p3[1]);





	return 0;
}