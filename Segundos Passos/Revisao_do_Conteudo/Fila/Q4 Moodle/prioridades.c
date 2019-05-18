#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu()
{
    printf("1 - Adicionar na Fila Geral\n");
    printf("2 - Adicionar na Fila Prioritária\n");
    printf("3 - Chamar Próximo a ser Atendido\n");
    printf("4 - Menu\n");
    printf("5 - Encerrar\n");
    printf("6 - Zerar Numero de Atendimento\n");
}

int main()
{

    Fila *prioritaria = criar();
    Fila *geral = criar();
    int tresTurnos = 0;
    int numeroAtendimento = 0;
    int op = 0;

    menu();

    while (1)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            numeroAtendimento++;
            printf("seu numero do atendimento é : Geral-%d\n", numeroAtendimento);
            inserir(geral, numeroAtendimento);
            break;

        case 2:
            numeroAtendimento++;
            printf("seu numero do atendimento é : Prioritario-%d\n", numeroAtendimento);
            inserir(prioritaria, numeroAtendimento);
            break;

        case 3:
            if (vazia(geral) && vazia(prioritaria))
            {
                printf("Filas vazias, tente outro comando.\n");
                break;
            }

            if ((!vazia(prioritaria)) && (tresTurnos <= 3))
            {
                printf("O cliente Prioritario-%d é o próximo a ser atendido\n", remover(prioritaria));
                tresTurnos++;
                break;
            }

            printf("O cliente Geral-%d é o próximo a ser atendido\n", remover(geral));
            tresTurnos = 0;
            break;

        case 4:
            menu();
            break;

        case 5:
            printf("Encerrando...\n");
            return 0;

        case 6:
            if (vazia(geral) && vazia(prioritaria))
            {
                numeroAtendimento = 0;
                printf("Numero de atendimento zerado.\n");
                break;
            }
            printf("As filas precisam estar vazias para zerar o numero do atendimento.\n");
            break;
        default:
            printf("Comando não existe, tente novamente.\n");
            break;
        }
    }

    liberar(prioritaria);
    liberar(geral);

    return 0;
}