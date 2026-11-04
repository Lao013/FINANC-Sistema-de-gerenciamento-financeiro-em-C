#include <stdio.h>
#include "../include/telas.h"
#include "../include/init.h"
#include "../include/usuario.h"

Usuario usrAtual;

int main()
{
    //carrega as informações do arquivo na memória
    readData(&usrAtual);

    //entra no menu
    menu();

    //finaliza o programa e registra o que mudou no arquivo
    updateData(&usrAtual);
    printf("aperte para encerrar");

    return 0;
}
