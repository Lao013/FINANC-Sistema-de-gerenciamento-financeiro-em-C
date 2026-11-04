#include <stdio.h>
#include "../include/init.h"

void updateData() //atualiza o arquivo com o saldo atual
{
    FILE *data = fopen("users/usrdata.bin", "wb");

    if(data == NULL){
        printf("Não foi possivel acessar o usuário!");
        return 1;
    }

    fwrite(&saldoAtual, sizeof(double), 1, data);

    fclose(data);

    return 0;
}



void readData() //atualiza a variavel com o dado que está no arquivo
{
    FILE *data = fopen("users/usrdata.bin", "rb");

    if(data == NULL){
        printf("Não foi possivel acessar o usuário!");
        return 1;
    }

    fread(&saldoAtual, sizeof(double), 1, data);

    fclose(data);

    return 0;
}
