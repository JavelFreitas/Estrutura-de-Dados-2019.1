#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"

/*
    Funções que vou usar da estrutura da árvore dentro da main:
    [X] inserir(jog_, carta);               insere carta no baralho do jogador, carta é inteiro
    [X] zerar(jog_);                        libera memoria das cartas do jogador
    [X] int remover(Jogador *jog, int i);   remove do jogador um valor
    [X] buscarMenor(jog_first);             busca o menor valor de int do baralho do jogador
*/
typedef struct jogador{
    No *baralho;
    int pontuacao;
    int vitorias;
}Jogador;

typedef struct baralho{
    int cartas[13]; 
}Baralho;           

Baralho *criarBaralho(){
    Baralho *novo = (Baralho*)malloc(sizeof(Baralho));
    int i = 0;
    for(i = 0; i<13 ;i++){
        novo->cartas[i] = 0;
    }
    return novo;
}

Jogador *criarJogador(){
    Jogador *novo_jogador = (Jogador*)malloc(sizeof(Jogador));
    novo_jogador->baralho = criar_no(0);
    novo_jogador->baralho = remover(novo_jogador->baralho,0);
    novo_jogador->pontuacao = 0;
    novo_jogador->vitorias = 0;
    return novo_jogador;
}

void darCarta(Jogador *jog_, Baralho *embaralho){
    int carta = ((rand() % 13) + 1);
    while(carta != 0){
        printf("&&  Dentro do While do darCarta p10, %d\n", carta);
        if(embaralho->cartas[carta-1] < 4){
            printf("&&  Valor da carta no if %d\n", carta);
            jog_->baralho = inserir(jog_->baralho, carta);
            printf("&&  Inserido a carta %d\n", carta);
            embaralho->cartas[carta-1]++;
            carta = 0;
            return;
        }
        carta++;
        if(carta == 14){
            carta = 1;
        }
    }
}

void embaralhar(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int qtd_cartas_jogador = 0;
    printf("&& Antes de criar baralho p6\n");
    Baralho *embaralho = criarBaralho();
    printf("&& Depois de criar baralho p7\n");
    // printf("&&  \n");
    while(qtd_cartas_jogador != 10){
        printf("&&  While do embaralhar p8, loop %d\n", qtd_cartas_jogador);
        printf("Jog 1  \n");
        imprimir_no(jog_first->baralho);
        darCarta(jog_first, embaralho);
        printf("\nJog 2  \n");
        imprimir_no(jog_sec->baralho);
        darCarta(jog_sec, embaralho);
        printf("\nJog 3  \n");
        imprimir_no(jog_third->baralho);
        darCarta(jog_third, embaralho);
        qtd_cartas_jogador++;
    }
    printf("&&  Dei as Cartas p9\n");

}
//////
void embaralhar(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int qtd_cartas_jogador = 0;
    
    Baralho *embaralho = criarBaralho();
    
    while(qtd_cartas_jogador != 10){
        imprimir_no(jog_first->baralho);
        darCarta(jog_first, embaralho);
        qtd_cartas_jogador++;
    }
    qtd_cartas_jogador = 0;
    while(qtd_cartas_jogador != 10){
        imprimir_no(jog_sec->baralho);
        darCarta(jog_sec, embaralho);
        qtd_cartas_jogador++;
    }
    qtd_cartas_jogador = 0;
    while(qtd_cartas_jogador != 10){
        imprimir_no(jog_third->baralho);
        darCarta(jog_third, embaralho);
        qtd_cartas_jogador++;
    }
    qtd_cartas_jogador = 0;
    
    printf("&&  Dei as Cartas p9\n");

}


//////

void rodada(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int carta_um = buscaMenor(jog_first->baralho);
    int carta_dois = buscaMenor(jog_sec->baralho);
    int carta_tres = buscaMenor(jog_third->baralho);
     
    jog_first->baralho = remover(jog_first->baralho, carta_um);
    jog_sec->baralho = remover(jog_sec->baralho, carta_dois);
    jog_third->baralho = remover(jog_third->baralho, carta_tres);
    
    if((carta_um >= carta_dois) && (carta_um >= carta_tres)){
        jog_first->pontuacao++;
        printf("Jogador 1 \n"); 
    }
    if((carta_dois >= carta_um) && (carta_dois >= carta_tres)){
        jog_sec->pontuacao++;
        printf("Jogador 2\n"); 
    }
    if((carta_tres >= carta_um) && (carta_tres >= carta_dois)){
        jog_third->pontuacao++;
        printf("Jogador 3\n"); 
    }
}

void partida(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int i = 0;
    printf("&& Na partida p4\n");
    embaralhar(jog_first, jog_sec, jog_third);
    printf("&& depois do embaralhar p5\n");
    while(i < 10){

        printf("Jog 1  ");
        imprimir_no(jog_first->baralho);
        printf("\nJog 2  ");
        imprimir_no(jog_sec->baralho);
        printf("\nJog 3  ");
        imprimir_no(jog_third->baralho);
        printf("\n");

        rodada(jog_first, jog_sec, jog_third);
        i++;
    }
    printf("_____>Vencedor(es) da Partida\n");
    if(jog_first->pontuacao >= jog_sec->pontuacao && jog_first->pontuacao >= jog_third->pontuacao){
        printf("______Jogador 1\n");
        jog_first->vitorias++;   
    }
    if(jog_sec->pontuacao >= jog_first->pontuacao && jog_sec->pontuacao >= jog_third->pontuacao){
        printf("______Jogador 2\n");
        jog_sec->vitorias++;   
    }
    if(jog_third->pontuacao >= jog_sec->pontuacao && jog_third->pontuacao >= jog_first->pontuacao){
        printf("______Jogador 3\n");
        jog_third->vitorias++;   
    }
}

void vitorioso(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    printf("<<<O(s) vencedor(es) eh(são):>>>\n");
    if(jog_first->vitorias >= jog_sec->vitorias && jog_first->vitorias >= jog_third->vitorias){
        printf("__< Jogador 1 >__\n");    
    }
    if(jog_sec->vitorias >= jog_first->vitorias && jog_sec->vitorias >= jog_third->vitorias){
        printf("__< Jogador 2 >__\n");
    }
    if(jog_third->vitorias >= jog_sec->vitorias && jog_third->vitorias >= jog_first->vitorias){
        printf("__< Jogador 3 >__\n");
    }
}

void jogarJogo(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    printf("&&  Jogar Jogo p1\n");
    int qtd_partidas = 0;
    printf("Escolha quantidade de partidas\n");
    while(qtd_partidas <= 0){
        scanf("%d", &qtd_partidas);
        if(qtd_partidas <= 0){
            printf("Digite um valor positivo\n");
        }
    }

    while(qtd_partidas > 0){
        printf("&& While do Jogar Jogo p2\n");
        partida(jog_first, jog_sec, jog_third);
        printf("&& depois do while do jogar jogo p3\n");
        zerar(jog_first->baralho);
        zerar(jog_sec->baralho);
        zerar(jog_third->baralho);
        qtd_partidas--;
    }

    vitorioso(jog_first, jog_sec, jog_third);

}

void menu(){
    printf("0 - Menu\n");
    printf("1 - Jogar Jogo\n");
    printf("2 - Sair do Jogo\n");
}


int main(){
    srand(time(NULL));
    Jogador *jog_first = criarJogador();
    Jogador *jog_sec = criarJogador();
    Jogador *jog_third = criarJogador();
    int op = 0;

    while(op >= 0){
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            menu();
            break;
        case 1:
            jogarJogo(jog_first, jog_sec, jog_third);
            break;
        case 2:
            printf("Desligando Jogo...\n");
            op = -1;
            break;
        default:
            printf("Comando nao especificado\n");
            break;
        }
    }
    //liberar(jog_, jog_2, jog_3);
    return 0;
}
