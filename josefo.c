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
void josefo(Lista* lista, int pulo);

void main() {
    // Aloca memória pra lista e pro nó dentro dela e define os valores padrões.
    Lista* lista_soldados = (Lista *)malloc(sizeof(Lista));
    lista_soldados->cabeca = (No *)malloc(sizeof(No));

    lista_soldados->cabeca->anterior = lista_soldados->cabeca;
    lista_soldados->cabeca->proximo = lista_soldados->cabeca;
    lista_soldados->cabeca->num = 0;
    lista_soldados->tamanho = 0;
    
    int resp_soldados;
    int resp_pulos;

    printf("Insira o número de soldados: ");
    scanf("%d", &resp_soldados);
    printf("Insira o tamanho do pulo: ");
    scanf("%d", &resp_pulos);
    inserir_soldado(lista_soldados, resp_soldados);
    josefo(lista_soldados, resp_pulos);
}

// Usa o tamanho da lista no for para percorrer todos os itens e mostrar os soldados.
void mostrar_soldados(Lista* lista) {
    No* item = lista->cabeca->proximo;
    int c;

    printf("Soldados: ");
    for (c = 0; c < lista->tamanho; c++) {
        printf("%d ", item->num);
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
    mostrar_soldados(lista);
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
            printf("Soldado removido: %d\n", item->num);
            item->anterior->proximo = item->proximo;
            item->proximo->anterior = item->anterior;
            lista->tamanho--;
            free(item);
            mostrar_soldados(lista);
            break;
        } else {
            item = item->proximo;
        }
        c++;
    }
}

void josefo(Lista* lista, int pulo) {
    No* item = lista->cabeca->proximo;
    // Nó auxiliar pra guardar o ponteiro do próximo.
    No* aux;
    int c = 1;

    // While 1 (true) faz a lista circular ser lida infinitamente.
    while (1) {
        // Ignora o nó de index 0(nó cabeça) e faz apontar pro próximo item da lista.
        if (item->num != 0) {
            if (lista->tamanho == 1) {
                printf("O último soldado foi %d\n", item->num);
                // Quando restar apenas um elemeno na lista com exceção do nó cabeça o programa para.
                break;
            }

            /* 
            Só remove o soldado quando o valor de C for igual o do pulo, usa a variável auxiliar pra guardar o ponteiro do próximo
            depois remove e então a variável item recebe o valor guardado na variável auxiliar.
            */
            if (c == pulo) {
                aux = item->proximo;
                remover_soldado(lista, item->num);
                c = 1;
                item = aux;
            } else {
                item = item->proximo;
                c++;
            }
        } else {
            item = item->proximo;
        }
    }
}