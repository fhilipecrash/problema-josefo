#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no {
    int num;
    No *proximo;
    No *anterior;
};

struct lista {
    int tamanho;
    No *cabeca;
};

// Auxiliares.
void mostrar_soldados(Lista* lista);
void inserir_soldado(Lista* lista, int total_soldados);
void remover_soldado(Lista* lista, int num_soldado);
int josefo(Lista* lista, int pulo);

void main() {
    // Aloca memória pra lista e pro nó dentro dela e define os valores padrões.
    Lista* lista_soldados = (Lista *)malloc(sizeof(Lista));
    lista_soldados->cabeca = (No *)malloc(sizeof(No));

    lista_soldados->cabeca->anterior = lista_soldados;
    lista_soldados->cabeca->proximo = lista_soldados;
    lista_soldados->cabeca->num = 0;
    lista_soldados->tamanho = 0;
    
    inserir_soldado(lista_soldados, 10);

}

// Usa o tamanho da lista no for para percorrer todos os itens e mostrar os soldados.
void mostrar_soldados(Lista* lista) {
    No* item = lista->cabeca->proximo;
    int c;

    for (c = 0; c < lista->tamanho; c++) {
        printf("Soldado: %d\n", item->num);
        item = item->proximo;
    }
    printf("\n");
}

/*
Recebe o valor dos soldados que vão ser adicionados
criando um novo nó a cada repetição.
*/
void inserir_soldado(Lista* lista, int total_soldados) {
    int c;

    for (c = 1; c < total_soldados+1; c++) {
        No* soldado = (No *)malloc(sizeof(No));
        if (lista->tamanho == 0) {
            /*
            A primeira adição de um soldado é diferente por que 
            ele precisa apontar pro nó cabeça e o nó cabeça precisa apontar pra ele.
            */
            soldado->proximo = lista->cabeca;
            soldado->anterior = lista->cabeca;
            soldado->num = c;
            lista->cabeca->proximo = soldado;
            lista->cabeca->anterior = soldado;
            lista->tamanho++;
        } else {
            /* 
            Qualquer outro soldado é adicionado dessa forma apontando pro último soldado(soldado que o nó cabeça sempre aponta)
            e depois apontando pro nó cabeça, já que esse novo soldado se torna o último da lista.
            */
            soldado->proximo = lista->cabeca;
            soldado->anterior = lista->cabeca->anterior;
            soldado->num = c;
            lista->cabeca->anterior->proximo = soldado;
            lista->cabeca->anterior = soldado;
            lista->tamanho++;
        }
    }
}

void remover_soldado(Lista* lista, int num_soldado) {
    No* item = lista->cabeca->proximo;
    int c = 0;

    while (c < lista->tamanho) {
        if (num_soldado == item->num) {
            /* 
            O soldado anterior recebe o endereço do próximo soldado 
            e o próximo soldado recebe o endereço do soldado anterior,
            depois o soldado que não é mais apontado por nada é liberado da memória com free e a execução para.
            */
            item->anterior->proximo = item->proximo;
            item->proximo->anterior = item->anterior;
            lista->tamanho--;
            free(item);
            break;
        } else {
            item = item->proximo;
        }
        c++;
    }
}

// TODO terminar o problema do josefo
int josefo(Lista* lista, int pulo) {
    No* item = lista->cabeca->proximo;

    while (true) {
        item = item->proximo;
    }
}