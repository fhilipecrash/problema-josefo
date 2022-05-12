#include <stdio.h>
#include <stdlib.h>

#ifndef Polinomio_H
#define Polinomio_H

typedef struct {
    int coeff;
    int exp;
} Polinomio;

// TODO criar array da struct
// O asterisco indica que a função retorna um ponteiro do tipo Polinomio
Polinomio* criar(int item1, int item2);
void somar(Polinomio *item1, Polinomio *item2);
void avaliar(Polinomio *item);

#endif

void main() {
    // TODO testar a diferença do *poliX = criar e poliX = *criar
    Polinomio *poli1 = criar(2, 4);
    Polinomio *poli2 = criar(3, 5);

    // aparentemente o endereço de (void *)poliX é o mesmo de poliX.coeff
    printf("Struct adress: %p, coeff adress: %p, exp adress: %p\n", (void *)poli1, (int *)&poli1[1].coeff, (int *)&poli1[1].exp);
    printf("coeff: %d, exp: %d\n", poli1[1].coeff, poli1[1].exp);
    printf("Struct adress: %p, coeff adress: %p, exp adress: %p\n", (void *)poli2, (int *)&poli2[1].coeff, (int *)&poli2[1].exp);
    printf("coeff: %d, exp: %d\n", poli2[1].coeff, poli2[1].exp);

    somar(poli1, poli2);

    free((void *)poli1); // (void *) especifica o formato do endereço do ponteiro
    free((void *)poli2);
};

Polinomio* criar(int item1, int item2) {
    Polinomio *poli = (Polinomio *) malloc(sizeof(Polinomio)*10);
    int termos, i;

    for(i = 0; i < termos; i++) {
        poli[i].coeff = item1;
        poli[i].exp = item2;
    }

    return poli;
}

// TODO terminar a função somar
void somar(Polinomio *item1, Polinomio *item2) {
    int sum1, sum2;

    sum1 = item1.coeff + item2.coeff;
    sum2 = item1.exp + item2.exp;

    printf("Sum coeff = %d, Sum exp = %d\n", sum1, sum2);
}

