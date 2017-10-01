/***************************************************************************
 *  $MCD Modulo de implementacao: Modulo Historico
 *
 *	Arquivo gerado
 *  Letras identificadoras:      HIS
 *
 *  Autores: 
*		 mc - Matheus Caldas
 *	     bp - Bruno Pedrazza
 *	     pg - Pedro Gomes
 *	     va - Vinícius Arcoverde
 *	     lf - Leon França
 *	     gc - Gabriel Costa
 *  $HA Historico de evolucao:
 *  Versao       Autor		Data            Observacoes
 *	0.0.1		  mc       28/09/17			Criacao inicial do modulp
 *  $ED Descrição do módulo
 *     Este módulo implementa um conjunto de funcoes para criar e manipular
 *     atributos do módulo Historico.
 *
 *
 *
 ***************************************************************************/

/* Inclusões do compilador */
#include  <stdio.h>
#include  <string.h>
#include  <malloc.h>


/* Inclusão do respectivo módulo de definição */
#define HISTORICO_OWN
#include "HISTORICO.H"
#undef HISTORICO_OWN

/***********************************************************************
 *
 *  $TC Tipo de dados: HIS que define a estrutura do tipo HISTORICO
 *
 *	$ED Descrição do tipo
 *		Descreve a estrutura de um HISTORICO
 *
 ***********************************************************************/

struct HIS_tagHistorico  {   
	//TODO
	int x;
	//Lista<DisplinaCursadas>;
};


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: HIS Criar Historico                                                 *
 **************************************************************************/

HIS_tpCondRet HIS_criarHistorico (HIS_tpHistorico ** pHistorico)
{
	//TODO
    return HIS_CondRetOK ;
} 
/* Fim funcao: HIS Criar Historico */


/**************************************************************************
 *                                                                        *
 * Funcao: HIS remove removeHistorico                                            	  *
 **************************************************************************/
 
HIS_tpCondRet HIS_removeHistorico (HIS_tpHistorico ** pHistorico)
{
	if (*pHistorico == NULL)
		return HIS_CondRetRecebeuPonteiroNulo; 

	else
	{
		free(*pHistorico);
		*pHistorico = NULL;
	}
	return HIS_CondRetOK ;
}
 /* Fim funcao: HIS remove Historico */



/********** Fim do modulo de implementacao: Modulo Historico **********/
