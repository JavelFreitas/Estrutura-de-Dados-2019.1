#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *praBinario(Pilha *p, int number){
    while(number >= 1){
        inserir(p, number % 2);
        number -= (number % 2);
        number /= 2;
        printf("Topo : %d  Valor : %d\n", p->topo, p->v[p->topo]);
    }
    return p;
}

int main(){
    int number = 0;
    printf("O programa esta em loop para melhor teste de resultado.\nO topo simboliza o valor que o elemento da pilha vai estar elevado\n ");
    while (3)
    {
        if(number == 111) break;
        Pilha *p = criar();
        scanf("%d", &number);
        p = praBinario(p, number);
        
    }
    
    
    return 0;
}