#include <stdio.h>
#include <stdlib.h>

#ifndef POLINOMIO_H
#define POLINOMIO_H

typedef struct {
    int num1;
    int num2;
} POLINOMIO;

// O asterisco indica que a função retorna um ponteiro do tipo polinomio
POLINOMIO* criar(int item1, int item2);
void somar(POLINOMIO *item1, POLINOMIO *item2);
void avaliar(POLINOMIO *item);

#endif

int main() {
    // TODO testar a diferença do *poliX = criar e poliX = *criar
    POLINOMIO *poli1 = criar(2, 4);
    POLINOMIO *poli2 = criar(3, 5);

    // aparentemente o endereço de (void *)poliX é o mesmo de poliX->num1
    printf("Struct adress: %p, Num1 adress: %p, Num2 adress: %p\n", (void *)poli1, (int *)&poli1->num1, (int *)&poli1->num2);
    printf("Num1: %d, Num2: %d\n", poli1->num1, poli1->num2);
    printf("Struct adress: %p, Num1 adress: %p, Num2 adress: %p\n", (void *)poli2, (int *)&poli2->num1, (int *)&poli2->num2);
    printf("Num1: %d, Num2: %d\n", poli2->num1, poli2->num2);

    somar(poli1, poli2);

    free((void *)poli1); // (void *) especifica o formato do endereço do ponteiro
    free((void *)poli2);
};

POLINOMIO* criar(int item1, int item2) {
    POLINOMIO *poli = (POLINOMIO *) malloc(sizeof(POLINOMIO));

    poli->num1 = item1;
    poli->num2 = item2;

    return poli;
}

// TODO terminar a função somar
void somar(POLINOMIO *item1, POLINOMIO *item2) {
    int sum1, sum2;

    sum1 = item1->num1 + item2->num1;
    sum2 = item1->num2 + item2->num2;

    printf("Sum num1 = %d, Sum num2 = %d\n", sum1, sum2);
}

