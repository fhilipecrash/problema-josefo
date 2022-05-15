/*
João Luiz Mineiro Alves
Fernando Soares de Araújo Filho
José Fhilipe Martins Coelho
*/

#include "functions.h"

int main() {
    // Aloca memória pra lista e pro nó dentro dela e define os valores padrões.
    Lista* lista_soldados = (Lista *)malloc(sizeof(Lista));
    lista_soldados->cabeca = (No *)malloc(sizeof(No));

    lista_soldados->cabeca->anterior = lista_soldados->cabeca;
    lista_soldados->cabeca->proximo = lista_soldados->cabeca;
    lista_soldados->cabeca->num = 0;
    lista_soldados->tamanho = 0;

    inserir_soldados(lista_soldados);
    josefo(lista_soldados, inserir_pulo(lista_soldados));

    return 0;
}
