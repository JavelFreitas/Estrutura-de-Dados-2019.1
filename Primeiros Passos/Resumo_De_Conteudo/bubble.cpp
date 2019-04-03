#include <iostream>
using namespace std;

void bubble(int *v, int tam){
    int aux = 0;
    int i = 0;
    for(i = (tam-1) ;i > 0;i--){
        for(int j=0;j<i;j++){
            if(v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void mostrar(int *v, int tam){
    for(int i = 0; i < tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int v[6] = {5, 2, 7, 1, 7, 2};
    mostrar(v, 6);
    bubble(v, 6);
    mostrar(v, 6);
    return 0;

}