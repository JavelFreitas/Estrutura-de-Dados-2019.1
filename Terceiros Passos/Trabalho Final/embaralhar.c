#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Funções que vou usar da estrutura da árvore dentro da main:
    inserir(jog_, carta);               insere carta no baralho do jogador, carta é inteiro
    zerar(jog_);                        libera memoria das cartas do jogador
    int remover(Jogador *jog, int i);   remove do jogador um valor
    buscarMenor(jog_first);             busca o menor valor de int do baralho do jogador
*/




typedef struct jogador{
    int baralho[13];
    int pontuacao;
    int vitorias;
}Jogador;

typedef struct baralho{
    int cartas[13]; 
}Baralho; 

void inserir(Jogador *jog_, int carta){
    jog_->baralho[carta-1]++;
}

Baralho *criarBaralho(){
    Baralho *novo = (Baralho*)malloc(sizeof(Baralho));
    int i = 0;
    for(i = 0; i<13 ;i++){
        novo->cartas[i] = 0;
    }
    return novo;
}

void darCarta(Jogador *jog_, Baralho *embaralho){ //NOTE Criado com o intuito de reduzir o uso da mesma lógica em diferentes partes do código
    int carta = ((rand() % 13) + 1);
        while(carta != 0){
            if(embaralho->cartas[carta-1] < 4){
                inserir(jog_, carta);
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
void zerar(Jogador *jog){
    for(int i = 0; i<13;i++){
        jog->baralho[i] = 0;
    }
}

void liberar(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    zerar(jog_first);
    zerar(jog_sec);
    zerar(jog_third);
}
void embaralhar(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){
    int carta = 0;
    int qtd_cartas_jogador = 0;
    Baralho *embaralho = criarBaralho();
    
    while(qtd_cartas_jogador != 10){
        darCarta(jog_first, embaralho);
        darCarta(jog_sec, embaralho);
        darCarta(jog_third, embaralho);
        qtd_cartas_jogador++;
    }

}

int buscarMenor(Jogador *jog){
    for(int i = 0; i<13; i++){
        if(jog->baralho[i] > 0){
            return i;
        }
    }
}

int remover(Jogador *jog, int i){
    jog->baralho[i]--;
    return i;
}

void rodada(Jogador *jog_first, Jogador *jog_sec, Jogador *jog_third){  //NOTE  fixo 10 rodadas, uma por carta;
    int carta_um = remover(jog_first, buscarMenor(jog_first)); //NOTE  falta criar essa estrutura pra retornar o menor valor da árvore;
    int carta_dois = remover(jog_sec, buscarMenor(jog_sec));    //FIXME no codigo real, manda a arvore
    int carta_tres = remover(jog_third, buscarMenor(jog_third));
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

void mostrarCartas(Jogador *jog_){
    printf("Cartas :\n");
    for(int i = 0; i<13 ; i++){
        printf("%d ", jog_->baralho[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    Jogador *jog_ = (Jogador*)malloc(sizeof(Jogador));
    Jogador *jog_2 = (Jogador*)malloc(sizeof(Jogador));
    Jogador *jog_3 = (Jogador*)malloc(sizeof(Jogador));
    Baralho *embaralho = (Baralho*)malloc(sizeof(Baralho));
    int qtd_cartas = 0;

    for(int i = 0; i<13 ; i++){

        jog_->baralho[i] = 0;
        jog_2->baralho[i] = 0;
        jog_3->baralho[i] = 0;
    }
    for(int i = 0; i<13 ; i++){

        embaralho->cartas[i] = 0;
    }

    mostrarCartas(jog_);
    mostrarCartas(jog_2);
    mostrarCartas(jog_3);


    int i = 0;
    embaralhar(jog_, jog_2, jog_3);
    while(i < 10){
        mostrarCartas(jog_);
        mostrarCartas(jog_2);
        mostrarCartas(jog_3);
        rodada(jog_, jog_2, jog_3);
        i++;
    }
    //TODO Estrutura da partida
    //TODO Determina vencedor
    printf("Lista de Vencedores: \n");
    if(jog_->pontuacao >= jog_2->pontuacao && jog_->pontuacao >= jog_2->pontuacao){
        printf("Jogador 1\n");   
    }
    if(jog_2->pontuacao >= jog_->pontuacao && jog_2->pontuacao >= jog_3->pontuacao){
        printf("Jogador 2\n");   
    }
    if(jog_3->pontuacao >= jog_2->pontuacao && jog_3->pontuacao >= jog_->pontuacao){
        printf("Jogador 3\n");   
    }

    printf("%d\n", qtd_cartas);
    mostrarCartas(jog_);
    mostrarCartas(jog_2);
    mostrarCartas(jog_3);

    //liberar(jog_, jog_2, jog_3);
    return 0;
}