#pragma once
#include "lista.h"

Lista * criarPilha();

void inserirPilha(Lista *pilha, int valor);

int removerPilha(Lista *pilha);

int cheiaPilha(Lista *p);

int vaziaPilha(Lista *p);

void liberarPilha(Lista *p);

void imprimirPilha(Lista *p);
