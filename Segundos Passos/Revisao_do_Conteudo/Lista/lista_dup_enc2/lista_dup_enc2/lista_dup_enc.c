#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no{
	int valor;
	struct no *prox;
	struct no *ant;
}No;

struct lista{
   No *ini;
    No *fim;
    int qtd_elem;
};

Lista* criar(){
   Lista *l = (Lista*) malloc(sizeof(struct lista));
   l->ini = NULL;
    l->fim = NULL;
    l->qtd_elem = 0;
   return l;
}

void inserir(Lista *l, int valor, int pos){
    if(pos>=0 && pos<=l->qtd_elem){
        if(vazia(l)){
            l->ini = (No*) malloc(sizeof(struct no));
            l->fim = l->ini;
            l->ini->valor = valor;
            l->ini->prox = NULL;
            l->ini->ant = NULL;
        }else{
            No *n= (No*) malloc(sizeof(struct no));
            n->valor = valor;
            
            if(pos==0){
                n->prox = l->ini;
                n->ant = NULL;
                l->ini->ant = n;
                l->ini = n;
            }else{
                int i = 0;
                No *temp = l->ini;
                for(int i=0;i<pos-1;i++) temp = temp->prox;
                
                n->prox = temp->prox;
                if(pos != l->qtd_elem) temp->prox->ant = n;
                n->ant = temp;
                temp->prox = n;
                
                if(pos == l->qtd_elem) l-> fim = n;
            }
        }
        l-> qtd_elem = l->qtd_elem+1;
    }else{
        printf("Posição de inserção inválida");
    }
    
}

int vazia(Lista *l){
   if(l->qtd_elem == 0 ) return 1;
   else return 0; 
}

int remover(Lista *l, int pos){  
   int i=0;
   No *temp = l->ini;
   int valor = 0;
   if(pos>=0 && pos<l->qtd_elem){
       if(!vazia(l)){
           if(pos == 0){
               l->ini = l->ini->prox;
               if(l->ini != NULL) l->ini->ant = NULL;
               valor = temp->valor;
               free(temp);
               l->qtd_elem = l->qtd_elem -1;
               return(valor);
           }else{
               for(int i=0;i<pos;i++) temp = temp->prox;
               
               if(pos != l->qtd_elem-1) temp->prox->ant = temp->ant;
               temp->ant->prox = temp->prox;
               
               if(pos == l->qtd_elem-1) l->fim=temp->ant;
               
               valor = temp->valor;
               free(temp);
               l->qtd_elem = l->qtd_elem -1;
               return(valor);
           }
       }else{
           printf("Lista vazia impossível remover");
           exit(0);
       }
   }else{
       printf("Posição inválida de remoção");
       exit(0);
   }
}


int cheia(Lista *l){
    return 0;
}

void imprimir(Lista *l, int pos){
        No *temp = l->ini;
    if(pos>=0 && pos<l->qtd_elem){
        for(int i=0;i<pos;i++) temp = temp->prox;
        
        printf("%d", temp->valor);
    }else{
        printf("Valor de posição inválido");
    }
}

void liberar(Lista *l){
  if(l->ini != NULL){
    No *temp = l->ini;
    No *temp2 = l->ini->prox;
    while(temp!=NULL){
       free(temp);
       temp = temp2;
       if(temp2 != NULL) temp2= temp2->prox;
    }
   
  }
  free(l);
}
