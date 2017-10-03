/***************************************************************************
 *  $MCD Modulo de implementacao: Modulo DisciplinaCursada.c
 *
 *	Arquivo gerado
 *  Letras identificadoras:      DIC
 *
 *  Autores: 
*		 mc - Matheus Caldas
 *	     bp - Bruno Pedrazza
 *	     pg - Pedro Gomes
 *	     va - Vinícius Arcoverde
 *	     lf - Leon França
 *	     gc - Gabriel Costa
 *  $HA DisciplinaCursada de evolucao:
 *  Versao       Autor		Data            Observacoes
 *	0.0.1		  mc       30/09/17			Criacao inicial do modulo
 *	1.0.1         va        30/09/2017   	Implementaçacao das funcoes de criar e
												set situacao, grau e periodo.
*	1.0.2		  va       03/09/17			Correção de parametros do criarDisciplina e comparando string da situacao

 *  $ED Descrição do módulo
 *     Este módulo implementa um conjunto de funcoes para criar e manipular
 *     atributos do módulo DisciplinaCursada.
 *
 *
 *
 ***************************************************************************/

/* Inclusões do compilador */
#include  <stdio.h>
#include  <string.h>
#include  <malloc.h>
#include "disciplina.h"

/* Inclusão do respectivo módulo de definição */
#define DISCIPLINACURSADA_OWN
#include "DISCIPLINACURSADA.H"
#undef DISCIPLINACURSADA_OWN


/* Inclusao dos modulos dependentes */


/***********************************************************************
 *
 *  $TC Tipo de dados: DIC que define a estrutura do tipo DisciplinaCursada
 *
 *	$ED Descrição do tipo
 *		Descreve a estrutura de uma DisciplinaCursada
 *
 ***********************************************************************/

struct DIC_tagDisciplinaCursada  {   

	Disciplina *disciplina;
	char situacao[3];
	char periodo[7];
	float grau;	
};


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: DIC Criar DisciplinaCursada                                                 *
 **************************************************************************/

DIC_tpCondRet DIC_criarDisciplinaCursada (DIC_tpDisciplinaCursada ** pDisciplinaCursada, Disciplina *disciplina, char *situacao, char* periodo, float grau)
{
	*pDisciplinaCursada = NULL;
	*pDisciplinaCursada = ( DIC_tpDisciplinaCursada * ) malloc( sizeof( DIC_tpDisciplinaCursada )) ;
	if (*pDisciplinaCursada == NULL)
		return DIC_CondRetFaltouMemoria;

	DIC_setDisciplina(*pDisciplinaCursada, disciplina);
	DIC_setGrau(*pDisciplinaCursada, grau);
	DIC_setPeriodo(*pDisciplinaCursada, periodo);
	DIC_setSituacao(*pDisciplinaCursada, situacao);

    return DIC_CondRetOK ;
} 
/* Fim funcao: DIC Criar DisciplinaCursada */


/**************************************************************************
 *                                                                        *
 * Funcao: DIC remove removeDisciplinaCursada                                            	  *
 **************************************************************************/
 
DIC_tpCondRet DIC_removeDisciplinaCursada (DIC_tpDisciplinaCursada ** pDisciplinaCursada)
{
	if (*pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo; 
	else
	{
		free(*pDisciplinaCursada);
		*pDisciplinaCursada = NULL;
	}
	return DIC_CondRetOK ;
}

 /* Fim funcao: DIC remove DisciplinaCursada */

/**************************************************************************
 *                                                                        *
 * Funcao: DIC set grau da disciplina cursada                                                *
 **************************************************************************/

DIC_tpCondRet DIC_setDisciplina (DIC_tpDisciplinaCursada * pDisciplinaCursada, Disciplina *disciplina)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;

	if (disciplina == NULL)
		return DIC_CondRetParamInvalido;

	pDisciplinaCursada->disciplina = disciplina;
    return DIC_CondRetOK ;
} 
/* Fim funcao: DIC set grau da disciplina cursada */

/**************************************************************************
 *                                                                        *
 * Funcao: DIC set grau da disciplina cursada                                                *
 **************************************************************************/

DIC_tpCondRet DIC_setGrau (DIC_tpDisciplinaCursada *pDisciplinaCursada, float grau)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;
	
	if (grau > 10 || grau < 0)		
		return DIC_CondRetParamInvalido;

	pDisciplinaCursada->grau = grau;

    return DIC_CondRetOK ;
} 
/* Fim funcao: DIC set grau da disciplina cursada */

/**************************************************************************
 *                                                                        *
 * Funcao: DIC set periodo da disciplina cursada                                                *
 **************************************************************************/

DIC_tpCondRet DIC_setPeriodo (DIC_tpDisciplinaCursada * pDisciplinaCursada, char* periodo)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;
	
	if (periodo == NULL || strlen(periodo) >= 7)
		return DIC_CondRetParamInvalido;
	
	strcpy(pDisciplinaCursada->periodo, periodo);

    return DIC_CondRetOK ;
} 
/* Fim funcao: DIC set periodo da disciplina cursada */


/**************************************************************************
 *                                                                        *
 * Funcao: DIC set situacao da disciplina cursada                                                *
 **************************************************************************/

DIC_tpCondRet DIC_setSituacao (DIC_tpDisciplinaCursada *pDisciplinaCursada, char* situacao)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;
	
	if (situacao == NULL || strlen(situacao) > 3 || strcmp(situacao, "AP") != 0 || strcmp(situacao, "RN") != 0 || strcmp(situacao, "RF") != 0)		
		return DIC_CondRetParamInvalido;
			
		return DIC_CondRetParamInvalido;

	strcpy(pDisciplinaCursada->situacao, situacao);

    return DIC_CondRetOK ;
} 
/* Fim funcao: DIC set grau da disciplina cursada */

/**************************************************************************
*                                                                        	*
* Funcao: DIC set TODOS os campos de uma disciplina cursada        				*
**************************************************************************/
DIC_tpCondRet DIC_setTodosOsCampos(DIC_tpDisciplinaCursada *pDisciplinaCursada, Disciplina disciplina, int situacao, char * periodo, float grau)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;
	
	if (disciplina == NULL)
		return DIC_CondRetParamInvalido;
	pDisciplinaCursada->disciplina = disciplina;
	
	if(periodo == NULL || strlen(periodo) >= 7)
		return DIC_CondRetParamInvalido;
	strcpy(pDisciplinaCursada->periodo, periodo);
	
	if( situacao == NULL || strlen(situacao) > 3 || !strcmp(situacao, "AP") || !strcmp(situacao, "RN") || !strcmp(situacao, "RF"))
		return DIC_CondRetParamInvalido;
	strcpy(pDisciplinaCursada->situacao, situacao);
	
	if(grau > 10 || grau < 0)
		return DIC_CondRetParamInvalido;
	pDisciplinaCursada->grau = grau;
	
	return DIC_CondRetOK;
}
/* Fim funcao: DIC set Todos Os Campos da disciplina cursada*/

/**************************************************************************
 *                                                                        *
 * Funcao: DIC get disicplina da disciplina cursada                                                *
 **************************************************************************/

DIC_tpCondRet DIC_getDisciplina (DIC_tpDisciplinaCursada *pDisciplinaCursada, Disciplina *disciplina)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;

	disciplina = pDisciplinaCursada->disciplina;

    return DIC_CondRetOK;
} 
/* Fim funcao: DIC get disciplina da disciplina cursada */

/**************************************************************************
 *                                                                        *
 * Funcao: DIC get grau da disciplina cursada                                                *
 **************************************************************************/


DIC_tpCondRet DIC_getGrau (DIC_tpDisciplinaCursada * pDisciplinaCursada, float* grau)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;

	*grau = pDisciplinaCursada->grau;
    return DIC_CondRetOK ;
} 
/* Fim funcao: DIC get grau da disciplina cursada */

/**************************************************************************
*                                                                        *
* Funcao: DIC get situacao da disciplina cursada                         *
**************************************************************************/
DIC_tpCondRet DIC_getSituacao(DIC_tpDisciplinaCursada *pDisciplinaCursada, char* situacao)
{
	if (pDisciplinaCursada == NULL)
		return DIC_CondRetRecebeuPonteiroNulo;

	strcpy(situacao, pDisciplinaCursada->situacao);
	return DIC_CondRetOK;
}
/* Fim funcao: DIC get situacao da disciplina cursada */


/********** Fim do modulo de implementacao: Modulo DisciplinaCursada **********/
