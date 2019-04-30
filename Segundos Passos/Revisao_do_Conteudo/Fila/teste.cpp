#include <iostream> //TODO tenta consertar isso aqui
#include <sstream> // ta dando tipo incompleto
#include "fila.h" // e dizendo que a fila não tem membro
using namespace std;


struct Controller{
    Fila *f;

    void shell(string l){
        stringstream in(l);
        string o = "";
        int valor = 0;
        in >> o;

        f = criar();

        if(o == "init"){
            f = criar();
        }else if(o == "add"){
            in >> valor;
            inserir(f, valor);
            cout << f->n_elem;
        }else if(o == "rm"){
            remover(f);
        }else if(o == "show"){
            imprimir(f);
        }

        cout << "  Deu certo!" << endl;
    }

    void exec(){
        string line;
        while(1){
            getline(cin, line);
            if(line == "end"){
                return;
            }
            shell(line);
        }
        return;
    }

};

int main(){
    Controller c;
    c.exec();
    return 0;
}