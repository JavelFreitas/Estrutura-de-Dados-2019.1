#include <stdio.h>
// Estruturas de Repetição for, while, do while;
int main(){
    int x = 0, soma = 0;
    printf("\n");

    for(int i = 0;i<=10; i++){ //mais usado quando se sabe o numero de repeticoes Ex: Vetores e Matrizes
        printf("Digite o %d numero\n", i);
        scanf("%d", &x);
        soma += x;
    }

    printf("O valor de x eh %d\n", x);
    printf("A soma de todos os valores eh %d\n\n", soma);

    x = 0;

    while(x != 10){ //mais usado quando o numero de repeticoes eh incerto
        x++;
        printf("O valor atual de x eh %d\n", x);
    }

    printf("\n");
    x = 0;
    int tentativas = 0;
    
    do{
        printf("Adivinhe o numero entre 1 e 10!\n");
        scanf("%d", &x);
        tentativas++;
        if(x == 5){
            printf("5! Voce achou o numero :]\n");
            printf("seu numero de tentativas foi %d\n", tentativas);
        }
    }while(x != 5);

    return 0;
}