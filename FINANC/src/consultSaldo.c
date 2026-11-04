#include <stdio.h>
#include <stdlib.h>
#include "../include/telas.h"
#include "../include/init.h"

void consultSaldo()
{
    system("cls");
    printf("Nome: %s", usrAtual.nome);
    printf("Saldo atual: %.2f", usrAtual.saldoAtual);
}
