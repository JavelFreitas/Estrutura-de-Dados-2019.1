#include <iostream>
#include <sstream>
using namespace std;

struct No
{
    No():
    informacao(""), anterior(nullptr), proximo(nullptr)
    {}

    string informacao;
    No *anterior;
    No *proximo;

    void setInfo(string info){
        this->informacao = info;
    }
    string getInfo(){
        return this->informacao;
    }
};

void menu_info(){
    cout << "Escolha o que quer fazer:";
    cout << "1 - adicionar um No";
}

int main()
{
    string info = "";
    int op = 0;
    while(info != "end"){
        switch (op)
        {
            case 1:
                    
                break;
            case 2:

                break;
            default:
                break;
        }
        No primeiro;
        No segundo;

        
        cin >> info;
        primeiro.setInfo(info);

        cin >> info;
        segundo.setInfo(info); 

    }   
}