#include <stdio.h>
#include <locale.h>
#define SIZE 5
void copy_arr(double trg[], double src[], int n);
void copy_ptr(double* trg2, double* src2, int m);
void copy_ptrs(double* trg3, double* src3, double* end);

int main(void) {
    int i, j;

    double source[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    printf("Source:  ");
    for (i = 0; i < SIZE; i++) {
        printf("%5.1f ", source[i]);
    }
    putchar('\n');

    copy_arr(target1, source, SIZE);

    copy_ptr(target2, source, SIZE);
    printf("Target2: ");
    for (j = 0; j < SIZE; j++) {
        printf("%5.1f ", target2[j]);
    }
    putchar('\n');

    copy_ptrs(target3, source, source + 5);

    return 0;
}

void copy_arr(double trg[], double src[], int n) {
    int i, j, k;
    for (i = 0, j = 0; i < n; i++, j++) {
        trg[i] = src[j];
    }
    printf("Target1: ");
    for (k = 0; k < SIZE; k++) {
        printf("%5.1f ", trg[k]);
    }
    putchar('\n');
}

void copy_ptr(double* trg2, double* src2, int m) {
    int i, j;
    for (i = 0, j = 0; i < m; i++, j++) {
        *(trg2 + i) = *(src2 + j);
    }
}
void copy_ptrs(double* trg3, double* src3, double* end) 

    {
	
	double month[3][5];
}	

