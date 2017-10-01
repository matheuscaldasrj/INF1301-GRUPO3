/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Disciplina
*
*  Arquivo gerado:              disciplina.C
*  Letras identificadoras:      DIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: 	mrol - Matheus Rodrigues de Oliveira Leal
*             SaintL - Leonardo Abreu Santos
*	      ngtgmp - Felipe Nogueira de Souza
	          LL - Clayton Lucas Mendes Lima
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*       0.01 mrol     30/08/2017  Início do desenvolvimento
*       0.02 ngtgmp   01/09/2017  $Des.
*       0.03 mrol     03/09/2017  $Des. Funções básicas implementadas e funcionando
*		0.04 Leonardo 04/09/2017  $Des. Função delete
*		0.05 todos    05/09/2017  Correções gerais
*		0.05 ngtgmp   08/09/2017  Aumentando a segurança do código - vazamentos de memória nos testes
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#define MAX_NOME 25
#define MAX_CODIGO 8
#define MAX_BIBLIOGRAFIA 300
#define MAX_EMENTA 300
#define MIN_CREDITOS 1
/***********************************************************************
*
*  $TC Tipo de dados: DIS Descritor de Disciplina
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma Disciplina
*
***********************************************************************/
struct disciplina{
  char nome[MAX_NOME];
  char codigo[MAX_CODIGO];
  int creditos;
  char bibliografia[MAX_BIBLIOGRAFIA];
  char ementa[MAX_EMENTA];
};

/***** Protótipos das funções encapuladas no módulo *****/
static char* DIS_le_codigo(void);
static int DIS_le_creditos(void);
static char* DIS_le_nome(void);
static char *DIS_le_ementa(void);
/*****  Código das funções exportadas pelo módulo  *****/
/***************************************************************************
*
*  Função: DIS exibe
*  ****/
DIS_tpCondRet DIS_exibe(Disciplina* d){
  if (d != NULL){
    printf("NOME: %s - CODIGO: %s - CREDITOS: %d - BIBLIOGRAFIA: %s - EMENTA: %s\n",d->nome, d->codigo, d->creditos, d->bibliografia,d->ementa);
    return DIS_CondRetOK;
  }
  return DIS_CondRetErroEstrutura;
} /* Fim função: DIS exibe */
/***************************************************************************
* ngtgmp
*
*  Função: DIS ler ementa
* ****/
char* DIS_le_ementa(void){
  char* ementa = (char *)calloc(MAX_EMENTA, sizeof(char));
  if(ementa == NULL)  { exit(1);  }
  printf("Digite a ementa\n");
  scanf(" %300s", ementa);
  return ementa;
} /* Fim função: DIS ler bibliografia */
/***************************************************************************
*
*  Função: DIS ler creditos
*  ****/
int DIS_le_creditos(void){
  int cred;
  printf("Digite a quantidade de creditos:\n");
  scanf("%d", &cred);
  return cred;
} /* Fim função: DIS ler creditos */
/***************************************************************************
*
*  Função: DIS ler nome
*  ****/
char* DIS_le_nome(void){
  char* n = (char *)calloc(MAX_NOME, sizeof(char));
  if(n == NULL)
  {
    printf("Espaço em memória insuficiente\n");
    exit(-1);
  }
  printf("Digite o nome\n");
  scanf(" %25[^\n]s", n);
  return n;
} /* Fim função: DIS ler creditos */
/***************************************************************************
*
*  Função: DIS ler bibliografia
*  ****/
char *DIS_le_Bib(void){
  char *n = (char *)calloc(MAX_BIBLIOGRAFIA, sizeof(char));
  if(n == NULL)
  {
    printf("Espaço em memória insuficiente\n");
    exit(1);
  }
  printf("Digite a bibliografia\n");
  scanf(" %300[^\n]s", n);
  return n;
} /* Fim função: DIS ler bibliografia */
/***************************************************************************
*
*  Função: DIS ler codigo
*  ****/
char* DIS_le_codigo(void) 				/* Codigo da disciplina no padrão inf0000 */
{
  char* cod1 = (char*)calloc(MAX_CODIGO, sizeof(char)); 	/*cod1 = prefixo*/
  char* cod2 = (char*)calloc(5, sizeof(char));
  if (cod1 == NULL)
  {
    printf("Memoria insuficiente!\n\n");
    exit(1);
  }
  strcat(cod1, "inf");
  printf("\nDigite o codigo numerico da disciplina:\n");
  scanf("%4s", cod2); 				/* O usuario digitará apenas a parte numerica do codigo (4 Numerais no caso)*/
  /*ngtgmp - não deixa o usuário escrever algo que não sejam numerais*/
  while((int)cod2[0]<48 ||(int) cod2[0]>57 ||(int)cod2[1]<48 || (int)cod2[1]>57 || (int)cod2[2]<48 ||(int) cod2[2]>57 ||(int) cod2[3]<48 ||(int) cod2[3]>57 || strlen(cod2)<4)
  {
    printf("Selecione caracteres validos (0 >= x <=9):");
    scanf("%4s", cod2);
  }
  strcat(cod1, cod2);	  			/* Concatena "inf" + 4 numerais no máximo */
  free(cod2);
  return cod1;
}/* Fim função: DIS ler codigo  */
/***************************************************************************
*
*  Função: DIS obter bibliografia
*  ****/
 DIS_tpCondRet DIS_get_bibliografia(Disciplina* dis, char** bibliografia) {
	if (dis->bibliografia)
	{
		*bibliografia = (char*) calloc(MAX_BIBLIOGRAFIA, sizeof(char));
		if(bibliografia == NULL)
		{
			printf("Memoria insuficiente");
      return DIS_CondRetFaltouMemoria;
		}
		strcpy(*bibliografia, dis->bibliografia);
		return DIS_CondRetOK;
	}
	return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter bibliografia */
/***************************************************************************
*
*  Função: DIS obter codigo
*  ****/
DIS_tpCondRet DIS_get_codigo(Disciplina* dis, char** codigo)
{
	if (dis->codigo)
	{
		*codigo = (char*) calloc (MAX_CODIGO, sizeof(char));
			if(codigo == NULL)
			{
				printf("Memoria insuficiente");
        return DIS_CondRetFaltouMemoria;
			}
		strcpy(*codigo, dis->codigo);
		return DIS_CondRetOK;
	}
	return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter codigo */
/***************************************************************************
*
*  Função: DIS obter nome
*  ****/
DIS_tpCondRet DIS_get_nome(Disciplina* dis, char** nome)
{
  if(dis->nome){
   *nome = (char*) calloc (MAX_NOME, sizeof(char));
   if(nome == NULL)
   {
    printf("Memoria insuficiente");
     return DIS_CondRetFaltouMemoria;
   }
   strcpy(*nome,dis->nome);
   return DIS_CondRetOK;
  }
  return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter nome */
/***************************************************************************
*
*  Função: DIS obter ementa
*  ****/
DIS_tpCondRet DIS_get_ementa(Disciplina* dis, char** ementa)
{
  if(dis->ementa)
  {
	*ementa = (char*) calloc (MAX_EMENTA, sizeof(char));
	if(ementa == NULL)
	{
		printf("Memoria insuficiente");
    return DIS_CondRetFaltouMemoria;
	}
	strcpy(*ementa, dis->ementa);
	return DIS_CondRetOK;
  }
  return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter ementa */
/***************************************************************************
*
*  Função: DIS get creditos
*  ****/
DIS_tpCondRet DIS_get_creditos (Disciplina* dis, int *creditos)
{
	if(dis->creditos)
	{
		if(dis->creditos<MIN_CREDITOS)
		{
			printf("Creditos invalidos\n");
			return DIS_CondRetCreditoNegativo;
		}
		*creditos=dis->creditos;
		return DIS_CondRetOK;
	}
	return DIS_CondRetErroEstrutura;
}/* Fim função: DIS get creditos */
/*************************************************************************
*  ngtgmp
*
*  Função: DIS gera uma disciplina por input do teclado
*  ****/
DIS_tpCondRet DIS_gera_cmd(Disciplina** d)
{
  (*d) = (Disciplina*) calloc(1, sizeof(Disciplina));
  if((*d) == NULL)
		return DIS_CondRetFaltouMemoria;
  (*d)->creditos = DIS_le_creditos();
  strcpy((*d)->bibliografia,DIS_le_Bib());
  strcpy((*d)->nome, DIS_le_nome());
  strcpy((*d)->codigo, DIS_le_codigo());
  strcpy((*d)->ementa, DIS_le_ementa());

  return DIS_CondRetDisciplinaCriada;
}/* Fim função: DIS gera uma disciplina por input do teclado */
/*************************************************************************
*  ngtgmp
*
*  Função: DIS gera uma disciplina recebendo parâmetros externos
*  ****/
DIS_tpCondRet DIS_gera_param(Disciplina** d, char* nome, char* codigo, int creditos, char* bibliografia, char* ementa)
{
  (*d) = (Disciplina*) calloc(1,sizeof(Disciplina));
  if((*d) == NULL)
		return DIS_CondRetFaltouMemoria;
  if(sizeof(nome)>MAX_NOME*sizeof(char))
	  return DIS_CondRetParametroInvalido;
  strcpy((*d)->nome, nome);
  if(sizeof(codigo)>MAX_CODIGO*sizeof(char))
	  return DIS_CondRetParametroInvalido;
  strcpy((*d)->codigo, codigo);
  (*d)->creditos = creditos;
  if(sizeof(bibliografia)>MAX_BIBLIOGRAFIA*sizeof(char))
	  return DIS_CondRetParametroInvalido;
  strcpy((*d)->bibliografia, bibliografia);
  if(sizeof(ementa)>MAX_EMENTA*sizeof(char))
	  return DIS_CondRetParametroInvalido;
  strcpy((*d)->ementa, ementa);

  return DIS_CondRetDisciplinaCriada;
}/* Fim função: DIS gera uma disciplina recebendo parâmetros externos */
/***************************************************************************
*
*  Função: DIS deleta disciplina
*  ****/
DIS_tpCondRet DIS_deleta_Disciplina (Disciplina **d)
{
	*d = NULL;
	free(*d);
  return DIS_CondRetDisciplinaDeletada;
}
/* Fim função: DIS deleta Disciplina */
