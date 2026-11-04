#pragma once

#include "../include/Transacao.h"
//#define MAX_MOVIMENTACOES 60

typedef struct Usuario
{
    char nome[60];
    double saldoAtual;
    //Transacao movimentacoes[MAX_MOVIMENTACOES];
} Usuario;
