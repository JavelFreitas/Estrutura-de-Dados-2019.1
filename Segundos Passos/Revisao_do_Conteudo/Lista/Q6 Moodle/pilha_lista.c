#include "pilha_lista.h"

Lista * criarPilha(){
    return criar();
}
void inserirPilha(Lista *pilha, int valor){
    inserir(pilha, valor, pilha->qtd_elem);
}

int removerPilha(Lista *pilha){
    return remover(pilha, pilha->qtd_elem-1);
}

int cheiaPilha(Lista *p){
    return 0;
}

int vaziaPilha(Lista *p){
    if(vazia(p)){
        return 1;
    }
}

void liberarPilha(Lista *p){
    liberar(p);
}

void imprimirPilha(Lista *p){
    imprimir(p, p->ini->valor);
}