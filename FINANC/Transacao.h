
#ifndef TRANSACAO_H
#define TRANSACAO_H
// Evita que este arquivo seja incluído mais de uma vez durante a compilação.

// Define uma estrutura para representar uma transação financeira.
typedef struct {
    int codigo;       // Código identificador único da transação.
    char desc[50];    // Descrição da transação (ex: Salário, Mercado).
    char tipo[10];    // Tipo da transação: Receita ou Despesa.
    float valor;      // Valor financeiro da transação.
    char data[11];    // Data da transação no formato DD/MM/AAAA.
} Transacao;          // Nome do tipo criado pelo typedef.

#endif
// Finaliza a proteção contra inclusões repetidas.
