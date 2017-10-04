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
 *	0.0.1		  mc       28/09/17			Criacao inicial do modulo
  *	0.0.2		  va       04/09/17			inicio implementacao de imprimeHistorico
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
#include "listas.h"


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
	List *disciplinasCursadas;
	//Lista<DisplinaCursadas>;
};


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: HIS Criar Historico                                                 *
 **************************************************************************/

HIS_tpCondRet HIS_criarHistorico (HIS_tpHistorico ** pHistorico)
{
	LIS_tpCondRet retCriacao;

	*pHistorico = NULL;
    *pHistorico = ( HIS_tpHistorico * ) malloc( sizeof( HIS_tpHistorico )) ;

    if( *pHistorico == NULL ){
		return HIS_CondRetFaltouMemoria ;
		}
		
	retCriacao = createList(&((*pHistorico)->disciplinasCursadas));


	if(retCriacao  != LIS_CondRetOK){
		return HIS_CondRetProblemaListaDisciplinas;
	}


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

/**************************************************************************
 *                                                                        *
 * Funcao interna: HIS ordena removeHistorico                                            	  *
 **************************************************************************/

//List* HIS_ordenaHistorico(List* disciplinasCursadas)
//{
//	List* tmp, listaOrdenada;
//	tmp =  disciplinasCursadas->next;
//
//	while(tmp != NULL) 
//	{
//		int valPeriodoCursor = 00
//		if (get_val_cursor(disciplinasCursadas)->periodo )
//
//		tmp = tmp->next;
//	}
//}

/**************************************************************************
 *                                                                        *
 * Funcao: HIS imprimeHistorico                                            	  *
 **************************************************************************/
//HIS_tpCondRet HIS_imprimeHistorico(List* disciplinasCursadas)
//{
//	if(disciplinasCursadas == NULL)
//		HIS_CondRetRecebeuPonteiroNulo;
//	
//	FILE*f = fopen("historico.txt", "w");
//	if (f == NULL)
//	{
//		printf("Error opening file!\n");
//		return HIS_CondRetErroAoAbrirArquivo ;
//	}
//
//	List* tmp;
//	tmp =  next(disciplinasCursadas);
//	while(tmp != NULL) 
//	{
//		fprintf(f, "Periodo: " + get_val_cursor(tmp)->periodo);
//		fprintf(f, get_val_cursor(tmp)->disciplina->nome + ": " + get_val_cursor(tmp)->grau + "  " + get_val_cursor(tmp)->situacao);
//		tmp = tmp->next;
//	}
//	
//	fclose(f);
//
//	return HIS_CondRetOK;
//}

 /* Fim funcao: HIS imprime Historico */

/********** Fim do modulo de implementacao: Modulo Historico **********/
