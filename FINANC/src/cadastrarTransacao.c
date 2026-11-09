#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/usuario.h"


void cadastrarTransacao(Usuario *usuario){
    int cod, codConf;

    if(usuario->qtdMovimentacoes < MAX_MOVIMENTACOES){ //verificar se nao atingiu o maximo de movimentacoes
        printf("\nDigite a descricao da transacao: ");
        fgets(usuario->movimentacoes[usuario->qtdMovimentacoes].desc, 50, stdin);
        printf("Desrcição: %s", usuario->movimentacoes[usuario->qtdMovimentacoes].desc);

        //procura o \n na palavra e troca por \0
        usuario->movimentacoes[usuario->qtdMovimentacoes].desc[strcspn(usuario->movimentacoes[usuario->qtdMovimentacoes].desc, "\n")] = '\0';

        printf("Tipo de transacao:\n ");
        printf("  [0] Receita\n");
        printf("  [1] Despesa\n");
        scanf("%d", &cod);

        // Limpa o buffer de entrada, removendo os caracteres restantes até a quebra de linha.
        while (getchar() != '\n');
        switch(cod){
            case 0:
                usuario->movimentacoes[usuario->qtdMovimentacoes].movimentacao = RECEITA;//valor enum
                break;
            case 1:
                usuario->movimentacoes[usuario->qtdMovimentacoes].movimentacao = DESPESA;//valor enum
                break;
            default:
                printf("Entrada inválida.");
                return;

        }

       printf("Digite o valor da transacao: ");
       scanf("%f", &usuario->movimentacoes[usuario->qtdMovimentacoes].valor);
       // Limpa o buffer de entrada, removendo os caracteres restantes até a quebra de linha.
       while (getchar() != '\n');

       printf("Digite a data da transacao (DD/MM/AAAA): ");
       fgets(usuario->movimentacoes[usuario->qtdMovimentacoes].data, 11, stdin);

       //procura o \n na palavra e troca por \0
       usuario->movimentacoes[usuario->qtdMovimentacoes].data[strcspn(usuario->movimentacoes[usuario->qtdMovimentacoes].data, "\n")] = '\0';

       //adiciona o codigo de forma automatica, usando a posicao no vetor + 1
       usuario->movimentacoes[usuario->qtdMovimentacoes].codigo = usuario->qtdMovimentacoes + 1;

       system("cls");

       printf("\n+------------------------------------+\n");
       printf("|       CONFIRMAR TRANSACAO            |\n");
       printf("+--------------------------------------+\n");
       printf("| Codigo: %d\n", usuario->movimentacoes[usuario->qtdMovimentacoes].codigo);
       printf("| Descricao: %s\n", usuario->movimentacoes[usuario->qtdMovimentacoes].desc);

       printf("| Tipo: %s\n",
               usuario->movimentacoes[usuario->qtdMovimentacoes].movimentacao == RECEITA ? "Receita" : "Despesa");

       printf("| Valor: R$ %.2f\n", usuario->movimentacoes[usuario->qtdMovimentacoes].valor);
       printf("| Data: %s\n", usuario->movimentacoes[usuario->qtdMovimentacoes].data);

       printf("+--------------------------------------+\n");
       printf("| [1] Confirmar cadastro                |\n");
       printf("| [0] Cancelar cadastro                 |\n");
       printf("+--------------------------------------+\n");

       scanf("%d", &codConf);
       //limpar buffer de entrada
       while (getchar() != '\n');
       if(codConf == 1){
           usuario->qtdMovimentacoes++;
           printf("Transacao salva com sucesso.");
       }else if(codConf == 0){
           printf("Cadastro cancelado.");
           return;
       }else{
            printf("Opcao invalida.");
       }

    }else{
        printf("Máximo de movimentações cadastradas.");

    }


}
