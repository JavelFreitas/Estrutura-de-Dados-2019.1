#include <stdio.h>
#include "arvore.h"

int main(){
  int opc, valor, r;
  Arvore *a;
  do{
	printf("Digite a opção desejada: \n 1- Criar Arvore \n 2- Inserir \n 3- Remover \n 4- Imprimir \n 5- Verificar se a Arvore está vazia \n 6- sair\n");
    	scanf("%d", &opc);
	
	switch(opc){
	  case 1:
         a = criar();
 		 printf("arvore criada com sucesso\n");
 	     break;
	  case 2:
 	    printf("Digite o valor a ser inserido na Arvore\n");
 		scanf("%d", &valor);
        inserir(a, valor);
	    break;
	  case 3:
 	    printf("Digite o valor a ser removido\n");
 		scanf("%d", &valor);
  	    r = remover(a, valor);
            
	    if(r) printf("O valor %d foi removido com sucesso\n", valor);
        else printf("O valor %d não existe na árvore\n", valor);
	    break;
	  case 4:
 	    printf("Qual o tipo de percurso 1-pré-ordem, 2-in-ordem, 3-Pós-ordem\n");
 		scanf("%d", &r);
		imprimir(a, r);
        break;
	  case 5:
	 	if(vazia(a)) printf("A arvore está vazia\n");
		else printf("A arvore não está vazia\n");
		break;
	  case 6:
        liberar(a);
		printf("Programa encerrado com sucesso\n");
		break;
      default: printf("Opção Inválida\n");
	}
  }while(opc != 6);
  return(0);
}
