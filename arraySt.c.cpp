#include <locale.h>
#include <conio.h>
#include <stdio.h>
#define SIZE 10
#define LOUS 10
void sel(double send[LOUS], double olen[LOUS],double *p[LOUS]);

int main() {
    setlocale(LC_ALL, "Russian");
    double unit[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 7.0, 9.0, 0.0 };
    double* p[SIZE];
    double* num;
    char flag = 1;
    unsigned i;

    printf("Несортированный массив\n");
    for (i = 0; i < SIZE; i++) {
        printf("%.2f ", unit[i]);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        p[i] = &unit[i];
    }
    do {
        flag = 0;
        for (i = 1; i < SIZE; i++) {
            if (*p[i] < *p[i - 1]) {
                num = p[i];
                p[i] = p[i - 1];
                p[i - 1] = num;
            }
        }
    } while (flag);
    printf("Отсортированный массив\n");
    for (i = 0; i < SIZE; i++) {

        printf("%.2f", *p[i]);
    }
    printf("\n");
    printf("сортированный массив не был изменен\n");
    for (i = 0; i < SIZE; i++)
        printf("%.2f", unit[i]);
    sel(unit,&unit[SIZE],p);
}
void sel(double send[LOUS], double olen[SIZE],double *p[LOUS])
{
    unsigned ios;
    char flan = 1;
    double open[LOUS] = { 2.1,3.1,4.1,5.1,6.1,9.1,0.0,4.1,3.3,1.2 };
    double* secold[LOUS];
    double* longw;
    for (ios = 0; ios < LOUS; ios++) {
        printf("\n");
        printf("Сортировка 2:%.2f\n", open[ios]);
    }
    for (ios = 0; ios < LOUS; ios++) {
        secold[ios] = &open[ios];
    }
    do {
        flan = 0;
        for (ios = 1; ios <LOUS; ios++) {
            if (*secold[ios] < *secold[ios - 1]) {
                longw = secold[ios];
                secold[ios] = secold[ios-1];
                secold[ios - 1] = longw;
           
                flan = 1;

            }
        }
    } while (flan);
    printf("Сортированный массив 2");
    for (ios = 0; ios < LOUS ; ios++) {
        printf("%.2f", *secold[ios]);
    }
}
    



