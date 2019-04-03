#include <iostream>
using namespace std;

void mostrar(int *v, int tam);

void insertion(int *v, int tam){
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = 1; i<tam ; i++){
        
        temp = v[i];
        for(j = i-1; j>=0 ; j--){
            if(v[j]> temp) v[j+1] = v[j];
            else break;
        }
        v[j+1] = temp;
        mostrar(v, 7);
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
    int v[7] = {6, 19, 8, 2, 9, 3, 0};
    mostrar(v, 7);
    insertion(v, 7);
    mostrar(v, 7);
    return 0;
}