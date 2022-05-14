/*
João Luiz Mineiro Alves
Fernando Soares de Araújo Filho
José Fhilipe Martins Coelho
*/

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
void inserir_soldados(Lista* lista);
void inserir_pulo(Lista* lista);
void mostrar_soldados(Lista* lista);
void popular_lista(Lista* lista, int total_soldados);
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

    inserir_soldados(lista_soldados);
    inserir_pulo(lista_soldados);
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

// TODO verificar se o valor digitado é inteiro(excluindo char, \n ou EOF).
void inserir_soldados(Lista* lista) {
    int resp_soldados, teste, ch;
    
    printf("Insira o número de soldados(inserir 0 sai do programa): ");
    teste = scanf("%d", &resp_soldados);
    printf("\n");
    while (teste == 0) {
        // TODO Entender o que é fprint
        // Faz a validação do valor digitado pelo usuário
        fprintf(stderr, "Valor inválido. Insira um número inteiro!\n");
        printf("Insira o número de soldados(inserir 0 sai do programa): ");
        do {
            ch = getchar();
        } while ((ch != EOF) && (ch != '\n'));
        teste = scanf("%d", &resp_soldados);
        printf("\n");
    }
    if (resp_soldados != 0) {
        popular_lista(lista, resp_soldados);
    } else {
        printf("Tchau!\n");
    }
}

void inserir_pulo(Lista* lista) {
    int resp_pulos, teste, ch;

    while (1) {   
        printf("Insira o tamanho do pulo(exceto 0): ");
        teste = scanf("%d", &resp_pulos);
        while (teste == 0) {
            fprintf(stderr, "Valor inválido. Insira um número inteiro!\n");
            printf("Insira o tamanho do pulo(exceto 0): ");
            do {
                ch = getchar();
            } while ((ch != EOF) && (ch != '\n'));
            teste = scanf("%d", &resp_pulos);
        }
        if (resp_pulos == 0) {
            printf("Não se pode ter um pulo de 0\n");
        } else {
            josefo(lista, resp_pulos);
            break;
        }
    }
}

/*
Recebe o valor dos soldados que vão ser adicionados
criando um novo nó a cada repetição.
*/
void popular_lista(Lista* lista, int total_soldados) {
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
    /* O ponteiro auxiliar serve pra guardar a referência da lista
    pois a remoção do elemento faz a função perder a referência da lista.
    */ 
    No* aux;
    if (pulo > 0) {
        No* item = lista->cabeca->proximo;
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
    } else {
        No* item = lista->cabeca->anterior;
        int c = -1;

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
                    aux = item->anterior;
                    remover_soldado(lista, item->num);
                    c = -1;
                    item = aux;
                } else {
                    item = item->anterior;
                    c--;
                }
            } else {
                item = item->anterior;
            }
        }
    }
}