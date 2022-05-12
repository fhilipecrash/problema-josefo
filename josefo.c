#include <stdio.h>
#include <stdlib.h>

typedef struct soldado No;
typedef struct lista Lista;

struct soldado {
    int num;
    No *proximo;
    No *anterior;
};

struct lista {
    int tamanho;
    No *cabeca;
};

// Auxiliares
void inserir_soldado(Lista* lista, int num_soldado);

void main() {
    Lista* lista_soldados = (Lista *)malloc(sizeof(Lista));
    lista_soldados->cabeca = (No *)malloc(sizeof(No));

    lista_soldados->cabeca->anterior = lista_soldados;
    lista_soldados->cabeca->proximo = lista_soldados;
    lista_soldados->tamanho = 0;
    
    inserir_soldado(lista_soldados, 1);
    inserir_soldado(lista_soldados, 2);
    inserir_soldado(lista_soldados, 3);
    inserir_soldado(lista_soldados, 4);

    // printf("%d", lista_soldados->tamanho);

    int c;

    No* posicao = lista_soldados->cabeca->proximo;
    for(c = 0; c < 4; c++) {
        printf("Soldado: %d\n", &posicao->num);
        posicao = posicao->proximo;

    }
}

void inserir_soldado(Lista* lista, int num_soldado) {
    No* soldado = (No *)malloc(sizeof(No));
    
    if (lista->tamanho == 0) {
        soldado->proximo = lista;
        soldado->anterior = lista;
        soldado->num = num_soldado;
        lista->cabeca->proximo = soldado;
        lista->cabeca->anterior = soldado;
        lista->tamanho++;
    } else {
        soldado->proximo = lista;
        soldado->anterior = lista->cabeca->anterior;
        soldado->num = num_soldado;
        lista->tamanho++;
    }
}