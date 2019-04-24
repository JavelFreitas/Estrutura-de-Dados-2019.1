#include <iostream> //REVIEW tenta revolver as questões aqui
#include "pilha.h"
#include <sstream>
#include <time.h>
#include <stdlib.h>

using namespace std;
/* NUMEROS ALEATÓRIOS
    biblioteca time.h e biblioteca stdlib.h, usando a função srand(time(NULL)) para setar um padrão
    rand() retorna um número aleatório entre 0 e um número gigante, mas da pra limitar ele usando mod
    por exemplo rand()%10 para ser entre 0 e 9 AN



*/
void menu(){//TODO termina isso aq
    cout << "1 - Cria pilha" ;
    cout << "2 - Insere na pilha";
    //cout << ;//remove
    //cout << ;// imprime
    //cout << ;// vazio
    //cout << ;// cheio
    //cout << ;// sair
}

struct Controller
{
    Pilha *p = nullptr;

    void shell(string text)
    {
        stringstream ss(text);
        int op;
        int valor = 0;
        ss >> op;

        switch (op)
        {
        case 1:
            p = criar();
            break;
        case 2:
        ss >> valor;
        default:
            cout << "Opção invalida" << endl;
            break;
        }
    }

    void exec()
    {
        string text;
        while (1)
        {
            getline(cin, text);
            if (text == "7")
                return;
            shell(text);
        }
    }
};
int main()
{
    srand(time(NULL));
    cout << 1 + rand()%10;
    // Controller c;
    // c.exec();
    return 0;
}