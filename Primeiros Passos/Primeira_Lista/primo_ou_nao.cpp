#include <iostream>
#include <math.h>
using namespace std;

int primo(int var, int n){
    if(n >= sqrt(var)){// eh primo
        return 1;
    }
    if(var%n == 0){ // n eh primo
        return 0;
    }
    return primo(var, n+1);
}

int main(){
    int variavel = 0;
    int n = 2;
    cin >> variavel;
    cout << primo(variavel, n);
}