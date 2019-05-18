//#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define N 20

Pilha* criar(){
   Pilha *p = (Pilha*) malloc(sizeof(Pilha));
   p->topo = -1;
   return(p);
}

int cheia(Pilha *p){
   if(p->topo == N-1) return 1;
   else return(0);
}

void inserir(Pilha *p, char valor){
   if(p->topo == N-1) printf("A pilha está cheia");
   else{
      p->topo = p->topo+1;
      p->s[p->topo] = valor;
   }
}

int vazia(Pilha *p){
  if(p->topo ==-1) return 1;
  else return 0;
}

char remover(Pilha *p){
   char valor;
   if(vazia(p)){ printf("A pilha está vazia, não é possivel fazer remoção");
    exit(1);
   }
   valor = p-> s[p->topo];
   p->topo = p->topo-1;
   return(valor); 
}

void imprimir(Pilha *p){
  printf("\nO elemento  do topo da pilha é  %d",p->s[p->topo]);
}

void liberar(Pilha *p){
  free(p);
}
