#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
    int valor;
    No *proximo;
    No *anterior;
};

struct lista {
    int tamanho;
    No *cabeca;
};

void imprimir_lista(Lista* lista) {
    No* item = lista->cabeca->proximo;

    printf("Soldados: ");
    for (int c = 0; c < lista->tamanho; c++) {
        printf("%d ", item->valor);
        item = item->proximo;
    }
    printf("\n");
}

void inserir_item(Lista* lista, int valor) {
    No* item = (No *)malloc(sizeof(No));
    item->valor = valor;
    item->proximo = lista->cabeca;
    item->anterior = lista->cabeca->anterior;
    lista->cabeca->anterior->proximo = item;
    lista->cabeca->anterior = item;
    lista->tamanho++;
}

void remover_item(Lista* lista, int valor) {
    No* item = lista->cabeca->proximo;

    for (int c = 0; c < lista->tamanho; c++) {
        if (item->valor == valor) {
            item->anterior->proximo = item->proximo;
            item->proximo->anterior = item->anterior;
            lista->tamanho--;
            free(item);
            break;
        }
        item = item->proximo;
    }
}


void iniciar_lista(Lista* lista) {
    lista->tamanho = 0;
    lista->cabeca = (No *)malloc(sizeof(No));
    lista->cabeca->valor = 0;
    lista->cabeca->proximo = lista->cabeca;
    lista->cabeca->anterior = lista->cabeca;
}

int main() {
    Lista* lista = (Lista *)malloc(sizeof(Lista));
    iniciar_lista(lista);
    return 0;
}