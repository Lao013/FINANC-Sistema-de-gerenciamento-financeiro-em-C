#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/usuario.h"

void editarTransacao(Usuario *usr)
{
    int codigo;
    int indice = -1;



    if (usr->qtdMovimentacoes == 0) {
        printf("\nNenhuma transacao cadastrada.\n");
        return;
    }

    printf("+--------------------------------------------------+\n");
    printf("|             EDITAR TRANSACOES                    |\n");
    printf("+--------------------------------------------------+\n");

    // Exibe todas as transações para que o usuário escolha qual deseja editar
    for (int i = 0; i < usr->qtdMovimentacoes; i++) {

        printf("| %-3d | %-15s | %-7s | %6.2f | %s \n",
            usr->movimentacoes[i].codigo,
            usr->movimentacoes[i].desc,
            usr->movimentacoes[i].movimentacao == RECEITA ? "Receita" : "Despesa",
            usr->movimentacoes[i].valor,
            usr->movimentacoes[i].data
        );
    }


    // Solicita o código da transação que será editada.
    printf("\nDigite o codigo da transacao que deseja editar: ");
    scanf("%d", &codigo);

    // Limpa o caractere de quebra de linha deixado pelo scanf.
    while (getchar() != '\n');

    // Procura no vetor a transação que possui o código informado.
    for (int i = 0; i < usr->qtdMovimentacoes; i++) {
        if (usr->movimentacoes[i].codigo == codigo) {
            indice = i;
            break;
        }
    }

    // Se o índice continuar -1, significa que o código não foi encontrado.
    if (indice == -1) {
        printf("\nTransacao nao encontrada.\n");
        return;
    }

    // Guarda uma cópia da transação original e cria outra para receber as alterações.
    Transacao antiga = usr->movimentacoes[indice];
    Transacao nova = antiga;

    // Alterar descrição
    printf("\nDescricao atual: %s\n", antiga.desc);
    printf("Digite a nova descricao: ");

    fgets(nova.desc, sizeof(nova.desc), stdin);

    // Remove a quebra de linha inserida pelo fgets.
    nova.desc[strcspn(nova.desc, "\n")] = '\0';

    int tipoNovo;

    // Exibe o tipo atual e solicita o novo tipo da transação.
    printf("\nTipo atual: %s\n",
        antiga.movimentacao == RECEITA ? "Receita" : "Despesa");

    printf("\nEscolha o novo tipo:\n");
    printf("[0] Receita\n");
    printf("[1] Despesa\n");
    printf("Opcao: ");

    scanf("%d", &tipoNovo);
    while (getchar() != '\n');

    // Verifica se o tipo informado é válido.
    if (tipoNovo != 0 && tipoNovo != 1) {
        printf("Tipo invalido!\n");
        return;
    }

    nova.movimentacao = tipoNovo;

    // Solicita o novo valor e verifica se é positivo.
    printf("\nValor atual: R$ %.2f\n", antiga.valor);
    printf("Digite o novo valor: R$ ");

    scanf("%f", &nova.valor);
    while (getchar() != '\n');

    if (nova.valor <= 0) {
        printf("Valor invalido!\n");
        return;
    }

     // Solicita a nova data da transação.
    printf("\nData atual: %s\n", antiga.data);
    printf("Digite a nova data (DD/MM/AAAA): ");

    fgets(nova.data, sizeof(nova.data), stdin);

    nova.data[strcspn(nova.data, "\n")] = '\0';

    int confirmar;

    system("cls");

    // Exibe os dados atualizados para o usuário confirmar a edição.

    printf("\n+--------------------------------------+\n");
    printf("|       CONFIRMAR EDICAO               |\n");
    printf("+--------------------------------------+\n");

    printf("| Codigo: %d\n", nova.codigo);
    printf("| Descricao: %s\n", nova.desc);

    printf("| Tipo: %s\n",
        nova.movimentacao == RECEITA ? "Receita" : "Despesa");

    printf("| Valor: R$ %.2f\n", nova.valor);
    printf("| Data: %s\n", nova.data);

    printf("+--------------------------------------+\n");
    printf("| [1] Confirmar edicao                 |\n");
    printf("| [0] Cancelar edicao                  |\n");
    printf("+--------------------------------------+\n");

    printf("Opcao: ");
    scanf("%d", &confirmar);
    while (getchar() != '\n');

    if (confirmar == 1) {

    // Desfaz o efeito da transação antiga no saldo
    if (antiga.movimentacao == RECEITA) {
        usr->saldoAtual -= antiga.valor;
    } else {
        usr->saldoAtual += antiga.valor;
    }

    // Aplica o efeito da nova transação no saldo
    if (nova.movimentacao == RECEITA) {
        usr->saldoAtual += nova.valor;
    } else {
        usr->saldoAtual -= nova.valor;
    }

    // Atualiza a transação no vetor
    usr->movimentacoes[indice] = nova;

    printf("\nTransacao editada com sucesso!\n");

    } else if (confirmar == 0) {

        printf("\nEdicao cancelada.\n");

    } else {

        printf("\nOpcao invalida. Edicao cancelada.\n");
    }
}
