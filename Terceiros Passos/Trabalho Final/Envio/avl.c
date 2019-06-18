#include <stdio.h> 
#include <stdlib.h> 
#include "avl.h"

struct no{
    int valor; 
	No *esq; 
	No *dir; 
	int altura;
};

int vazio(No* no){
    return no == NULL;
}

void imprimir_no(No *n){
    if (n != NULL) {
        printf(" -%d- ", n->valor);
        imprimir_no(n->esq);
        imprimir_no(n->dir);
    }
}

int altura(No *no) { return (vazio(no)) ? 0 : no->altura; } 

int maior(int a, int b){ return (a > b) ? a : b; } 

No* criar_no(int valor){ 
	No* no = (No*) malloc(sizeof(No)); 
	no->valor = valor; 
	no->esq = NULL;
	no->dir = NULL;
	no->altura = 1;
	return(no);
}

void zerar(No* no){
    if (vazio(no))
        return;
    zerar(no->esq);
    zerar(no->dir);
    free(no);
}

No *rotacaoRR(No *no) { 
    printf("&&  Entra na RR\n"); 
    No* aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    printf("&&  Sai da RR\n");
    return aux;
} 

No *rotacaoLL(No *no) { 
    printf("&&  Entrou na LL\n");
    No* aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    printf("&&  Saiu da LL\n");
    return aux;
}

No *rotacaoLR(No *no){
    // printf("&&  Entra na LR\n");
    no->esq = rotacaoLL(no->esq);
    // printf("&&  Rotacionou na LR com a LL\n");
    // printf("&&  Retornando mandando RR\n");
    return rotacaoRR(no);
}

No *rotacaoRL(No *no){
    printf("&&  Entra no RL\n");
    no->dir = rotacaoRR(no->dir);
    printf("&&  Depois de chamar o RR\n");
    printf("&&  Sai do RL\n");
    return rotacaoLL(no);
}

int balanceamento(No *no){ 
	if (no == NULL) 
		return 0; 
	return altura(no->esq) - altura(no->dir); 
}

No* inserir(No* no, int valor) {

	if (vazio(no)){
		return(criar_no(valor));
        printf("&&  Criando no vazio, inserir i1\n");
    }

	if (valor <= no->valor){
		no->esq = inserir(no->esq, valor); 
        printf("&&  inserindo a esquerda %d\n", valor);
    }
	else if (valor > no->valor){
		no->dir = inserir(no->dir, valor); 
        printf("&&  inserindo a direita %d\n", valor);
    } 

	no->altura = 1 + maior(altura(no->esq), altura(no->dir)); 
    printf("&&  Balanceando\n");
	int fator_balanceamento = balanceamento(no);
    printf("&&  Terminou de Balancear o fator%d\n", fator_balanceamento);  

	// ** / ** 
    printf("&&  Primeiro if\n");
	if (fator_balanceamento > 1 && valor < no->esq->valor) {
        printf("&&  Rotacao RR\n");
		return rotacaoRR(no); 
    }

    printf("&&  Seg\n");
	if (fator_balanceamento < -1 && valor > no->dir->valor){
        printf("&&  Rotacao LL\n");
		return rotacaoLL(no); 
    } 
    printf("&&  Terc\n");
	if (fator_balanceamento > 1 && valor > no->esq->valor){
        printf("&&  Rotacao LR\n");
        return rotacaoLR(no);
    }

    printf("&&  Quarto\n");
	if (fator_balanceamento < -1 && valor < no->dir->valor){
        printf("&&  Rotacao RL\n");
		return rotacaoRL(no);
        printf("&&  Depois do RL\n");
    }

    printf("&&  Retornando no %d\n", no->valor);
	return no; 
}


No* remover(No* no, int valor) {
  
    if (vazio(no)) 
        return no; 
  
    if ( valor < no->valor ) 
        no->esq = remover(no->esq, valor); 
  
    else if( valor > no->valor ) 
        no->dir = remover(no->dir, valor); 
  
    else{ 
        if( (no->esq == NULL) || (no->dir == NULL) ) { 
            No* temp = no->esq ? no->esq : no->dir; 
 
            if (temp == NULL){ 
                temp = no; 
                no = NULL; 
            } 
            else  
                *no = *temp;
            free(temp); 
        } 
        else{ 
            No* temp = buscaPosicaoMenor(no->dir); 
            no->valor = temp->valor; 
            no->dir = remover(no->dir, temp->valor); 
        } 
    } 

    if (vazio(no)) 
      return no; 

    no->altura = 1 + maior(altura(no->esq), altura(no->dir)); 
  
    int fator_balanceamento = balanceamento(no); 
  
  
    if (fator_balanceamento > 1 && balanceamento(no->esq) >= 0) 
        return rotacaoRR(no); 
   
    if (fator_balanceamento > 1 && balanceamento(no->esq) < 0) 
    { 
        no->esq =  rotacaoLL(no->esq); 
        return rotacaoRR(no); 
    } 
   
    if (fator_balanceamento < -1 && balanceamento(no->dir) <= 0) 
        return rotacaoLL(no); 
   
    if (fator_balanceamento < -1 && balanceamento(no->dir) > 0) 
    { 
        no->dir = rotacaoRR(no->dir); 
        return rotacaoLL(no); 
    } 
  
    return no; 
} 

int buscaMenor(No *no){
    No *menor_no = no;
    while (menor_no->esq)
        menor_no = menor_no->esq;
    return menor_no->valor;
}

No* buscaPosicaoMenor(No *no){
    No *menor_no = no;
    while (menor_no->esq)
        menor_no = menor_no->esq;
    return menor_no;
}

// int main() {

//     No *root = NULL;

//     root = inserir(root, 9);
//     root = inserir(root, 10);
//     root = inserir(root, 2);
//     root = inserir(root, 3);
//     root = inserir(root, 13);
//     root = inserir(root, 10);
//     root = inserir(root, 3);
//     root = inserir(root, 2);
//     root = inserir(root,3);
//     root = inserir(root, 6);
    

//     imprimir_no(root);

//     // printf("\nMenor elemento: %d\n", buscaMenor(root));
//     int i = 1;
//     while (root != NULL){
//         printf("\n%dº elemento removido: %d\n-> ", i, buscaMenor(root));
//         root = remover(root, buscaMenor(root));
//         imprimir_no(root);
//         printf("\n");
//         i++;
//     }

//     zerar(root);

//     return 0;
// } 
