#include <iostream> // Questao 5
using namespace std;

int potenciar(int n){
    if(n <= 1){
        return 2;
    }
    return n = 2 * potenciar(n-1);
}

int main(){
    int variavel = 0;
    cin >> variavel;
    cout << potenciar(variavel);
    return 0;
}