#include <iostream>
using namespace std;

void mostrar(int *v, int tam){
    for(int i = 0; i < tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}


void bubble(int *v, int tam){
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = tam; i >= 0; i--){
        for(j = 0; j < tam-1; j++){
            if(v[j]<v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

int main(){
    int v[7] = {8, 2, 7, 3, 9, 2, 0};
    mostrar(v, 7);
    bubble(v, 7);
    mostrar(v, 7);
    return 0;
}