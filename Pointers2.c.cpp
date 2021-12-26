#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
void CREAT(int* p,int **olen);
int lopz(int milk);
int main(void)
{
	setlocale(LC_ALL, "Russian");
	int melon = 81;
	int* cwohen;
	cwohen = &melon;
	if (cwohen == NULL)
		cwohen++;
		printf("loading:%d\n", *cwohen);
		int** lops;
		lops = &cwohen;
		**lops = 8;
		if(lops!=NULL)
		printf("loading:%d\n", **lops);
		CREAT(cwohen, lops);

		lopz(1);

}
void CREAT(int* p, int** olen)
{
	int a[5] = { 10,20,30,40,50 };
	int zelon=0;
	int*zp;
	int** ousec;
	int* lops = &a[4];
	
	for (zp = a, ousec = &zp; olen < ousec; zp++)

		a[zelon] = *zp;

	printf(" loading: %d %d\n", a[1],*lops);
	**ousec = 2006;

	printf("loading:%d\n", **ousec/2);

	int*** lein = &ousec;

	printf("loading:%d\n", ***lein);

}
int lopz(int milk)
{
	int  a;
	scanf_s("%d", &a);
	if (a==false)
		printf("true:\n");
	else
	{
		printf("false\n");
	}
	return a;
}