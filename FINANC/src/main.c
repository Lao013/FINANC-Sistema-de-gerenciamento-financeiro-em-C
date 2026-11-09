#pragma once

#include <stdio.h>
#include <locale.h>
#include "../include/telas.h"
#include "../include/init.h"
#include "../include/usuario.h"

extern Usuario cadUsr();

Usuario usrAtual;

int main()
{
    setlocale(LC_ALL, "");
    // o programa aceita caracteres da língua portuguesa.


    //carrega as informações do arquivo na memória
    if(readData(&usrAtual) != 0){
        usrAtual = cadUsr();
    }

    //entra no menu
    menu();

    //finaliza o programa e registra o que mudou no arquivo
    updateData(&usrAtual);
    printf("aperte para encerrar");

    return 0;
}
