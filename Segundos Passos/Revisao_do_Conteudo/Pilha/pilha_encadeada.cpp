#include <iostream>
struct Pilha
{
    No *topo;
};

struct No{
    int valor;
    No *prox;
};

Pilha *criar()
{
    Pilha *nova = (Pilha *)malloc(sizeof(Pilha));
    nova->topo = nullptr;
    return nova;
}

void inserir(Pilha *p, int valor)
{
    No *np = (No *)malloc(sizeof(No));
    np->valor = valor;
    np->prox = p->topo;
}

int remover(Pilha *p)
{
    if (vazia(p))
        return 0;
    p->topo = p->topo->prox;
    return 1;
}

int vazia(Pilha *p)
{
    // if (p == nullptr)
    //     return 1;
    // return 0;
}

int cheia(Pilha *p)
{
    // return 0;
}

void imprimir(Pilha *p)
{
    // if (vazia(p))
    // {
    //     std::cout << "Está vazia" << std::endl;
    // }
    // else
    // {
    //     std::cout << p->valor << " é o valor no topo" << std::endl;
    // }
}

void liberar(Pilha *p)
{
    // free(p);
}
