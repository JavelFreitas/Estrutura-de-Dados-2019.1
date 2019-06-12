#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct jogador{
    Arvore *baralho;
    char nome[30];
    int pontuacao;
    int vitorias;
}Jogador;

typedef struct baralho{
    int cartas[13]; 
}Baralho;           

Baralho *criarBaralho(){
    Baralho *novo = (Baralho*)malloc(sizeof(Baralho));
    int i = 0;
    for(i = 0; i<12 ;i++){
        novo->cartas[i] = 0;
    }
    return novo;
}

Jogador *criarJogador(){
    Jogador *novo_jogador = (Jogador*)malloc(sizeof(Jogador));
    novo_jogador->baralho = criar();
    novo_jogador->nome[0] = "";
    novo_jogador->pontuacao = 0;
    novo_jogador->vitorias = 0;
    return novo_jogador;
}

void embaralhar(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int carta = 0;
    int qtd_cartas_jogador = 0;
    Baralho *embaralho = criarBaralho();
    
    while(qtd_cartas_jogador != 10){
        carta = ((rand() % 13) + 1);
        while(carta != 0){
            if(embaralho->cartas[carta] < 4){
                inserir(jog_first->baralho, carta);
                embaralho->cartas[carta]++;
                carta = 0;
            }
            carta++;
            if(carta == 13)
        }
        



        qtd_cartas_jogador++;
    }
    



}

Jogador *vencedor(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    
}

void rodada(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){  // fixo 10 rodadas, uma por carta;
    int carta_um = remover(jog_first->baralho, buscarMenor()); // falta criar essa estrutura pra retornar o menor valor da árvore;
    int carta_dois = remover(jog_sec->baralho, buscarMenor());
    int carta_tres = remover(jog_third->baralho, buscarMenor());
    if(carta_um >= carta_dois && carta_um >= carta_tres){
        jog_first->pontuacao++;
    }
    if(carta_dois >= carta_um && carta_dois >= carta_tres){
        jog_sec->pontuacao++;
    }
    if(carta_tres >= carta_um && carta_tres >= carta_dois){
        jog_third->pontuacao++;
    }

}

void partida(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int rodadas = 11;
    embaralhar(jog_first, jog_sec, jog_third);
    while(--rodadas){
        rodada(jog_first, jog_sec, jog_third);
    }
}

void menu(){
    printf("Opções do jogo\n");
    printf("1 - Menu\n");
    printf("2 - Jogar o jogo _numeroDeRodadas\n"); // numero maximo de rodadas?
    
}

void jogo(){
    int op = 0;
    int partidas = 0;
    menu();
    while(1){
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            menu();
            break;
        
        case 2:
            printf("Escolha o numero de partidas\n");
            scanf("%d", &partidas);
            Jogador *jog_first = criarJogador();
            Jogador *jog_sec = criarJogador();
            Jogador *jog_third = criarJogador();

            while(partidas > 0){
                partida(jog_first, jog_sec, jog_third);
                partidas--;
            } // Cada jogador tem sua pontuação, mas não se sabe o vencedor



            printf("O vencedor foi o jogador %s");

            break;
        default:
            break;
        }


    }



}



int main(){


    return 0;
}
