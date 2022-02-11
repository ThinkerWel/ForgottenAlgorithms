#include <stdio.h>
#include <stdlib.h>

int array(int arr[])

{
	int const lenst = 15;
	int dexl[15] = { 109,891,901,109,2,89,56,78,891,2,10,89,1001,56,83 };
	int cost = 0;

	for (int i = 0; i < lenst; i++) {
		for (int j = i + 1; j < lenst; j++) {
			if (dexl[i] == dexl[j]) {
				for (int n = j - 1; n < lenst; n++) {
					if (dexl[j] == dexl[n])
						cost++;
				}
				if (cost == 1)
				{
					printf("\tDuplicat Number : %d \t\n", dexl[i]);
					
				}
				cost = 0;
				
			}
		}
	}
	printf("\n");
	return *dexl;

}

int main()
{
	int n = 10;
	int* Delp = new int[n];
	int a, b;
	int f = array(Delp);

	int* sold = (int*)malloc(5 * sizeof(Delp));
	printf("Enter Number :");

	for (a = 0; a < n; a++)
		scanf_s("%d", &Delp[a]);
	printf("\n");

	printf("***  Duplicate values *** \n ");
	for(int i=0;i<n;i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Delp[i] == Delp[j])
			{
				printf("Number - [%d]\n", Delp[i]);
			}
		}
	}
	free(sold);
}
