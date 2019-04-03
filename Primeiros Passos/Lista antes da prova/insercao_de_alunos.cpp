#include <iostream>
using namespace std;

struct aluno{ //ANCHOR mudar o modo de mudar o aluno, ao invés dele receber as informações e sobrepor, tenta receber o aluno por inteiro.
    float ira;//Nao passa o temp_ira e o temp_nome, passa logo o v[i] ou o v[j].s
    string nome;
};

void mostrar(aluno *v, int tam){
    for(int i = 0; i < tam; i++)
    {
        cout << v[i].nome << " ";
        cout << v[i].ira << " ";
    }
    cout << endl;
}



void insertion(aluno *v, int tam){
    int i = 0;
    int j = 0;
    aluno temp;

    for(i = 1; i<tam; i++){
        temp = v[i];

        for(j = i-1; j>=0 ; j--){
            if(v[j].ira > temp.ira){
                v[j+1] = v[j];
            }else break;
        }
        v[j+1] = temp;   
    }
}

int main(){
    int tam = 8;
    //cin >> tam;
    aluno v[tam];
    for(int i=0; i<tam;i++){
        cin >> v[i].ira;
        cin >> v[i].nome;
    }
    
    mostrar(v, tam);
    insertion(v, tam);
    mostrar(v, tam);

    return 0;
}