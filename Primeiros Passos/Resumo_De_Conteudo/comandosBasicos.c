#include <stdio.h>
// Entrada e saida de dados printf e scanf
// Estrutura de condição if else [else if] e switch(case, break, default);
int main(){
    int x = 0; //variável local recebendo 0
    
    printf("Hello World!\n"); //mostrar na tela
    scanf("%d", &x); //receber valor, inserindo-o na variável
    printf("O valor digitado foi %d\n", x); //mostrando na tela o novo valor
    
    if(x>=10){ //Estrutura de condição
        printf("Numero maior ou igual a 10\n");
    }else if(x==10){
        printf("Numero igual a 10\n");
    }else{
        printf("Numero menor que 10\n");
    }
    
    switch(x){ //Outra estrutura de condição
        case 5: //Casos de teste
            printf("Tenha um bom dia\n");
            break;
        case 10:
            printf("Boa sorte!\n");
            break;
        default: //Funciona como o ultimo else, caso nenhum seja verdadeiro esse vai ser usado
            printf("Valor diferente de 10 e 5\n");
    }
    return 0;
}