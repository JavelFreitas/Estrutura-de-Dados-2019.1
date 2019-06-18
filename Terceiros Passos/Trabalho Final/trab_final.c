#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sogliato.h"

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
    novo_jogador->baralho = criar();
    novo_jogador->pontuacao = 0;
    novo_jogador->vitorias = 0;
    return novo_jogador;
}

void darCarta(Jogador *jog_, Baralho *embaralho){ //NOTE Criado com o intuito de reduzir o uso da mesma lógica em diferentes partes do código
    int carta = ((rand() % 13) + 1);
    while(carta != 0){
        if(embaralho->cartas[carta-1] < 4){
            jog_->baralho = inserir(jog_->baralho, carta);
            embaralho->cartas[carta-1]++;
            carta = 0;
            return;
        }
        carta++;
        if(carta == 13){
            carta = 1;
        }
    }
}

void embaralhar(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int qtd_cartas_jogador = 0;
    Baralho *embaralho = criarBaralho();
    
    while(qtd_cartas_jogador != 10){
        darCarta(jog_first, embaralho);
        darCarta(jog_sec, embaralho);
        darCarta(jog_third, embaralho);
        qtd_cartas_jogador++;
    }

}

void rodada(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){  //NOTE  fixo 10 rodadas, uma por carta;
    int carta_um = buscarMenor(jog_first->baralho); //NOTE  falta criar essa estrutura pra retornar o menor valor da árvore;
    int carta_dois = buscarMenor(jog_sec->baralho);    //FIXME no codigo real, manda a arvore
    int carta_tres = buscarMenor(jog_third->baralho);
     
    jog_first->baralho = remover(jog_first->baralho, carta_um); //NOTE  falta criar essa estrutura pra retornar o menor valor da árvore;
    jog_sec->baralho = remover(jog_sec->baralho, carta_dois);    //FIXME no codigo real, manda a arvore
    jog_third->baralho = remover(jog_third->baralho, carta_tres));
    
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
    
    embaralhar(jog_first, jog_sec, jog_third);
    while(i < 10){

        imprimir(jog_first->baralho);
        imprimir(jog_sec->baralho);
        imprimir(jog_third->baralho);

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

    int qtd_partidas = 0;
    printf("Escolha quantidade de partidas\n");
    while(qtd_partidas <= 0){
        scanf("%d", &qtd_partidas);
        if(qtd_partidas <= 0){
            printf("Digite um valor positivo\n");
        }
    }

    while(qtd_partidas > 0){
        partida(jog_first, jog_sec, jog_third);//TODO Estrutura da partida
        zerarJogadores(jog_first, jog_sec, jog_third); // deleta todos os nos, até mesmo o principal.
        qtd_partidas--;
    }

    vitorioso(jog_first, jog_sec, jog_third);

}

void menu(){
    printf("0 - Menu\n");
    printf("1 - Jogar Jogo\n");
    printf("2 - Sair do Jogo\n");
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
