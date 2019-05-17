#include "lista.h" 
#include "no.h" 

struct Lista
{
    int qtd_elem;
    No* no;
};

struct No{
    No* prox;
    No* anterior;
    int valor;
};

