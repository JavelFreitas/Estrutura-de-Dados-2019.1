#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct No
{

    string informacao;
    No *proximo;

    void setInfo(string info)
    {
        this->informacao = info;
    }
    string getInfo()
    {
        return this->informacao;
    }
};

No *inicio()
{
    return NULL;
}

No *inserir(No *l, string i)
{
    No *no = new No;
    no->setInfo(i);
    no->proximo = l;
    return no;
}

No* remover(No* no, string aux){
    while(no != NULL){
        if(no->getInfo() == aux){
            do{
            


            }while(no != NULL);
        }
        no = no->proximo;
    }
    
    cout << "Nao encontrado" << endl;
    return NULL;
}
void menu_info()
{
    cout << "Escolha o que quer fazer:";
    cout << "1 - Iniciar No";
    cout << "2 - Adicionar No";
}

void mostrar_no(No *no)
{
    short int i = 0;
    while (no != NULL)
    {
        cout  << "[" << i++ << "] "<< no->getInfo() << " ";
        no = no->proximo;
    }
    cout << "[" << i << "]"<< "vazio" << endl;
}

bool esta_vazio(No *no)
{
    if (no == NULL)
        return 1;
    else
        return 0;
}

struct Controller
{
    No *atual = inicio(); //NOTE tenta fazer um if pra iniciar, pergunta pro enyo como que pode ser feito caso não consiga

    void shell(string comandos)
    {
        stringstream ss(comandos);
        string op = "";
        string aux = "";
        ss >> op;

        if (op == "add")
        {
            ss >> aux;
            atual = inserir(atual, aux);
        }
        else if (op == "show")
        {
            mostrar_no(atual);
        }
    }
    void exec()
    {
        string comandos;
        while (true)
        {
            getline(cin, comandos);
            if (comandos == "end")
                return;
            shell(comandos);
        }
    }
};

int main()
{
    Controller c;
    c.exec();
    return 0;
}