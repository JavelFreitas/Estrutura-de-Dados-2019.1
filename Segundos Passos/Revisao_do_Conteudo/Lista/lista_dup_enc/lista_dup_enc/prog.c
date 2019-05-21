#include <stdio.h>
#include "lista.h"

int main(){
  int opc, valor, pos;
  Lista *l;
  do{
	printf("Digite a opção desejada: \n 1- Criar Lista \n2- Inserir \n 3- Remover \n 4- Imprimir \n5- Verificar se a Lista está vazia \n 6- sair");    
    	scanf("%d", &opc);
	
	switch(opc){
	  case 1:
             l = criar();
 		printf("Lista criada com sucesso");
 	     break;
	  case 2:
 	    printf("Digite o valor a ser inserido na Lista");
 		scanf("%d", &valor);
 	    printf("Digite a posição a ser inserido");
 		scanf("%d", &pos);
     		inserir(l, valor, pos);
	     break;
	  case 3:
 	    printf("Digite a posição a ser removido");
 		scanf("%d", &pos);
  	    valor = remover(l, pos);
	    printf("O valor removido foi %d", valor);
	   break;
	  case 4:
 	    printf("Digite a posição da consulta");
 		scanf("%d", &pos);
		imprimir(l, pos);
	        break;
	  case 5:
	 	if(vazia(l)) printf("A lista está vazia");
		else printf("A lista não está vazia");
		break;
	  case 6:
        	liberar(l);
		printf("Programa encerrado com sucesso");
		break;
          default: printf("Opção Inválida");
	}
  }while(opc != 6);
  return(0);
}
