struct Lista;

Lista* criar();

int vazia(Lista* l);

int cheia(Lista* l);

void inserir(Lista *l, int valor, int pos);

void imprimir(Lista *l, int pos);

int remover(Lista *l, int pos);

void liberar(Lista *l);