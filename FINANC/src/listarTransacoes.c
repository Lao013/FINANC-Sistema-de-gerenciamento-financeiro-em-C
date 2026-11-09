#include <stdio.h>
#include <stdlib.h>
#include "../include/usuario.h"
#include "../include/Transacao.h"


void listarReceitas(Usuario *usr)
{

    float totalReceitas = 0.0;
    int qtdReceitas = 0;

    printf("---------RECEITAS--------\n\n");
    for(int i = 0; i < usr->qtdMovimentacoes; i++){
        if(usr->movimentacoes[i].movimentacao == RECEITA){
            printf("\tDescrição: %s - Valor: %.2f - Data: %s \n", usr->movimentacoes[i].desc,
                   usr->movimentacoes[i].valor, usr->movimentacoes[i].data);
            totalReceitas +=  usr->movimentacoes[i].valor;
            qtdReceitas ++;
        }

    }
    if(qtdReceitas == 0){
        printf("Nenhuma receita cadastrada.\n");
        return;
    }

    printf("\nTotal receitas: %.2f\n", totalReceitas);
}


void listarDespesas(Usuario *usr)
{


    float totalDespesas = 0.0;
    int qtdDespesas = 0;

    printf("---------DESPESAS--------\n\n");
    for(int i = 0; i < usr->qtdMovimentacoes; i++){
        if(usr->movimentacoes[i].movimentacao == DESPESA){
            printf("\tDescrição: %s - Valor: %.2f - Data: %s \n", usr->movimentacoes[i].desc,
                   usr->movimentacoes[i].valor, usr->movimentacoes[i].data);
            totalDespesas +=  usr->movimentacoes[i].valor;
            qtdDespesas ++;
        }

    }
    if(qtdDespesas == 0){
        printf("Nenhuma despesa cadastrada.\n");
        return;
    }

    printf("\nTotal despesas: %.2f\n", totalDespesas);
}

void listarTodas(Usuario *usr)
{
    printf("---------TODAS TRANSAÇÕES--------\n\n");
    if(usr->qtdMovimentacoes == 0){
        printf("Nenhuma transação cadastrada.\n");
        return;
    }
    for(int i = 0; i < usr->qtdMovimentacoes; i++){

        switch(usr->movimentacoes[i].movimentacao)
        {
            case RECEITA:
                printf("\t Tipo: Receita - ");
                break;

            case DESPESA:
                printf("\t Tipo: Despesa - ");
                break;
        }
        printf("Descrição: %s - Valor: %.2f - Data: %s \n", usr->movimentacoes[i].desc,
               usr->movimentacoes[i].valor, usr->movimentacoes[i].data);


    }

}
