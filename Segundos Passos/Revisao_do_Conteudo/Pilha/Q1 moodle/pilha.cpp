#include <iostream>
#include "pilha.h"
#define N 20
struct Pilha
{
    int v[N];
    int topo;
};

Pilha *criar()
{
    Pilha *nova = (Pilha *)malloc(sizeof(Pilha));
    nova->topo = -1;
    return nova;
}

void inserir(Pilha *p, int valor)
{
    if (cheia(p))
    {
        std::cout << "Está cheio" << std::endl;
        return;
    }
    p->topo += 1;
    p->v[p->topo] = valor;
}

int remover(Pilha *p)
{
    if (vazia(p))
        return 0;
    int valor;

    valor = p->v[p->topo];
    p->topo = p->topo - 1;
    return valor;
}

int vazia(Pilha *p)
{
    if (p->topo == -1)
        return 1;
    return 0;
}

int cheia(Pilha *p)
{
    if (p->topo == N - 1)
        return 1;
    return 0;
}

void imprimir(Pilha *p)
{
    if (vazia(p))
    {
        std::cout << "Está vazia" << std::endl;
    }
    else
    {
        std::cout << p->v[p->topo] << " é o valor no topo" << std::endl;
    }
}

void liberar(Pilha *p)
{
    free(p);
}
