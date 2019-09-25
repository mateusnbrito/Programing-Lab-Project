#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

int main()
{
    int resp, v1, v2, sair=0;

    inicializar();

    while (sair == 0)
    {
        printf("MENU\n\n1 - Criar Estrutura Auxiliar\n2 - Inserir Número em Estrutura Auxiliar\n3 - Excluir Número de Estrutura Auxiliar\n4 - Finalizar\n\n");
        scanf("%d", &resp);

        switch(resp)
        {
            case 1:
            {
                printf("\nInsira o tamanho e a posição: ");
                scanf("%d%d", &v1, &v2);
                criarEstruturaAuxiliar(v1, v2);
                break;
            }
            case 2:
            {
                printf("\nInsira o valor e a posição: ");
                scanf("%d%d", &v1, &v2);
                inserirNumeroEmEstrutura(v1, v2);
                break;
            }
            case 3:
            {
                printf("\nInsira a posição: ");
                scanf("%d", &v1);
                excluirNumeroDoFinaldaEstrutura(v1);
                break;
            }

            case 4:
            {
                finalizar();
                sair = 1;
                break;
            }
        }
    }
}