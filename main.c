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

void josefo(Lista* lista, int pulo) {
    No* item = lista->cabeca->proximo;
    int c = 1;

    while (1) {
        if (item->valor != 0) {  // Ignora o nó cabeça
            if (lista->tamanho == 1) {  // Último soldado restante
                printf("O último soldado foi %d\n", item->valor);
                break;
            }

            if (c == pulo) {  // Encontrou o soldado a ser removido
                No* aux = item->proximo;
                remover_item(lista, item->valor);
                c = 1;  // Reinicia a contagem
                item = aux;
                break;
            } else {
                item = item->proximo;  // Continua navegação
                c++;
            }
        } else {
            item = item->proximo;  // Pula o nó cabeça            
        }  
    }
}

int main() {
    Lista* lista = (Lista *)malloc(sizeof(Lista));
    iniciar_lista(lista);

    printf("Quantos soldados deseja inserir? ");
    int max_soldados;
    scanf("%d", &max_soldados);
    for (int c = 1; c <= max_soldados; c++) {
        // printf("Digite o número do soldado: ");
        // int num_soldado;
        // scanf("%d", &num_soldado);
        inserir_item(lista, c);
    }
    imprimir_lista(lista);

    while (1) {
        if (lista->tamanho == 1) {
            printf("Só restou um soldado\n");
            break;
        }

        printf("Qual o tamanho do pulo? ");
        int pulo;
        scanf("%d", &pulo);
        josefo(lista, pulo);
        imprimir_lista(lista);
    }
    
    return 0;
}
