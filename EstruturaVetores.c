#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

//Atribuição do valor '0' à variável de struct 'posi'.
estrPrin emp = 
{
    .posi = 0,
    .posi2 = 0
};

//variável de Struct para lista
No *lista = NULL;

//Função que cria as estruturas auxiliares.
int criarEstruturaAuxiliar(int tamanho, int posicao)
{
    int ret;
    
    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (tamanho>=1)
        {
            if (p[posicao-1].ptr == NULL)
            {
                if (tamanho < 1000)
                {
                    p[posicao-1].ptr = (int*) malloc(sizeof(int)*tamanho);
                    p[posicao-1].tam = tamanho;

                    ret = SUCESSO;
                }
                else
                {
                    ret = SEM_ESPACO_DE_MEMORIA;
                }
                
                
            }
            else
            {
                ret = JA_TEM_ESTRUTURA_AUXILIAR;
            }
        }
        else
        {
            ret = TAMANHO_INVALIDO;
        }    
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }
    
    return ret;
}

//Função que insere número na estrutura auxiliar.
int inserirNumeroEmEstrutura(int valor, int posicao)
{
    int ret, temEspaco = 0;

    if(p[posicao-1].posi >= p[posicao-1].tam) temEspaco = 1;

    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (p[posicao-1].ptr != NULL)
        {
            if (temEspaco == 0)
            {
                p[posicao-1].ptr[p[posicao-1].posi] = valor;
                p[posicao-1].posi++;

                ret = SUCESSO;
            }
            else
            {
                ret = SEM_ESPACO;
            }
        }
        else
        {
            ret = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }

    return ret;
}

//Função que exclui o número do fim da estrutura.
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int ret;

    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (p[posicao-1].ptr != 0)
        {
            if (p[posicao-1].posi > 0)
            {
                p[posicao-1].posi--;

                ret = SUCESSO;
            }
            else
            {
                ret = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
            ret = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }

    return ret;
}

//Função que exclui o número do fim da estrutura.
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao)
{
    int ret, c1=0, c2=0, aux=-1;

    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (p[posicao-1].ptr != 0)
        {
            if (p[posicao-1].posi != 0)
            {
                while(c1<((p[posicao-1].tam)-1))
                {
                    if(p[posicao-1].ptr[c1] == valor) c2=c1;
                    c1++;
                }
                c1=0;

                if(c2!=-1)
                {
                    c1=c2;
                    while(c1<((p[posicao-1].tam)-1))
                    {
                        aux = p[posicao-1].ptr[c1];
                        p[posicao-1].ptr[c1] = p[posicao-1].ptr[c1+1];
                        p[posicao-1].ptr[c1+1] = aux;
                        c1++;
                    }

                //p[posicao-1].ptr[((p[posicao-1].tam)-1)] = 0;
                p[posicao-1].posi--;

                    ret = SUCESSO;
                }
                else
                {
                    ret = NUMERO_INEXISTENTE;
                }
                
            }
            else
            {
                ret = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
            ret = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }

    return ret;
}

//Função que verifica se uma posição é válida.
int ehPosicaoValida(int posicao)
{
    int ret;
    
    if (posicao < 1 || posicao > 10) ret = POSICAO_INVALIDA;
    else ret = SUCESSO;

    return ret;
}

//Função que copia os dados das estruturas auxiliares.
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int ret, c1=0;

    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (p[posicao-1].ptr != NULL)
        {
            while(c1 < (p[posicao-1].posi))
            {
                vetorAux[c1] = p[posicao-1].ptr[c1];
                c1++;
            }
            c1=0;

            ret = SUCESSO;
        }
        else
        {
            ret = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }

    return ret;
}

//Função que copia os dados das estruturas auxiliares ordenados.
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int ret, c1=0, c2=0, aux;

    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (p[posicao-1].ptr != NULL)
        {
            while(c1 < p[posicao-1].posi)
            {
                vetorAux[c1] = p[posicao-1].ptr[c1];
                c1++;
            }
            c1=1;

            while(c1 <= ((p[posicao-1].tam)-1))
            {
                while(c2 < ((p[posicao-1].tam)-2))
                {
                    if(vetorAux[c2] > vetorAux[c2+1])
                    {
                        aux = vetorAux[c2];
                        vetorAux[c2] = vetorAux[c2+1];
                        vetorAux[c2+1] = aux;
                    }
                    c2++;
                }
                c1++;
                c2=0;
            }
            c1=0;

            ret = SUCESSO;
        }
        else
        {
            ret = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }

    return ret;
}

//Função que recebe os dados de todas as estruturas auxiliares.
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int ret, c1=0, c2=0, c3=0, teste=0;

    while(c1<10)
    {
        if(p[c1].ptr == NULL) teste++;
        c1++;
    }
    c1=0;

    if(teste < 10)
    {
        while(c1<10)
        {
            while(c2 < p[c1].posi)
            {
                vetorAux[c3] = p[c1].ptr[c2];
                c2++;
                c3++;
            }
            c1++;
            c2=0;
        }
        c1=0;
        ret = SUCESSO;
    }
    else ret = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return ret;
}

//Função que recebe os dados de todas as estruturas auxiliares de forma ordenada.
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int ret, c1=0, c2=0, c3=0, teste=0, aux, tam=0;

    while(c1<10)
    {
        if(p[c1].ptr == NULL) teste++;
        else
        {
            tam = tam + p[c1].posi;
        }

        c1++;
    }
    c1=0;

    if(teste != 10)
    {
        while(c1<10)
        {
            while(c2 < p[c1].posi)
            {
                vetorAux[c3] = p[c1].ptr[c2];
                c2++;
                c3++;
            }
            c1++;
            c2=0;
        }
        c1=0;

        while(c1 < tam)
            {
                while(c2 < tam-1)
                {
                    if(vetorAux[c2] > vetorAux[c2+1])
                    {
                        aux = vetorAux[c2];
                        vetorAux[c2] = vetorAux[c2+1];
                        vetorAux[c2+1] = aux;
                    }
                    c2++;
                }
                c1++;
                c2=0;
            }
            c1=0;

        ret = SUCESSO;
    }
    else ret = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;



    return ret;
}

//Função que modifica o tamanho das estruturas auxiliares.
//Adicionar teste de erro de memória.
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int ret;

    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (p[posicao-1].ptr != NULL)
        {
            if (novoTamanho>0)
            {
                p[posicao-1].tam = novoTamanho;
                p[posicao-1].ptr = (int*) realloc(p[posicao-1].ptr, sizeof(int)*novoTamanho);

                ret = SUCESSO;
            }
            else
            {
                ret = NOVO_TAMANHO_INVALIDO;
            }
        }
        else
        {
            ret = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }

    return ret;
}

//Função que recebe a quantidade de elementos existentes em uma estrutura auxiliar.
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int ret;

    if(ehPosicaoValida(posicao) == SUCESSO)
    {
        if (p[posicao-1].ptr != NULL)
        {
            if (p[posicao-1].ptr[0] != '0')
            {
                ret = p[posicao-1].tam;
            }
            else
            {
                ret = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
            ret = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        ret = POSICAO_INVALIDA;
    }

    return ret;

}

//Função que monta a lista encadeada.
No* montarListaEncadeadaComCabecote()
{
    int c1=0;

    while(c1<10)
    {
        while(p[c1].posi2 < p[c1].tam)
        {
            lista = inserirNode(lista, c1);
        }
        c1++;
    }
    c1=0;
}

//Função que copia dos dados da lista encadeada para o vetor.
//Precisa reordenar.
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[])
{
    int c1=0;

    No *aux = inicio;

    while(aux != NULL)
    {
        vetorAux[c1] = aux->num;
        aux = aux->prox;
        c1++;
    }
    c1=0;
}

void destruirListaEncadeadaComCabecote(No* inicio)
{
    No *aux = inicio;

    inicio = aux->prox;
    free(aux);
}

//Função que faz os ponteiros da estrutura principal apontarem para NULL.
void inicializar()
{
    int c1=0;

    while(c1<10)
    {
        p[c1].ptr = NULL;
        c1++;
    }
    c1=0;
}

//PENDENTE
void finalizar()
{
    int c1=0, c2=0;

    while(c1<10)
    {
        free(p[c1].ptr);
        c1++;
    }
    c1=0;
}

//Função que cria nós da lista encadeada.
No* criarNode()
{
    No *novo = (No*) malloc(sizeof(No));
    return novo;
}

//Função que insere nós na lista encadeada.
No* inserirNode(No *inicio, int posicao)
{
    No *novoNode = criarNode();

    novoNode->num = p[posicao].ptr[p[posicao].posi2];
    p[posicao].posi2++;

    if(inicio == NULL)
    {
        inicio = novoNode;
        novoNode->prox = NULL;
    }
    else
    {
        novoNode->prox = inicio;
        inicio = novoNode;
    }
}

void config()
{
    int resp;

    FILE *config;

    config = fopen("config.txt", "a");
    config = fopen("config.txt", "r");

    fscanf(config, "%d", &resp);

    if(resp == 1) impListasDeci();
    else if(resp == 2) impListasBin();
}

void impListasDeci()
{
    int c1=0, c2=0, c3=0;

    FILE *arq;

    arq = fopen("dadosDec.txt", "w");

    while(c1<10)
    {
        arq = fopen("dadosDec.txt", "a");
        
        fprintf(arq, "EP%d: ", c1+1);

        while(c2 < p[c1].posi)
        {
            fprintf(arq, "%d ", p[c1].ptr[c2]);
            c2++;
        }
        fprintf(arq, "\n");
        c2=0;
        c1++;
    }
    c1=0;

    fclose(arq);
}

void impListasBin()
{
    int c1=0, c2=0, c3=0;

    FILE *arq2;

    arq2 = fopen("dadosBin.txt", "wb");

    while(c1<10)
    {
        arq2 = fopen("dadosBin.txt", "ab");
        
        fprintf(arq2, "EP%d: ", c1+1);

        while(c2 < p[c1].posi)
        {
            fwrite (&p[c1].ptr[c2], sizeof(int), 1, arq2);
            c2++;
        }
        fprintf(arq2, "\n");
        c2=0;
        c1++;
    }
    c1=0;

    fclose(arq2);
}