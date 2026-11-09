#include <stdio.h>
#include <stdlib.h>
#include "../include/telas.h"
#include "../include/usuario.h"

int mostrarTransacoes(Usuario *usr)
{
    int opcao;

    do{

    system("cls");

    printf("+--------------------------------------+\n");
    printf("|        LISTAGEM DE TRANSACOES        |\n");
    printf("+--------------------------------------+\n");
    printf("|                                      |\n");
    printf("|  [1] Listar somente receitas         |\n");
    printf("|  [2] Listar somente despesas         |\n");
    printf("|  [3] Listar todas as transacoes      |\n");
    printf("|                                      |\n");
    printf("|  [0] Voltar ao menu principal        |\n");
    printf("+--------------------------------------+\n");
    printf("Quantidade total de transações: %d\n", usr->qtdMovimentacoes);
    printf("|  Escolha uma opção: ");

    if(scanf("%d", &opcao) != 1){
        printf("Entrada inválida! Digite um número.\n");

        while(getchar() != '\n');

        system("pause");

        opcao = -1;
        continue;
    }

    switch(opcao){
        case 1:
            system("cls");
            listarReceitas(usr);
            system("pause");
            break;
        case 2:
            system("cls");
            listarDespesas(usr);
            system("pause");
            break;
        case 3:
            system("cls");
            listarTodas(usr);
            system("pause");
            break;
        case 0:
            return 0;
        default:
            printf("Opção inválida! Tente novamente.\n");
            system("pause");
            break;

    }

    }while(opcao != 0);



    return 0;
}
