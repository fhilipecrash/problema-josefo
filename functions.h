#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Protótipos das funções
void inserir_soldados(Lista* lista);
int inserir_pulo();
void mostrar_soldados(Lista* lista);
void popular_lista(Lista* lista, int total_soldados);
void remover_soldado(Lista* lista, int num_soldado);
void josefo(Lista* lista, int pulo);

// Função para exibir todos os soldados na lista
void mostrar_soldados(Lista* lista) {
    No* item = lista->cabeca->proximo;  // Começa no primeiro soldado após o cabeça
    int c;

    printf("Soldados: ");
    // Percorre todos os soldados usando o tamanho da lista
    for (c = 0; c < lista->tamanho; c++) {
        printf("%d ", item->num);      // Imprime o número do soldado
        item = item->proximo;          // Avança para o próximo soldado
    }
    printf("\n");
}

// Função para ler a quantidade de soldados do usuário
void inserir_soldados(Lista* lista) {
    int resp_soldados, teste, ch;
    
    printf("Insira o número de soldados(inserir 0 sai do programa): ");
    teste = scanf("%d", &resp_soldados);
    printf("\n");
    // Loop para validar entrada do usuário
    while (teste == 0) {
        fprintf(stderr, "Valor inválido. Insira um número inteiro!\n");
        printf("Insira o número de soldados(inserir 0 sai do programa): ");
        // Limpa o buffer de entrada
        do {
            ch = getchar();
        } while ((ch != EOF) && (ch != '\n'));
        teste = scanf("%d", &resp_soldados);
        printf("\n");
    }
    if (resp_soldados != 0) {
        popular_lista(lista, resp_soldados);  // Preenche a lista com soldados
    } else {
        printf("Tchau!\n");
    }
}

// Função para ler o tamanho do pulo do usuário
int inserir_pulo() {
    int resp_pulos, teste, ch;

    while (1) {   
        printf("Insira o tamanho do pulo(exceto 0): ");
        teste = scanf("%d", &resp_pulos);
        // Valida a entrada do usuário
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
            return resp_pulos;  // Retorna o pulo válido
        }
    }
}

// Função para preencher a lista com soldados
void popular_lista(Lista* lista, int total_soldados) {
    int c;

    for (c = 1; c < total_soldados+1; c++) {
        No* soldado = (No *)malloc(sizeof(No));
        if (lista->tamanho == 0) {
            // Primeiro soldado: conecta o cabeça ao novo nó
            soldado->proximo = lista->cabeca;
            soldado->anterior = lista->cabeca;
            soldado->num = c;
            lista->cabeca->proximo = soldado;
            lista->cabeca->anterior = soldado;
            lista->tamanho++;
        } else {
            // Soldados subsequentes: insere no final da lista
            soldado->proximo = lista->cabeca;
            soldado->anterior = lista->cabeca->anterior;
            soldado->num = c;
            lista->cabeca->anterior->proximo = soldado;
            lista->cabeca->anterior = soldado;
            lista->tamanho++;
        }
    }
    mostrar_soldados(lista);  // Exibe a lista após criação
}

// Função para remover um soldado específico da lista
void remover_soldado(Lista* lista, int num_soldado) {
    No* item = lista->cabeca->proximo;  // Começa no primeiro soldado
    int c = 0;

    // Procura o soldado a ser removido
    while (c < lista->tamanho) {
        if (num_soldado == item->num) {
            // Ajusta os ponteiros para pular o nó removido
            item->anterior->proximo = item->proximo;
            item->proximo->anterior = item->anterior;
            lista->tamanho--;
            free(item);  // Libera a memória do nó
            mostrar_soldados(lista);
            break;
        } else {
            item = item->proximo;  // Continua a busca
        }
        c++;
    }
}

// Função principal que resolve o problema de Josephus
void josefo(Lista* lista, int pulo) {
    No* aux;  // Ponteiro auxiliar para navegação

    if (pulo > 0) {  // Pulo positivo: navegação para frente
        No* item = lista->cabeca->proximo;
        int c = 1;

        while (1) {
            if (item->num != 0) {  // Ignora o nó cabeça
                if (lista->tamanho == 1) {  // Último soldado restante
                    printf("O último soldado foi %d\n", item->num);
                    break;
                }

                if (c == pulo) {  // Encontrou o soldado a ser removido
                    aux = item->proximo;
                    remover_soldado(lista, item->num);
                    c = 1;  // Reinicia a contagem
                    item = aux;
                    pulo = inserir_pulo();  // Solicita novo pulo
                } else {
                    item = item->proximo;  // Continua navegação
                    c++;
                }
            } else {
                item = item->proximo;  // Pula o nó cabeça
            }
        }
    } else {  // Pulo negativo: navegação para trás
        No* item = lista->cabeca->anterior;
        int c = -1;

        while (1) {
            if (item->num != 0) {  // Ignora o nó cabeça
                if (lista->tamanho == 1) {  // Último soldado restante
                    printf("O último soldado foi %d\n", item->num);
                    break;
                }

                if (c == pulo) {  // Encontrou o soldado a ser removido
                    aux = item->anterior;
                    remover_soldado(lista, item->num);
                    c = -1;  // Reinicia a contagem
                    item = aux;
                    pulo = inserir_pulo();  // Solicita novo pulo
                } else {
                    item = item->anterior;  // Continua navegação
                    c--;
                }
            } else {
                item = item->anterior;  // Pula o nó cabeça
            }
        }
    }
}
