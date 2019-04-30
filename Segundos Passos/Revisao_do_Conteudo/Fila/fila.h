struct Fila
{
    No *ultimo;
    No *primeiro;
    int n_elem;
};

Fila* criar();

void inserir(Fila *f, int valor);

int remover(Fila *f);

int vazia(Fila *f);

int cheia(Fila *f);

void imprimir(Fila *f);