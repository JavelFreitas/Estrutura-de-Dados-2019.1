#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *intercalar(Lista *l, Lista *r){
    Lista *aux = criar();
    Lista *retorno = criar();
    int qtd_elem = 0;
    while(!vazia(l) || !vazia(r)){
        if(!vazia(l)){
            inserir(aux, remover(l, 0), 0);
            qtd_elem++;
        }
        if(!vazia(r)){
            inserir(aux, remover(r, 0), 0);
            qtd_elem++;
        }
    }
    int aux2 = 0;
    while(qtd_elem != 0){
        inserir(retorno, remover(aux, qtd_elem-1),aux2);
        qtd_elem--;
        aux2++;
    }
    return retorno;
}


int main(){

    Lista *l = criar();
    Lista *r = criar();
    Lista *intercalada = criar();
    int n_elem1 = 0;
    int n_elem2 = 0;
    int number = 0;
    int i = 0;
    printf("Digite n de elementos da lista 1 e 2, apos isso insira na lista 1 e depois da lista 2\n");
    scanf("%d %d", &n_elem1, &n_elem2);
    while(n_elem1 > 0){
        scanf("%d", &number);
        inserir(l, number, 0);
        n_elem1--;
    }

    number = 0;

    while(n_elem2 > 0){
        scanf("%d", &number);
        inserir(r, number, 0);
        n_elem2--;
    }
    intercalada = intercalar(l, r);
    No *temp;
    temp = intercalada->ini;

    while(temp != NULL){
        printf("%d", temp->valor);
        temp = temp->prox;
    }

    return 0;
}