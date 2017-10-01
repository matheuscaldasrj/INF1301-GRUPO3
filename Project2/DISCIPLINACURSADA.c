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
	int situacao;
	char periodo[7];
	float grau;	
};


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: DIC Criar DisciplinaCursada                                                 *
 **************************************************************************/

DIC_tpCondRet DIC_criarDisciplinaCursada (DIC_tpDisciplinaCursada ** pDisciplinaCursada)
{
	//TODO
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



/********** Fim do modulo de implementacao: Modulo DisciplinaCursada **********/
