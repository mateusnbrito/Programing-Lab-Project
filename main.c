#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

void testeInserirSemNada();
void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeExcluir();
void testeListar();
void testeRetornarTodosNumeros();

int main(){
    inicializar();
    testeInserirSemNada();
    testeCriarEstrutura();
    testeInserirComEstrutura();
    testeExcluir();
    testeListar();
    testeRetornarTodosNumeros();
    finalizar();
}

void testeInserirSemNada(){
    printf("INSERIR NUMERO EM ESTRUTURA:\n\n");
    printf("%d\n",inserirNumeroEmEstrutura(2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",inserirNumeroEmEstrutura(2, -2) == POSICAO_INVALIDA);
    printf("%d\n",inserirNumeroEmEstrutura(2, 0) == POSICAO_INVALIDA);
    printf("%d\n",inserirNumeroEmEstrutura(2, 11) == POSICAO_INVALIDA);
    printf("\n");
} 

void testeCriarEstrutura(){
    printf("CRIAR ESTRUTURA AUXILIAR:\n\n");
    printf("%d\n",criarEstruturaAuxiliar(5, -2) == POSICAO_INVALIDA);
    printf("%d\n",criarEstruturaAuxiliar(5, 0) == POSICAO_INVALIDA);
    printf("%d\n",criarEstruturaAuxiliar(5, 11) == POSICAO_INVALIDA);
    printf("%d\n",criarEstruturaAuxiliar(-5, 2) == TAMANHO_INVALIDO);
    printf("%d\n",criarEstruturaAuxiliar(0, 2) == TAMANHO_INVALIDO);
    printf("%d\n",criarEstruturaAuxiliar(3, 2) == SUCESSO);
    printf("%d\n",criarEstruturaAuxiliar(6, 2) == JA_TEM_ESTRUTURA_AUXILIAR);
    printf("\n");
}

void testeInserirComEstrutura(){
    printf("INSERIR NUMERO EM ESTRUTURA:\n\n");
    printf("%d\n",inserirNumeroEmEstrutura(4, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(-2, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(6, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(5, 2) == SEM_ESPACO);
    printf("\n");
} 

void testeExcluir(){
    printf("EXCLUIR NUMERO DO FINAL DA ESTRUTURA:\n\n");
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(0) == POSICAO_INVALIDA);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == ESTRUTURA_AUXILIAR_VAZIA);
    printf("\n");
}

void testeListar(){
    printf("INSERIR NUMERO EM ESTRUTURA:\n\n");
    printf("%d\n",inserirNumeroEmEstrutura(7, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(-9, 2) == SUCESSO);
    printf("\n");

    int vet[2];

    printf("GET DADOS ESTRUTURA AUXILIAR:\n\n");
    printf("%d\n",getDadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",getDadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("%d\n",getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
    printf("\n");

    printf("GET DADOS ESTRUTURA AUXILIAR (RESULTADO):\n\n");
    printf("%d\n",vet[0] == 7);
    printf("%d\n",vet[1] == -9);
    printf("\n");

    printf("GET DADOS ORDENADOS ESTRUTURA AUXILIAR:\n\n");
    printf("%d\n",getDadosOrdenadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",getDadosOrdenadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("%d\n",getDadosOrdenadosEstruturaAuxiliar(2, vet) == SUCESSO);
    printf("\n");

    printf("GET DADOS ORDENADOS ESTRUTURA AUXILIAR (RESULTADO):\n\n");
    printf("%d\n",vet[0] == -9);
    printf("%d\n",vet[1] == 7);
    printf("\n");
    
    printf("EXCLUIR NUMERO DO FINAL DA ESTRUTURA:\n\n");
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("\n");

} 

void testeRetornarTodosNumeros(){
    
    int vet1[2];

    printf("GET DADOS DE TODAS ESTRUTURA AUXILIAR:\n\n");
    printf("%d\n",getDadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    printf("%d\n",getDadosOrdenadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    printf("\n");
    
    printf("INSERIR NUMERO EM ESTRUTURA:\n\n");
    printf("%d\n",inserirNumeroEmEstrutura(3, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(8, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(0, 2) == SUCESSO);
    printf("\n");
    
    printf("CRIAR ESTRUTURA AUXILIAR:\n\n");
    printf("%d\n",criarEstruturaAuxiliar(10, 5) == SUCESSO);
    printf("\n");
    
    printf("INSERIR NUMERO EM ESTRUTURA:\n\n");
    printf("%d\n",inserirNumeroEmEstrutura(1, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(34, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(12, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(6, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(27, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(-6, 5) == SUCESSO);
    printf("\n");
    
    int vet[9];

    printf("GET DADOS DE TODAS AS ESTRUTURAS AUXILIARES:\n\n");
    printf("%d\n",getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);
    printf("\n");

    printf("GET DADOS DE TODAS AS ESTRUTURAS AUXILIARES(RESULTADO):\n\n");
    printf("%d\n",vet[0] == 3);
    printf("%d\n",vet[1] == 8);
    printf("%d\n",vet[2] == 0);
    printf("%d\n",vet[3] == 1);
    printf("%d\n",vet[4] == 34);
    printf("%d\n",vet[5] == 12);
    printf("%d\n",vet[6] == 6);
    printf("%d\n",vet[7] == 27);
    printf("%d\n",vet[8] == -6);
    printf("\n");
    
    
    int vet2[9];
    
    printf("GET DADOS ORDENADOS DE TODAS AS ESTRUTURAS AUXILIARES:\n\n");
    printf("%d\n",getDadosOrdenadosDeTodasEstruturasAuxiliares(vet2) == SUCESSO);
    printf("\n");

    printf("GET DADOS ORDENADOS DE TODAS AS ESTRUTURAS AUXILIARES (RESULTADO):\n\n");
    printf("%d\n",vet2[0] == -6);
    printf("%d\n",vet2[1] == 0);
    printf("%d\n",vet2[2] == 1);
    printf("%d\n",vet2[3] == 3);
    printf("%d\n",vet2[4] == 6);
    printf("%d\n",vet2[5] == 8);
    printf("%d\n",vet2[6] == 12);
    printf("%d\n",vet2[7] == 27);
    printf("%d\n",vet2[8] == 34);
    
    config();
}
