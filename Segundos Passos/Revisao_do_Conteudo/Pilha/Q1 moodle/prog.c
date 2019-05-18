#include <stdio.h>
#include "pilha.h"

Pilha *inserirNaPilha(int number)
{
    Pilha *nova = criar();
    while (number >= 1)
    {
        inserir(nova, number % 10);
        number = number / 10;
    }
    return nova;
}

Pilha *reverterPraPilha(Pilha *nova)
{
    Pilha *reversa = criar();
    
    int aux = 0;
    int verificar = 0;
    int contagem = 0;

    while(!vazia(nova))
    {
        verificar *= 10;
        aux = nova->v[nova->topo];
        inserir(reversa, aux);
        imprimir(reversa);
        printf("  Topo : %d\n", contagem);
        verificar += remover(nova);
        contagem++;
    }
    return reversa;
}

int main()
{    
    int number;
    scanf("%d", &number);

    Pilha *p = criar();
    
    p = reverterPraPilha(inserirNaPilha(number));
    
    return 0;
}