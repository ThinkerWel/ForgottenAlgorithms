#include <stdio.h>
#include <locale.h>
#define SIZE 10
int  main() {

    setlocale(LC_ALL, "Russian");
    double unit[SIZE] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,0.0 };
    double* pel[SIZE];
    double* num;
    char flag = 1;
    unsigned i;
    for (i = 1; i < SIZE; i++) {
        printf("%.2f", unit[i]);
    }
    for (i = 0; i < SIZE; i++) {
        pel[i] = &unit[i];
    }
    do
    {
        flag = 0;
        for (i = 1; i < SIZE; i++) {
            if (*pel[i] < *pel[i - 1]) {
                num = pel[i];
                pel[i] = pel[i - 1];
                pel[i - 1] = num;
                flag = 1;
            }
        }
    } while (flag);



    printf("\nсортировка массива\n");
    for (i = 0; i < SIZE; i++) {
        printf("%.2f", *pel[i]);
    }
    printf("\n");
    printf("НЕСОРТИРОВАННЫЙ МАССИВ НЕ БЫЛ ИЗМЕНЕН\n");
    for (i = 0; i < SIZE; i++) {
        printf("%.2f", unit[i]);
    }
}