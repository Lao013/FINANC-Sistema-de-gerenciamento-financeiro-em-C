
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "AddService.h"

int main() {

    setlocale(LC_ALL, "");
    // o programa aceita caracteres da língua portuguesa.

    int opcao;
    int entradaInvalida;

    do{
        system("cls");
        //system clear para Linux, system cls para Windows.

        printf("+--------------------------------------+\n");
        printf("|               F I N A N C            |\n");
        printf("|       Controle Financeiro Pessoal    |\n");
        printf("+--------------------------------------+\n");
        printf("|                                      |\n");
        printf("|  [1] Registrar transação             |\n");
        printf("|  [2] Editar transação                |\n");
        printf("|  [3] Buscar transação                |\n");
        printf("|  [4] Excluir transação               |\n");
        printf("|  [5] Listar todas as transações      |\n");
        printf("|  [6] Consultar saldo                 |\n");
        printf("|                                      |\n");
        printf("+--------------------------------------+\n");
        printf("|  [0] Sair do sistema                 |\n");
        printf("+--------------------------------------+\n");
        printf("|  Escolha uma opção: ");


        // Verificar se a pessoa digitou algo diferente de um número inteiro:
        // Quando ela digita algo que não é um número inteiro o resultado do scanf é diferente de 1.
        // Aparece a mensagem de erro e o getchar apaga cada caracter que foi digitado até encontra o \n.
        // Como o caracter não é um número, ele não é atribuído a variável opcao, então colocamos manualmente o valor -1
        // como opção de número inteiro inválido para continuar o loop do do while.

        entradaInvalida = 0;

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");

            while (getchar() != '\n');

            opcao = -1;
            entradaInvalida = 1;

        }else{

            switch (opcao)
            {
                case 1:
                    system("cls");
                    ola();
                    break;

                case 2:
                    system("cls");
                    mundo();
                    break;

                case 3:
                    system("cls");
                    printf("Buscar transação\n");
                    break;

                case 4:
                    system("cls");
                    printf("Excluir transação\n");
                    break;

                case 5:
                    system("cls");
                    printf("Listar todas as transações\n");
                    break;

                case 6:
                    system("cls");
                    printf("Consultar saldo\n");
                    break;

                case 0:
                    system("cls");
                    printf("Saindo do FinanC...");
                    break;

                default:
                    printf("Opcao invalida!\n");
                    break;
            }

        }

        // Depois do scanf ler um número inteiro, ainda permanece o \n no buffer
        // o primeiro getchar limpa isso e o segunda aguarda o usuário apertar enter para continuar.
        // Se a pessoa digita uma letra, o tratamento do if para corrigir isso, já usa um getchar
        // então criamos uma variável entradaInvalida evitando que o usuário precise pressionar Enter duas vezes.

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");

            if (entradaInvalida == 0) {
                getchar();
            }

            getchar();
        }

    }while(opcao != 0);
    // do while mantem o programa em um loop para a pessoa entrar em uma opção,
    // fazer o que precisa e voltar para o menu.
    // Enquanto a opção for diferente de zero pois zero fecha o programa.

    return 0;
}

