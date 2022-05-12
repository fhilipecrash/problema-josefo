#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coeff;
    int exp;
} Polinomio;

// Inicializa arrays do tipo polinomio
Polinomio primeiro[10], segundo[10], resultadoado[10];

int criar_polinomio(Polinomio poli[]) {
    int termos, i;
    
    printf("\nNúmero de termos: ");
    scanf("%d", &termos);

    printf("\nDigite os expoentes em ordem decrescente!")
    for(i = 0; i < termos; i++) {
        printf("\nCoeficiente: ");
        scanf("%d", &poli[i].coeff);
        printf("\nExpoente: ");
        scanf("%d", &poli[i].exp);
    }
    
    return termos;
}

int somar_polinomios(int tamanho_primeiro, int tamanho_segundo) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while(i < tamanho_primeiro && j < tamanho_segundo) {
        if(primeiro[i].exp == segundo[j].exp) {
            resultado[k].coeff = primeiro[i].coeff + segundo[j].coeff;
            resultado[k].exp = primeiro[i].exp;
            i++;
            j++;
            k++;
        }
        else if(primeiro[i].exp > segundo[j].exp) {
            resultado[k].coeff = primeiro[i].coeff;
            resultado[k].exp = primeiro[i].exp;
            i++;
            k++;
        }
        else {
            resultado[k].coeff = segundo[i].coeff;
            resultado[k].exp = segundo[j].exp;
            j++;
            k++;
        }
    }

    while(i < tamanho_primeiro) {
        resultado[k].coeff = primeiro[i].coeff;
        resultado[k].exp = primeiro[i].exp;
        k++;
        i++;
    }

    while(j < tamanho_segundo) {
        resultado[k].coeff = segundo[j].coeff;
        resultado[k].exp = segundo[j].exp;
        k++;
        j++;
    }
    return k;
} */

void mostrar_polinomio(int cont, Polinomio poli[]) {
    int i;
    for(i = 0; i < cont; i++) {
        if (i != 0) {
            printf("+");
        }
        printf("%dx^%d", poli[i].coeff, poli[i].exp);
    }
}

void main() {
    int tamanho_primeiro, tamanho_segundo, tamanho_resultado;

    printf("\nPrimeiro polinomio: ");
    tamanho_primeiro = criar_polinomio(primeiro);
    printf("\nSegundo polinomio: ");
    tamanho_segundo = criar_polinomio(segundo);
    mostrar_polinomio(tamanho_primeiro, primeiro);
}