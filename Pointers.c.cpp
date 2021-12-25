#include <stdio.h>
#include <locale.h>
#define PEK 6
#define LOK 6
void disable(int a,int b );
int ins(int *a,int *b);
void funec(int **perl, char*given);
int main(void)
{
	setlocale(LC_ALL, "Russian");
	int loer[2] = { 8,20 };
	int puk[2] = { 5,6 };
	puk[1] += loer[1];
	char cloud[2] ;
	int** pie = 0;
	funec(pie, cloud);
	disable(LOK, PEK);
		ins(loer,puk);
		
	return 0;
}
int ins(int* a, int* b)
{
	int* loer;
	int bolt = 10;
	int xurex[5] = { 56,32,89,14 };
	loer = &bolt;
	loer = &xurex[2];
	while (loer > a)
			loer+= a[bolt];
	printf("%d is %d %d\n ", *loer,a[1],b[1]);
	return bolt;

}
void funec(int** perl, char* given)
{
	int count = 0;
	char ch;
	int **lesen = 0;
	char ouse[25] = " 'H' Good Morning 'H' " ;
	while (ch = getchar() != '\n')
		count++;
	
	printf("%s %d количество символов\n", ouse,ouse[count]);
}
void disable(int a, int b)
{
	int selor;
	int peult;
	int olesh=1;
	int secodn;
	
		for (peult = 1; peult < LOK; peult++)
		
			{
			for (selor = 1; selor < PEK; selor++)

				olesh -= selor + peult;
				secodn = selor * peult;
				printf("%d  it is   %d\n", olesh, secodn);
			}
		secodn *= selor / 2;
		printf("%4d\n", secodn*2);


	
}