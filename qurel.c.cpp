#include <stdio.h>

#define LOUR 7
int main(void)
{
	char ch[10] = { "dedpop" };

	float lour[7] = { 2.9,3.9,4.9,5.9,6.9,7.9,8.9 };
	int i;

	float megent[7] = { 2.5,3.5,5.5,6.5,8.5,7.5,9.5 };

	for (i = 0; i < LOUR; i++)
	{
		printf("no sorted array %.2f is %.2f\n", lour[i], megent[i]);

	}

	for (i = 1; i < LOUR; i++)

	{
		*ch = *megent;
		*megent = *lour;
		*lour = *ch;
		printf(" %s %.2f", ch, lour[i]);
	}
	printf("\n");
	printf("Sorted Array\n");
	for (i = 0; i < LOUR; i++)
	{
		printf("%.2f", lour[i]);
	}	

	for (i = 0; i < LOUR; i++)
	{
		printf("\nsort:%.2f", lour[i] / megent[i]);
	}

	for (i = 1; i < LOUR; i++) {
		
		ch[7] = megent[i];
		megent[i] = lour[i-1];
		lour[i-1] = ch[7];
		printf("\n");
		printf("%.2f  is houn  %.2f", lour[i], megent[i]);
	}

	for (i = 0; i < LOUR; i++) {
		printf("\n");
		printf(" sorted array :%.2f",lour[i]);
		
	}
	return 0;
}
