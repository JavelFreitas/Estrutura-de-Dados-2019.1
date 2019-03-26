#include <iostream>
using namespace std;

int soma(int x, int y){return x+y;}

void dizerOi(){cout << "OI";}

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    dizerOi();
    cin >> a >> b;
   cout << soma(a,b); 

   return 0;
}