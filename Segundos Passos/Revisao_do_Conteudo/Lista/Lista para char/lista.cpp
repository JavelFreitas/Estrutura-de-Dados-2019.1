#include "lista.h"
#include <iostream>

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

void inserir(Lista *l, Amigo* pessoa, int pos)
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
        l->v[pos] = *pessoa;
        l->qtd_elem += 1;
    }
}
    //strcpy(destino, origem);
void imprimir(Lista *l, int pos)
{
    if (!vazia(l) && pos >= 0 && pos < l->qtd_elem)
    {
        std::cout << "O elemento nesta posição é o " << l->v[pos].nome << std::endl;
    }
}
Amigo* remover(Lista *l, int pos)
{
    int i = 0;
    Amigo *valor = nullptr;
    if ((pos < 0 || pos > l->qtd_elem + 1) || (vazia(l)))
    {
        std::cout << "Erro na remoção\n";
        exit(1);
    }
    else
    {
        valor = &l->v[pos];
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