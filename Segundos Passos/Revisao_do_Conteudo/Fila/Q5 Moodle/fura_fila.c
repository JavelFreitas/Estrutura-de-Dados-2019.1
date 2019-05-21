#include <stdio.h> //TODO tirar alguns printf do código e ver se da pra refatorar
#include <stdlib.h>
#include "fila_circ.h"

Fila *furaFila(Fila *f, int pos, int elemento)
{
    int cont = 0;
    Fila *aux = criar();
    if(pos == f->fim+1){         //Caso seja para furar qualquer               //Caso o espaço posterior ao ultimo
        inserir(f, elemento);    //Espaço da fila, inclusive a pos-            //não possa ser preenchido pela função furaFila,
        return f;                //terior ao ultimo elemento, é só             // é só comentar da linha 9 a 12 e modificar 
    }                            //Descomentar essas 4 linhas e modificar o    // o if da linha 69 para (pos > f->fim)
    while (!vazia(f))            //if da linha 69 para (pos > f->fim+1)        
    {
        if (cont == pos)
        {
            inserir(aux, elemento);
        }
        inserir(aux, remover(f));
        cont++;
    }
    return aux;
}

void menu()
{

    printf("1 - Menu\n");
    printf("2 - Inserir: _elemento _posição\n");
    printf("3 - Parar Execução\n");
    printf("4 - Mostrar Fila\n");
    printf("5 - Mostrar todos os Elementos da fila (so para teste)\n");
    printf("6 - Inserir Elemento\n");
    return;
}

int main()
{
    Fila *f = criar();
    int elemento = 0;
    int pos = 0;
    int op = 0;

    menu();

    while (1)
    {
        printf("--INSERIR OP\n");
        scanf("%d", &op);
        int ini = f->ini;
        switch (op)
        {
        case 1:
            menu();
            break;
        case 2:
            printf("Digite o elemento\n");
            scanf("%d", &elemento);
            printf("Digite a posição\n");
            scanf("%d", &pos);
            printf("Elemento %d e Posição %d\n", elemento, pos);

            printf("Três dados%d %d %d\n", f->ini, f->fim, cheia(f));
            if (f->fim == -1 && f->ini == -1 && pos == 0)
            {
                inserir(f, elemento);
                break;
            }
            if ((pos < f->ini) || (pos > f->fim+1) || (cheia(f)))
            {
                printf("Nao eh possivel fazer operação, tente novamente.\n");
                break;
            }
            f = furaFila(f, pos, elemento);
            break;
        case 3:
            printf("Saindo...\n");
            return 1;
        case 4:
            imprimir(f);
            printf("\n");
            break;
        case 5:
            while (ini <= f->fim)
            {
                printf("elemento %d : %d\n", ini, f->v[ini]);
                ini++;
            }
            break;
        case 6:
            printf("Inserir elemento\n");
            scanf("%d", &elemento);
            inserir(f, elemento);
        default:
            break;
        }
    }
    return 0;
}