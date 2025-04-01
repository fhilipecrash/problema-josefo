/*
João Luiz Mineiro Alves
Fernando Soares de Araújo Filho
José Fhilipe Martins Coelho
*/

// Inclui o cabeçalho com as funções necessárias
#include "functions.h"

int main() {
    // Aloca memória para a estrutura da lista de soldados
    Lista* lista_soldados = (Lista *)malloc(sizeof(Lista));
    // Aloca memória para o nó cabeça da lista
    lista_soldados->cabeca = (No *)malloc(sizeof(No));

    // Configura a lista circular: ambos os ponteiros apontam para o próprio cabeça
    lista_soldados->cabeca->anterior = lista_soldados->cabeca;
    lista_soldados->cabeca->proximo = lista_soldados->cabeca;
    // Define o número do nó cabeça como 0 (não é um soldado)
    lista_soldados->cabeca->num = 0;
    // Inicializa o tamanho da lista como 0
    lista_soldados->tamanho = 0;

    // Chama função para inserir soldados na lista
    inserir_soldados(lista_soldados);
    // Executa o problema de Josephus com o pulo fornecido pelo usuário
    josefo(lista_soldados, inserir_pulo(lista_soldados));

    return 0;
}
