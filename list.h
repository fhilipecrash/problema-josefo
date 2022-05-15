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
