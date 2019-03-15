#include <stdio.h> // Questao 1

typedef struct prontuario{
    float altura, peso;
    char nome[50], endereco[50], telefone[8], data_de_nascimento[8]; 
}Prontuario;

int main(){

    Prontuario pac1;
    scanf("%s %s %s %s %f", pac1.nome, pac1.endereco, pac1.telefone, pac1.data_de_nascimento, &pac1.altura);
    printf("%s\n %s\n %s\n %s\n %f\n", pac1.nome, pac1.endereco, pac1.telefone, pac1.data_de_nascimento, pac1.altura);
    return 0;
    
}