#include <stdio.h>
#include "../include/init.h"
#include "../include/usuario.h"



void updateData(const Usuario *usr) //atualiza o arquivo com o saldo atual
{
    FILE *data = fopen("users/usrdata.bin", "wb");

    if(data == NULL){
        printf("Não foi possivel acessar o usuário!");
        return 1;
    }

    fwrite(usr, sizeof(*usr), 1, data);

    fclose(data);
}



void readData(Usuario *usr) //atualiza a variavel com o dado que está no arquivo
{
    FILE *data = fopen("users/usrdata.bin", "rb");

    if(data == NULL){
        printf("Não foi possivel acessar o usuário!");
        return 1;
    }

    fread(usr, sizeof(*usr), 1, data);

    fclose(data);

    return 0;
}
