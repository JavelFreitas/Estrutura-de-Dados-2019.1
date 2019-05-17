#pragma once
#define N 5

struct Amigo{
    char nome[20];
    int idade;
    char endereco[20];
};

struct Lista
{
    Amigo v[N];
    int qtd_elem;
};

Lista* criar();

int vazia(Lista* l);

int cheia(Lista* l);

void inserir(Lista *l, Amigo* pessoa, int pos);

void imprimir(Lista *l, int pos);

Amigo* remover(Lista *l, int pos);

void liberar(Lista *l);