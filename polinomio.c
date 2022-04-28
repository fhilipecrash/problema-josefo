#include <stdio.h>
#include <stdlib.h>

#ifndef POLINOMIO_H
#define POLINOMIO_H

typedef struct {
    int num1;
    int num2;
} POLINOMIO;

POLINOMIO *criar(int item1, int item2);
void somar(POLINOMIO *item1, POLINOMIO *item2);
void avaliar(POLINOMIO *item);

#endif

int main() {
    POLINOMIO poli1 = *criar(2, 4);
    printf("Num1: %d\nNum2: %d", poli1.num1, poli1.num2);
}

POLINOMIO *criar(int item1, int item2) {
    POLINOMIO *poli = (POLINOMIO *) malloc(sizeof(POLINOMIO));
    poli->num1 = item1;
    poli->num2 = item2;
    return poli;
}

