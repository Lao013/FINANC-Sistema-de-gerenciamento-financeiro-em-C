#include <stdlib.h>
#include <stdio.h>

void reboot()
{
    FILE *arquivo = fopen("users/usrdata.bin", "wb");
    abort();
}
