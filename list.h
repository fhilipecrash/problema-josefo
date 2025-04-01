// Declaração antecipada das estruturas para evitar dependência circular
typedef struct no No;
typedef struct lista Lista;

// Estrutura que representa um nó da lista duplamente encadeada
struct no {
    int num;            // Número do soldado
    No *proximo;        // Ponteiro para o próximo nó
    No *anterior;       // Ponteiro para o nó anterior
};

// Estrutura que representa a lista encadeada
struct lista {
    int tamanho;        // Quantidade de soldados na lista
    No *cabeca;         // Ponteiro para o nó cabeça (sentinel)
};
