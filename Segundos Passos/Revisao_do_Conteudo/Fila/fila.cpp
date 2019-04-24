#include "fila.h"
#include <iostream>
#define MAXIMO 5
using namespace std;

struct Fila
{
    No *ultimo;
    No *primeiro;
    int n_elem;
};

struct No
{
    int info;
    No *prox;
};

Fila *criar()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->n_elem = -1;
    f->ultimo = nullptr;
    f->primeiro = nullptr;
    return f;
}

void inserir(Fila *f, int valor)
{
    if (!cheia(f))
    {
        No *nf = (No *)malloc(sizeof(No));
        nf->info = valor;
        nf->prox = f->ultimo;
        f->ultimo = nf;
        if (f->n_elem == -1)
        {
            f->primeiro = nf;
        }
        f->n_elem++;
    }
    else
    {
        cout << "Não foi possível inserir";
    }
}

int remover(Fila *f) //TODO como que faz a remoção do primeiro nó(no caso aquele que foi adicionado a mais tempo)
{                    // de modo que os outros substituam o proximo?
    if (!vazia(f))
    {
        No *aux = f->ultimo;
        while (aux != f->primeiro)
        {
            aux = aux->prox;
        }

        f->primeiro;
    }
    else
    {
        cout << "Não foi possível remover";
    }
}

int vazia(Fila *f)
{
    if (f->n_elem == -1)
    {
        cout << "Está vazio";
        return 1;
    }
    else
    {
        cout << "Não está vazio";
        return 0;
    }
}

int cheia(Fila *f)
{
    if (f->n_elem == MAXIMO)
    {
        cout << "Está cheio";
        return 1;
    }
    else
    {
        cout << "não está cheio";
        return 0;
    }
}

void imprimir(Fila *f)
{
    cout << "O ultimo elemento é o " << f->ultimo << endl;
    cout << "O primeiro elemento é o " << f->primeiro << endl;
}