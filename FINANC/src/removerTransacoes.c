#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/usuario.h"

int removerTransacoes(Usuario *usr)
{
    int id;
    char escolha;

    printf("+--------------------------------------+\n");
    printf("|        Remover uma transação         |\n");
    printf("+--------------------------------------+\n");

    printf("\n\nDigite o codigo da transação que você ira remover:\n>");
    scanf("%d", &id);

    if(usr->qtdMovimentacoes == 0){
        printf("Nenhuma transação cadastrada.\n");
        return 1;
    }
    for(int i = 0; i < usr->qtdMovimentacoes; i++){
        if(usr->movimentacoes[i].codigo == id){
            system("cls");
            printf("[==== Transação %d ====]\n\n", id);

            printf("movimentação: %s\n", usr->movimentacoes[i].desc);

            switch (usr->movimentacoes[i].movimentacao)
            {
            case 0:
                printf("Tipo: receita\n");
                break;

            case 1:
                printf("Tipo: despesa\n");
                break;
            }

            printf("Valor: %.2f\n\n", usr->movimentacoes[i].valor);


            printf("=== Deseja remover esta transação? === [s / n]\n > ");
            scanf(" %c", &escolha);

            switch (escolha)
            {
            case 's':
                // Atualiza o saldo de acordo com o tipo da transação removida.
                if (usr->movimentacoes[i].movimentacao == RECEITA) {
                    usr->saldoAtual -= usr->movimentacoes[i].valor;
                } else {
                    usr->saldoAtual += usr->movimentacoes[i].valor;
                }

                printf("\nSaldo apos remocao: %.2f\n", usr->saldoAtual);

                for(int j = i; j < usr->qtdMovimentacoes; j++){
                    usr->movimentacoes[j] = usr->movimentacoes[j + 1];
                }
                usr->qtdMovimentacoes--;
                usr->movimentacoes[usr->qtdMovimentacoes] = (Transacao){0};
                printf("\n**Transação removida**\n");
                Sleep(3000);
                break;

            case 'n':
                printf("\n**Ação cancelada!");
                Sleep(3000);
                break;
            }

        }
    }

    return 0;
}
