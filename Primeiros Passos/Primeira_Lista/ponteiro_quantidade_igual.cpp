#include <iostream> // Questao 3
using namespace std;

int fnc(int L[], int n, int Q[], int m){
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1; j++)
        {   
            if(L[j]>L[j+1]){
                int aux = L[j];
                L[j] = L[j+1];
                L[j+1] = aux;
            }
        }
    }
    
    int numeros_iguais = 0;

    for(int i=0;i<n;i++)
    {
        if(i>0){
            if(L[i]==L[i-1]) continue;
        }
        for(int f=0;f<m;f++)
        {
            cout << L[i] << " " << Q[f];
            if(L[i] == Q[f]){
                numeros_iguais++;
                cout << " Numeros iguais :" << numeros_iguais << endl;
                break;
            }
            cout << endl;
        }    
    }
    return numeros_iguais;
}

int main()
{
    int L[5] = {4, 1, 3, 4, 1};
    int Q[5] = {3, 4, 2, 1, 6};
    int n = 5;
    int m = 5;

    int result = fnc(L, n, Q, m);
    cout << "Resultado final: " << result << endl;

    return 0;
}