#include <stdio.h>
#include <stdlib.h>
#include "../include/telas.h"
#include "../include/usuario.h"
#include "../include/cadastrarTransacao.h"
#include "../include/Transacao.h"

int mostrarTransacoes(Usuario *usr)
{
    Transacao transacao = usr->movimentacoes[usr->qtdMovimentacoes - 1];

    system("cls");
    printf("Ultima transação:\n\n");

    printf("Descrição: %s\n", transacao.desc);
    printf("Valor: %.2f\n", transacao.valor);

    switch(transacao.movimentacao)
    {
    case RECEITA:
        printf("Tipo: receita\n");
        break;

    case DESPESA:
        printf("Tipo: despesa\n");
        break;
    }

    printf("Data da transação: %s\n", transacao.data);

    while(getchar() != '\n');

    menu();

    return 0;
}
