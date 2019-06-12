#include <stdio.h>
#include <stdlib.h>
#include "pilha_lista.h"


int main(){
    Lista *pilha = criar();
    int op = 0;
    printf("digite numero de valores: ");
    scanf("%d", &op);
    int op2 = 0;

    while(op > 0){
        int valor = 0;
        printf("valor inserido : ");
        scanf("%d", &valor);
        inserirPilha(pilha, valor);
        op--;
        op2++;
    }

    while(op2 > 0){
        printf("O valor a ser removido é : %d", removerPilha(pilha));
        op2--;
    }
}