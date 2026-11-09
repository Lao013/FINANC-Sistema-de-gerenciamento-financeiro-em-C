#pragma once

#define MAX_MOVIMENTACOES 60

typedef enum
{
    RECEITA,
    DESPESA,
} tipo;

// Define uma estrutura para representar uma transação financeira.
typedef struct {
    int codigo;       // Código identificador único da transação.
    char desc[50];    // Descrição da transação (ex: Salário, Mercado).
    tipo movimentacao;// Tipo da transação: Receita ou Despesa.
    float valor;      // Valor financeiro da transação.
    char data[11];    // Data da transação no formato DD/MM/AAAA.
} Transacao;          // Nome do tipo criado pelo typedef.

typedef struct Usuario
{
    char nome[60];
    double saldoAtual;
    Transacao movimentacoes[MAX_MOVIMENTACOES];
    int qtdMovimentacoes;
} Usuario;
