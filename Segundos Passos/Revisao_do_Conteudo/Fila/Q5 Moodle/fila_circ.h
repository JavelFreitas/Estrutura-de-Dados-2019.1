#define N 10

typedef struct fila{
   int v[N];
   int qtd_elem;
   int ini, fim;
}Fila;

Fila *criar();

void inserir(Fila *f, int valor);

int remover(Fila *f);

int vazia(Fila *f);

int cheia(Fila *f);

void imprimir(Fila *f);

void liberar(Fila *f);
