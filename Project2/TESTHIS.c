/***************************************************************************
*$MCI Módulo de implementação: Módulo de teste específico
*	Arquivo: TESTHIS.C
*	Proprietário: Grupo 3 INF1301 17.2
*	Projeto: Trabalho 2
*	Gestor:  DI/PUC-Rio
*  	Autores: mc - Matheus Caldas
*	         bp - Bruno Pedrazza
*	         pg - Pedro Gomes
*	         va - Vinícius Arcoverde
*	         lf - Leon França
*	         gc - Gabriel Costa
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*$HA Alterações:
*      Versão  Autor    Data     	Observações
*	1.00	BP   	01/10/2017  	Criação do arquivo básico de testes
*	1.5		PG		05/10/2017		Adicionando Criação e Remoção
*	
*       1.00	BP   	01/10/2017  	Criação do arquivo básico de testes
*$ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo Historico.
*$EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo Historico:
*
*
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include	<stdlib.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "HISTORICO.H"
#include	"listas.h"
#include	"disciplina.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define	CRIA_HIST_CMD		"=criaHIS"
#define	REMOVE_HIST_CMD		"=removeHIS"
#define	GET_HIS_CMPT_CMD	"=getHisCompleto"
#define	GET_HIS_PRD_CMD		"=getHisPeriodo"
#define	GET_CR_TOTAL_CMD	"=getCrTotal"
#define	GET_CR_PRD_CMD		"=getCrPeioro"
#define IMPRIME_HIST_CMD	"=imprimeHist"

#define MAX 15

HIS_tpHistorico *pHistorico[MAX] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

 TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
 {
	 HIS_tpCondRet HIS_CondRetObtido = HIS_CondRetOK;
	 HIS_tpCondRet HIS_CondRetEsperada = HIS_CondRetFaltouMemoria;
											/* inicializa para qualquer coisa */

	 int i = 0;
	 int indexH; //indice Historico
	 int  NumLidos = -1 ;
	 int LIST_CondRetObtido = -999;
	 char periodo[7];
	 float cr;
	 List* list;
	 Disciplina* disciplinas[5];

	 TST_tpCondRet Ret;

	   if ( strcmp( ComandoTeste , CRIA_HIST_CMD ) == 0 )
	   {
			NumLidos = LER_LerParametros("ii", &indexH, &HIS_CondRetEsperada);
			if( NumLidos != 2)
            {
               return TST_CondRetParm;
            } /* if */

			HIS_CondRetObtido = HIS_criarHistorico(&pHistorico[indexH]);

			return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao criar Historico");

	   }

	   ////////////////////////////////////////////
	   ////////////////////////////////////////////

	   else if( strcmp( ComandoTeste , REMOVE_HIST_CMD ) == 0 )
	   {
		   NumLidos = LER_LerParametros("ii", &indexH, &HIS_CondRetEsperada);
			if( NumLidos != 2)
            {
               return TST_CondRetParm;
            } /* if */

			HIS_CondRetObtido = HIS_removeHistorico(&pHistorico[indexH]);

			return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao remover Historico");

	   }

	   ////////////////////////////////////////////
	   ////////////////////////////////////////////

	   else if( strcmp( ComandoTeste , GET_HIS_CMPT_CMD ) == 0 )
	   {
		   NumLidos = LER_LerParametros("ii", &indexH, &HIS_CondRetEsperada);
		   if (NumLidos != 2) {
			   return TST_CondRetParm;
		   }

		   list = NULL;
		   LIST_CondRetObtido = createList(&list);

		   if (LIST_CondRetObtido != LIS_CondRetOK) {
			   return TST_CondRetErro;
		   }
		   

		   HIS_CondRetObtido = HIS_getHistoricoCompleto(pHistorico[indexH], list);		   

		   return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao pegar historico completo");
	   }

	   ////////////////////////////////////////////
	   ////////////////////////////////////////////

	   else if( strcmp( ComandoTeste , GET_CR_TOTAL_CMD ) == 0 )
	   {
		   NumLidos = LER_LerParametros("ii", &indexH, &HIS_CondRetEsperada);
		   if (NumLidos != 2) {
			   return TST_CondRetParm;
		   }

		   list = NULL;
		   LIST_CondRetObtido = createList(&list);

		   if (LIST_CondRetObtido != LIS_CondRetOK) {
			   return TST_CondRetErro;
		   }
		   
		   HIS_CondRetObtido = HIS_getCrTotal(pHistorico[indexH], &cr);		   

		   return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao pegar CR total");
	   }

	   ////////////////////////////////////////////
	   ////////////////////////////////////////////

	   else if( strcmp( ComandoTeste , GET_CR_PRD_CMD ) == 0 )
	   {
		   NumLidos = LER_LerParametros("isi", &indexH, &periodo, &HIS_CondRetEsperada);
		   if (NumLidos != 3) {
			   return TST_CondRetParm;
		   }

		   list = NULL;
		   LIST_CondRetObtido = createList(&list);

		   if (LIST_CondRetObtido != LIS_CondRetOK) {
			   return TST_CondRetErro;
		   }
		   
		   HIS_CondRetObtido = HIS_getCrDoPeriodo(pHistorico[indexH], periodo, &cr);		   

		   return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao pegar CR total");
	   }

	   ////////////////////////////////////////////
	   ////////////////////////////////////////////

	   else if( strcmp( ComandoTeste , GET_HIS_PRD_CMD ) == 0 )
	   {
		   NumLidos = LER_LerParametros("isi", &indexH, &periodo, &HIS_CondRetEsperada);
		   if (NumLidos != 3) {
			   return TST_CondRetParm;
		   }

		   list = NULL;
		   LIST_CondRetObtido = createList(&list);

		   if (LIST_CondRetObtido != LIS_CondRetOK) {
			   return TST_CondRetErro;
		   }
		   
		   HIS_CondRetObtido = HIS_getHistoricoDoPeriodo(pHistorico[indexH], periodo, list);		   

		   return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao pegar historico completo");
	   }

	   ////////////////////////////////////////////
	   ////////////////////////////////////////////

	   else if( strcmp( ComandoTeste , IMPRIME_HIST_CMD ) == 0 )
	   {
		   NumLidos = LER_LerParametros("ii", &indexH, &HIS_CondRetEsperada);
		   if (NumLidos != 2) {
			   return TST_CondRetParm;
		   }

		   list = NULL;
		   LIST_CondRetObtido = createList(&list);

		   if (LIST_CondRetObtido != LIS_CondRetOK) {
			   return TST_CondRetErro;
		   }
		   
		   HIS_CondRetObtido = HIS_imprimeHistorico(pHistorico[indexH], list);

		   return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao imprimir historico");
	   }
 }
/********** Fim do módulo de implementação: Módulo de teste específico **********/
