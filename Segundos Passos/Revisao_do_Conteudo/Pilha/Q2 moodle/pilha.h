#define N 20

typedef struct Pilha{
   char s[N];
   int topo;
}Pilha;

Pilha* criar();

void inserir(Pilha *p, char valor);

char remover(Pilha *p);

int vazia(Pilha *p);

int cheia(Pilha *p);

void imprimir(Pilha *p);

void liberar(Pilha *p);
