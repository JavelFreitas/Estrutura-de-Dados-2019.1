#include <iostream>
using namespace std;

void selection(int *v, int tam){
    int i = 0;
    int j = 0;
    int pos_min = 0;
    int min = 0;

    for(i = 0; i<tam; i++){
        pos_min = i;
        for(j = i+1; j < tam; j++){
            if(v[j] < v[pos_min]) pos_min = j;
        }
        min = v[pos_min];
        v[pos_min] = v[i];
        v[i] = min;
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
    int v[6] = {7, 4, 2, 8, 1, 8};
    mostrar(v, 6);
    selection(v, 6);
    mostrar(v, 6);
    return 0;
}