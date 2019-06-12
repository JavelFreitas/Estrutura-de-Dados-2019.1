#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
    int qtd_cartas_jogador = 0;
    while(qtd_cartas_jogador != 10){ printf("%d\n", ((rand() % 13) + 1) ); qtd_cartas_jogador++;}
}