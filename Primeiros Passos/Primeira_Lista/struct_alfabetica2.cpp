#include <iostream> // Questao 2 que pode ficar repetindo
#include <string.h>
using namespace std;

struct Pessoa{
    char nome[30];
    char telefone[30]; 
    char endereco[30];
};

int main()// essa versão do código é para multiplas interações usando um arquivo de texto, ele para de rodar quando vc digita end dentro da variável end
{
    Pessoa p1;
    Pessoa p2;
    Pessoa p3;
    string end = "";
    do{
        cin >> end;
        cin >> p1.nome >> p1.telefone >> p1.endereco;
        cin >> p2.nome >> p2.telefone >> p2.endereco;
        cin >> p3.nome >> p3.telefone >> p3.endereco;

        // ordenar_e_mostrar(&p1, &p2, &p3);

        int resultado = strcmp(p1.nome, p2.nome);
        int resultado_final = 0;

        if(resultado <= -1){ // p1 < p2
            resultado_final = strcmp(p1.nome, p3.nome);

            if(resultado_final <= -1){ // p1<p3 && p2
                resultado_final = strcmp(p2.nome, p3.nome);
                
                if(resultado_final <= -1){ // p1<p2<p3
                    cout << p1.nome << " " << p2.nome << " " << p3.nome << endl; 

                }else{ // p1<p3<p2 ou p1<p3=p2
                    cout << p1.nome << " " << p3.nome << " " << p2.nome << endl;
                }
        
            }else if(resultado_final == 0){ // p1 == p3 < p2
                cout << p1.nome << " " << p3.nome << " " << p2.nome << endl;
            
            }else{// p3<p1<p2
                cout << p3.nome << " " << p1.nome << " " << p2.nome << endl;

            }
        }else if(resultado == 0){ // p1 == p2
            resultado_final = strcmp(p1.nome, p3.nome);
            if(resultado_final <= -1){// p1==p2<p3
                cout << p1.nome << " " << p2.nome << " " << p3.nome << endl;
            }else{//p1==p2==p3 ou p3<p1==p2
                cout << p3.nome << " " << p2.nome << " " << p1.nome << endl;
            }
        
        
        }else{// p2<p1
            resultado_final = strcmp(p1.nome, p3.nome);
            if(resultado_final <= -1){// p2<p1<p3
                cout << p2.nome << " " << p1.nome << " " << p3.nome << endl;
            }else if(resultado_final == 0){//p2<p1==p3
                cout << p2.nome << " " << p1.nome << " " << p3.nome << endl;
            }else{//p2 e p3 < p1
                resultado_final = strcmp(p2.nome, p3.nome);
                if(resultado_final <= -1){//p2<p3<p1
                    cout << p2.nome << " " << p3.nome << " " << p1.nome << endl;
                }else if(resultado_final == 0){//p2==p3<p1
                    cout << p3.nome << " " << p2.nome << " " << p1.nome << endl;                
                }else{//p2<p3<p1
                    cout << p2.nome << " " << p3.nome << " " << p1.nome << endl;
                }
                
            }
        }
    }while(end != "end");

    // cout << p3.nome << " " << p3.telefone << " " << p3.endereco << endl;
    // cout << p1.nome << " " << p1.telefone << " " << p1.endereco << endl;
    // cout << p2.nome << " " << p2.telefone << " " << p2.endereco << endl;
    
    return 0;
}