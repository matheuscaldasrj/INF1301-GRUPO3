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
*   1.7     GC		05/10/2017		Adicionando geraPar, geraDisc, getHistoricoCompleto, getHistoricoPeriodo, getCrTotal, getCrPeriodo e imprimeHistorico
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
#include	"DISCIPLINACURSADA.h"

//funcoes para criar disciplinas !!
#define GERA_PAR_DIS_CMD		"=gerapar"
#define GERA_DISC_CRIADA_CMD	"=geradisc"

/* Tabela dos nomes dos comandos de teste específicos */

#define	CRIA_HIST_CMD			"=criaHIS"
#define	REMOVE_HIST_CMD			"=removeHIS"
#define ADIC_DISC_HIS_CMD		"=adicDisc"
#define	GET_HIS_CMPT_CMD		"=getHisCompleto"
#define	GET_HIS_PRD_CMD			"=getHisPeriodo"
#define SALVA_HIST_ARQUIVO		"=salvaHistArquivo"
#define PRINT_HIST_PERIODO		"=printHistPeriodo"
#define PRINT_HIST_COMPLETO		"=printHistCompleto"
#define PRINT_HIST_SITUACAO     "=printHistSituacao"

#define DETURPA					"=deturpa"
#define VERIFICA				"=verifica"
#define MAX 30


Disciplina *pDisciplinas[MAX] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
DIC_tpDisciplinaCursada *pDisciplinaCursada[MAX] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

HIS_tpHistorico *pHistorico[MAX] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

 TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
 {
	 HIS_tpCondRet HIS_CondRetObtido = HIS_CondRetOK;
	 HIS_tpCondRet HIS_CondRetEsperada = HIS_CondRetOK;
											/* inicializa para qualquer coisa */

	 int i = 0;
	 int indexH, indexDI, indexDC, ValorDado3Creditos, DIS_CondRetEsperada, DIS_CondRetObtido, DIC_CondRetEsperada, DIC_CondRetObtido;
	 int  NumLidos = -1 ;
	 int LIST_CondRetObtido = -999;
	 char periodo[10], ValorDado1Nome[20], ValorDado2Codigo[20], ValorDado4Bib[20], ValorDado5Ementa[20], situacao[10], grauStr[10];
	 unsigned int matricula;
	 float cr, grau;
	 List* list;
	 int deturpacaoNumero;

	 TST_tpCondRet Ret;

	   if ( strcmp( ComandoTeste , GERA_PAR_DIS_CMD ) == 0 )
	   {

			 NumLidos = LER_LerParametros( "ississi" , &indexDI, &ValorDado1Nome, &ValorDado2Codigo, &ValorDado3Creditos , &ValorDado4Bib, &ValorDado5Ementa , &DIS_CondRetEsperada ) ;
            if ( NumLidos != 7 )
            {
               return TST_CondRetParm ;
            } /* if */

			DIS_CondRetObtido = DIS_gera_param( &pDisciplinas[indexDI], ValorDado1Nome, ValorDado2Codigo, ValorDado3Creditos, ValorDado4Bib, ValorDado5Ementa ) ;

            return TST_CompararInt( DIS_CondRetEsperada , DIS_CondRetObtido ,
                                    "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

       } /* fim ativa: Testar DIS Gerar disciplina por parametros externos */

	   else if( strcmp( ComandoTeste, GERA_DISC_CRIADA_CMD ) == 0 )
		 {

			 NumLidos = LER_LerParametros( "iisssi", &indexDC, &indexDI, situacao, periodo, grauStr, &DIC_CondRetEsperada);
		
			 grau = atof(grauStr);
			 if ( NumLidos != 6)
			 {
				 return TST_CondRetParm;
			 } /* if */

			 DIC_CondRetObtido = DIC_criarDisciplinaCursada (&pDisciplinaCursada[indexDC], pDisciplinas[indexDI], situacao, periodo, grau);

			 return TST_CompararInt ( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao criar Disciplina Cursada.");
		 }

	   else if ( strcmp( ComandoTeste , CRIA_HIST_CMD ) == 0 )
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
		   

		   HIS_CondRetObtido = HIS_getHistoricoCompleto(pHistorico[indexH], &list);		   

		   return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao pegar historico completo");
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

	   else if( strcmp( ComandoTeste , SALVA_HIST_ARQUIVO ) == 0 )
	   {
		   NumLidos = LER_LerParametros("iii", &indexH, &matricula, &HIS_CondRetEsperada);
		   if (NumLidos != 3) {
			   return TST_CondRetParm;
		   }

		   HIS_CondRetObtido = HIS_salvaHistoricoEmArquivo(&pHistorico[indexH], matricula);

		   return TST_CompararInt(HIS_CondRetEsperada , HIS_CondRetObtido, "Retorno errado ao salvar historico no arquivo");


	   }

	   else if( strcmp( ComandoTeste , ADIC_DISC_HIS_CMD ) == 0 )
	   {   
		   
		   NumLidos = LER_LerParametros("iisssi", &indexH, &indexDI, situacao, periodo, grauStr , &HIS_CondRetEsperada);

		   grau = atof(grauStr);
		   if (NumLidos != 6) {
			   return TST_CondRetParm;
		   }

		  HIS_CondRetObtido = HIS_adicionaDisciplina(pHistorico[indexH], pDisciplinas[indexDI], situacao, periodo, grau);
		   
		  return TST_CompararInt(HIS_CondRetObtido, HIS_CondRetEsperada, "Retorno errado ao adicionar disciplina ao historico");
	   }

	   else if( strcmp( ComandoTeste , PRINT_HIST_PERIODO ) == 0 )
	   {   
		   
		   NumLidos = LER_LerParametros("isi", &matricula, periodo, &HIS_CondRetEsperada);

		    if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } 

		   HIS_CondRetObtido = HIS_printHistoricoPeriodo(matricula,periodo);
		   
		  return TST_CompararInt(HIS_CondRetObtido, HIS_CondRetEsperada, "Retorno errado ao printar historico do periodo");
	   }



	   else if( strcmp( ComandoTeste , PRINT_HIST_SITUACAO ) == 0 )
	   {   
		   
		   NumLidos = LER_LerParametros("isi", &matricula, situacao, &HIS_CondRetEsperada);

		    if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } 

		   HIS_CondRetObtido = HIS_printHistoricoPorSituacao(matricula,situacao);
		   
		  return TST_CompararInt(HIS_CondRetObtido, HIS_CondRetEsperada, "Retorno errado ao printar historico por situacao");
	   }



	   	else if( strcmp( ComandoTeste , PRINT_HIST_COMPLETO ) == 0 )
	   {   
		   
		   NumLidos = LER_LerParametros("ii", &matricula, &HIS_CondRetEsperada);

			if ( NumLidos != 2 )
			{
				return TST_CondRetParm ;
			} 

		   HIS_CondRetObtido = HIS_printHistoricoCompleto(matricula);
		   
		  return TST_CompararInt(HIS_CondRetObtido, HIS_CondRetEsperada, "Retorno errado ao printar historico completo");
	   }
		else if( strcmp( ComandoTeste , DETURPA ) == 0 ) {   
		   
		   NumLidos = LER_LerParametros("iii", &indexH, &deturpacaoNumero, &HIS_CondRetEsperada);

			if ( NumLidos != 3 )
			{
				return TST_CondRetParm ;
			} 

		 return TST_CompararInt( HIS_CondRetOK , HIS_deturpaListaDeHistorico(pHistorico[indexH], deturpacaoNumero), "Erro ao tentar deturpar"  ) ;
		   
	   }
		else if( strcmp( ComandoTeste , VERIFICA ) == 0 ) {   
		   
		NumLidos = LER_LerParametros("ii", &indexH , &HIS_CondRetEsperada);

		if ( NumLidos != 2 )
		{
			return TST_CondRetParm ;
		} 
		
			

		return TST_CompararInt( HIS_CondRetEsperada , HIS_verificaHistorico(pHistorico[indexH]), "Verificacao indiciou erro"  ) ;
		   
	   }


 }
/********** Fim do módulo de implementação: Módulo de teste específico **********/
