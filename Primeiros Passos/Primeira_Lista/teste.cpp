#include <iostream> 
using namespace std;

void imprimir_numeros(int vec[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int vec[5] = {7, 4, 3, 11 ,1};
    int i = 5;

    imprimir_numeros(vec, i);
    
    for(int n = 0; n < i-1; n++)
    {
        for(int j = 0; j < i-1; j++)
        {   
            if(vec[j]>vec[j+1]){
                int aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }    
    }

    imprimir_numeros(vec, i);
    
    return 0;
}