#include "../include/Transacao"
#define MAX_MOVIMENTACOES 60

typedef struct
{
    char name[60];
    double saldoAtual;
    Transacao movimentacoes[MAX_MOVIMENTACOES];
}
