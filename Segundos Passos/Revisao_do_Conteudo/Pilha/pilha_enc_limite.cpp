#include <iostream> //TODO tenta fazer o Pilha e o No aqui e tira eles do header; 
#include "pilha.h"
#define MAXIMO 5


Pilha *criar()
{
    Pilha *nova = (Pilha *)malloc(sizeof(Pilha));
    nova->topo = nullptr;
    nova->q_elem = 0;
    return nova;
}

void inserir(Pilha *p, int valor)
{
    if (!cheia(p))
    {
        No *np = (No *)malloc(sizeof(No));
        np->prox = p->topo;
        p->topo = np;
        np->valor = valor;
        p->q_elem++;
    }
    else
    {
        std::cout << "Pilha está cheia";
    }
}

int remover(Pilha *p)
{
    if (vazia(p))
    {
        exit(1);
    }
    No *aux;
    aux = p->topo;
    int num = aux->valor;
    p->topo = p->topo->prox;
    free(aux);
    return num;
}

int vazia(Pilha *p) 
{
    if (p->topo == nullptr)
        return 1;
    return 0;
}

int cheia(Pilha *p) 
{
    if(p->q_elem == MAXIMO)
    {
        return 1;
    }
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
        std::cout << p->topo << " é o valor no topo" << std::endl;
    }
}

void liberar(Pilha *p) 
{
    free(p);
}
