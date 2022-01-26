#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <locale.h>
double  number();
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
int  lorsen=number();
 
    printf("Введите два числа:");
    scanf_s("%d %d", &a, &b);
    printf("1) Умножение      2)Деление ");
    printf("\n");
    printf("3)Сложение      4)Вычитание ");
    printf("\n");
    printf("5)Деление на остаток");
    printf("\n");
    scanf_s("%d", &lorsen);
  
    switch (lorsen)
    {
    case 1: printf("Сумма %d is %d and %d\n", a, b, a * b);
        break;
    case 2:printf("Сумма %d is %d and %d\n", a, b, a / b);
        break;
    case 3: printf("Сумма %d is %d and %d\n", a, b, a + b);
        break;
    case 4:printf("Сумма %d is %d and %d\n", a, b, a - b);
        break;
    case 5: printf("Сумма %d is %d and %d",a,b, a % b);
        break;
    default:
        printf("Ошибка #1");
    }
    printf("\n");
   
    return 0;
}
double   number()
{

    float    a, b;
   int lorsen;
    printf("Введите два числа:");
    scanf_s("%f %f", &a, &b);
    printf("1) Умножение      2)Деление ");
    printf("\n");
    printf(" 3)Сложение      4)Вычитание ");
    printf("\n");
    scanf_s("%d", &lorsen);

    switch (lorsen)
    {
    case 1 : printf("Сумма %.2f is  is %.2f and %.2f\n", a, b, a * b);
        break;
    case 2:printf("Сумма %.2f is s %.2f and %.2f\n", a, b, a / b);
        break;
    case 3: printf("Сумма %.2f is   is %.2f and %.2f\n", a, b, a + b);
        break;
    case 4:printf("Сумма %.2f and  is %.2f  %.2f\n", a, b, a - b);
        break;
    default:
        printf("Ошибка #2");
    }
    printf("\n");
    return lorsen;
}

  
 


