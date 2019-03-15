#include <iostream> // Questao 4 
using namespace std;

void Swap(int *p, int *q){
    int aux = *p;
    *p = *q;
    *q = aux;
}

int main(){
    int a = 0;
    int b = 0;

    cin >> a;
    cin >> b;

    cout << "O valor de a e b sao respectivamente: " << endl;
    cout << a << " " << b << endl;

    Swap(&a, &b);

    cout << "Os novos valores de a e b sao respectivamente: " << endl;
    cout << a << " " << b << endl;
    return 0;
}