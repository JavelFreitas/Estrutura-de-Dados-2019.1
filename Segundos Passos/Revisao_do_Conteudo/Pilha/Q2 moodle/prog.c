#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int ehPalindromo(Pilha *pa, char c[])
{ // por exemplo, radar;
    Pilha *aux = criar();
    int auxMain = 0;
    int i = 0;

    while (c[i] != '\0')
    {
        inserir(pa, c[i]); // r a d a r;
        i++;
    }

    auxMain = i / 2;

    while (auxMain > 0)
    {
        inserir(aux, remover(pa)); // r a , d a r
        auxMain--;
    }

    if (i % 2 == 1)
    {
        remover(pa); // removendo o d
    }

    while (auxMain > 0)
    {
        inserir(aux, remover(pa)); // r a , d a r
        auxMain--;
    }

    while(!vazia(pa)){
        if(remover(pa) != remover(aux)){
            return 0;
        }
    }
    return 1;
}

int main()
{

    Pilha *p = criar();
    char c[N];
    scanf("%s", c);
    int i = 0;
    if(ehPalindromo(p, c))
        printf("Eh Palindromo\n");
    else
        printf("Nao eh Palindromo\n");
    return 0;
}