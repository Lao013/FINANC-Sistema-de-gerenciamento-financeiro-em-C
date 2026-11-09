#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario cadUsr()
{
    Usuario usr =
    {
        .saldoAtual = 0.0,
        .qtdMovimentacoes = 0
    };

    system("cls");

    printf("Insira o nome de usuário: ");
    scanf("%s", &usr.nome);


    system("cls");
    printf("\nNome: %s", usr.nome);
    printf("\nSaldo atual: %.2f", usr.saldoAtual);
    printf("\nMovimentações: %d", usr.qtdMovimentacoes);

    printf("\n\nUsuario cadastrado!");
    printf("\n\n\n\nPressione qualquer trcla para  sair");
    while(getchar() != '\n');

    return usr;
}
