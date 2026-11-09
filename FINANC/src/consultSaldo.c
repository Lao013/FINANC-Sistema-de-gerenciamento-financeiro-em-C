#include <stdio.h>
#include <stdlib.h>
#include "../include/telas.h"
#include "../include/init.h"

void consultSaldo(Usuario *usr)
{
    system("cls");
    printf("Nome: %s\n", usr->nome);
    printf("Saldo atual: %.2f\n\n", usr->saldoAtual);
}
