#define N 5
#include "lista.h"
#include <iostream>

struct Lista
{
    int v[N];
    int qtd_elem;
};

Lista *criar()
{
    Lista *nl = (Lista *)malloc(sizeof(Lista));
    nl->qtd_elem = 0;
    return nl;
}

int vazia(Lista *l)
{
    if (l->qtd_elem == 0)
    {
        std::cout << "Esta vazia";
        return 1;
    }
    else
    {
        std::cout << "Nao esta vazia";
        return 0;
    }
}

int cheia(Lista *l)
{
    if (l->qtd_elem == N)
    {
        std::cout << "Esta cheia";
        return 1;
    }
    else
    {
        std::cout << "Nao esta cheia";
        return 0;
    }
}

void inserir(Lista *l, int valor, int pos)
{
    int i = 0;
    if ((pos <= 0 || pos > l->qtd_elem + 1) || (cheia(l)))
    {
        std::cout << "Erro na inserção\n";
        exit(1);
    }
    else
    {
        i = l->qtd_elem;
        while (i > pos)
        {
            l->v[i] = l->v[i - 1];
            i--;
        }
        l->v[pos] = valor;
        l->qtd_elem += 1;
    }
}

void imprimir(Lista *l, int pos)
{
    if (!vazia(l) && pos >= 0 && pos < l->qtd_elem)
    {
        std::cout << "O elemento nesta posição é o " << l->v[pos] << std::endl;
    }
}
int remover(Lista *l, int pos)
{
    int i = 0;
    int valor = 0;
    if ((pos < 0 || pos > l->qtd_elem + 1) || (vazia(l)))
    {
        std::cout << "Erro na remoção\n";
        return 1;
    }
    else
    {
        valor = l->v[pos];
        for (i = pos + 1; i < l->qtd_elem; i++)
        {
            l->v[i - 1] = l->v[i];
        }
    }
    l->qtd_elem -= 1;
    return valor;
}

void liberar(Lista *l)
{
    free(l);
}