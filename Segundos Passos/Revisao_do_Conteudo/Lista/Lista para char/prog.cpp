#include <iostream>
#include "lista.h"
using namespace std;

void options(){
    printf("1 - Show Options");
    printf("2 - Create List");
    printf("3 - Insert into List");
    printf("");
}

int main()
{
    // char nome[20];
    // scanf(" %[^\n]", nome);
    // printf("%s", nome);
    Lista *amigs;
    int op;
    while(1){
        if(op == 0){
            amigs = criar();
        }else if(op == 1){

        }


    }

    return 0;
}