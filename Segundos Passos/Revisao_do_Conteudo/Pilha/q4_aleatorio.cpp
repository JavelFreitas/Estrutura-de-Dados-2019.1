#include <iostream> //REVIEW tenta revolver as questões aqui
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "pilha.h"
#define MAXIMO 5

using namespace std;
/* NUMEROS ALEATÓRIOS
    biblioteca time.h e biblioteca stdlib.h, usando a função srand(time(NULL)) para setar um padrão
    rand() retorna um número aleatório entre 0 e um número gigante, mas da pra limitar ele usando mod
    por exemplo rand()%10 para ser entre 0 e 9.
*/

int main()
{
    srand(time(NULL));
    Pilha *j1;
    Pilha *j2;
    Pilha *aux1;
    Pilha *aux2;
    int i = 0;
    int aleatorio = (1 + rand()%10);
    cout << "Aleatorio :" << aleatorio << endl;

    j1 = criar();
    j2 = criar();
    aux1 = criar();
    aux2 = criar();

    for(i = 0; i<MAXIMO; i++){
        inserir(j1,1 + rand()%10);
        inserir(j2,1 + rand()%10);
    }

    for(i = 0; i<MAXIMO; i++){
        inserir(aux1,remover(j1));
        cout << aux1->topo->valor << " ";
    }

    cout << endl;

    for(i = 0; i<MAXIMO; i++){
        inserir(aux2,remover(j2));
        cout << aux2->topo->valor << " ";
    }

    cout << endl;

    for(i = 0; i<MAXIMO; i++){
        if(aux1->topo->valor == aleatorio){
            cout << "Jogador 1 ganhou" << endl;
            return 0;
        }else if(aux2->topo->valor == aleatorio){
            cout << "Jogador 2 ganhou" << endl;
            return 0;
        }
        remover(aux1);
        remover(aux2);
    }
    cout << "Nenhum jogador ganhou" << endl;
    return 0;
}