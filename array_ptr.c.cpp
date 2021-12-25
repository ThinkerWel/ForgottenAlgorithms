#include <stdio.h>
#include <locale.h>
#define MLES 3
#define POUS 3
void lukes(int mein[], int jon[]);
void look(int mek[][3], int loues[]);
int main(void) {
    setlocale(LC_ALL, "Russian");
    printf("\nProgram\n");
    int mas[3][3] = { { 2,2 }, { 3,1 },{31,81} };
    printf(" For the hours passed :%d\n ", mas[1][0]);
    int  num[3][3] = { {21,31,56},{51,23,78},{99,86,53 } };
    num[2][2] += mas[0][0];
   
    printf("For the seconds passed:%d\n", num[2][2]);
    num[2][1] += num[2][1];
    printf(" total time:%d\n", num[2][1]);
   
    lukes(mas[1], mas[2]);
    look(num,num[2]);
}
void lukes(int mein[], int jon[])
{
    int lour;
    int  peekc=1 ;
    for (lour = 0; lour < MLES; lour)
        lour += mein[1];     
            peekc += jon[2];
        printf("\n%d  and %d\n", lour, peekc);
        printf("%p is %p\n", &lour, &peekc);
   
}
void look(int mek[][3], int loues[])
{
   int peend = 1;
    int p;
    
    for (p = 0; p < POUS; p++)
    {
        int c;
        for (c = 0; c < MLES; c++)

            peend +=mek [0][0];
        
        printf("\nprems:%d summma=%d \n", p, peend);

    }
}
