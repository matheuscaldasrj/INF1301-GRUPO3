/***************************************************************************
*$MCI Módulo de implementação: Módulo de teste específico
*	Arquivo: TESTDIC.C
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
*	1.1	PG	02/10/2017	Adicionando e ajustando criação de Disciplina, adição Teste DIC Criar Disciplina Cursada. adição Teste DIC Remove Disciplina Cursada
*$ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo Disciplinas Cursadas.
*$EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo Disciplinas Cursadas:
*
*
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "DISCIPLINACURSADA.H"

#include    "disciplina.h"


/* Tabela dos nomes dos comandos de teste específicos */

/* Disciplinas */

#define     GERA_INP_DIS_CMD    "=gerainp"
#define     GERA_PAR_DIS_CMD    "=gerapar"

/* Disciplinas Cursadas */


#define    	CRIAR_DIC_CMD       	"=criarDIC"
#define		REMOVA_DIC_CMD		"=removeDIC"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TARV Efetuar operações de teste específicas para Sala
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     Sala sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/
#define MAX_DISC 15

Disciplina *pDisciplina[MAX_DISC] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
DIC_tagDisciplinaCursada *pDisciplinaCursada[MAX_DISC] =  = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

 TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
 {
	 /* Disciplina */

	DIS_tpCondRet CondRetObtido  ;
	DIS_tpCondRet CondRetEsperada  ;
        		/* inicializa para qualquer coisa */



      //char ValorEsperado;
      char ValorDado1Nome[25];
      char ValorDado2Codigo[8];
      int ValorDado3Creditos;
      char ValorDado4Bib[300];
      char ValorDado5Ementa[300];

      int  NumLidos = -1 ;
      char *ValorObtido1;
      char *ValorEsperado1;
      int ValorEsperado33;
      int ValorObtido33;
      int indexD;

	 /* Disciplina Cursada*/


	 DIC_tpCondRet CondRetObtido	= DIC_CondRetOK;
	 DIC_topCondRet	CondRetEsperada	= DIC_CondRetFaltouMemoria;
									 /* inicializa para qualquer coisa */


	 TST_tpCondRet Ret ;

	 /* Disciplina */

	 int indexDC;
	 int situacao;
	 char periodo
	 float grau;

	  /* Testar DIS Gerar discipina por parametros externos */

         if ( strcmp( ComandoTeste , GERA_PAR_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ississi" , indexD, &ValorDado1Nome, &ValorDado2Codigo, &ValorDado3Creditos , &ValorDado4Bib, &ValorDado5Ementa , &CondRetEsperada ) ;
            if ( NumLidos != 6 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_gera_param( &pDisciplina, ValorDado1Nome, ValorDado2Codigo, ValorDado3Creditos, ValorDado4Bib, ValorDado5Ementa ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

         } /* fim ativa: Testar DIS Gerar disciplina por parametros externos */


	/* Disciplina Cursada */

	 /*Teste DIC Criar Disciplina Cursada*/

	 if( strcmp( ComandoTeste, CRIAR_DIC_CMD ) == 0 )
	 {

		 NumLidos = LER_LerParametros( "issiisfi", &indexDC, &ValorDado1Nome, &ValorDado2Codigo, &ValorDado3Creditos, &situacao, &periodo, &grau, &CondRetEsperada);

		 if ( NumLidos != 8)
		 {
			 return TST_CondRetParm;
		 } /* if */

		 CondRetObtido = DIC_criarDisciplinaCursada (&pDisciplinaCursada[indexDC], ValorDado1Nome, ValorDado2Codigo, ValorDado3Creditos, situacao, periodo, grau);

		 return TST_CompararInt ( CondRetEsperada, CondRetObtido, "Retorno errado ao criar sala.");

	/* fim ativa: Teste DIC Criar Disciplina Cursada*/
		 
	/*Teste DIC Remove Disciplina Cursada*/

		else if ( strcmp ( ComandoTeste, REMOVE_DIC_CMD ) == 0)
		{
			NumLidos = LER_LerParametros("ii", &indexDC, CondRetEsperada);

			if( NumLidos != 2)
			{
				return TST_CondRetParm;
			}

			CondRetObtido = DIC_removeDisciplinaCursada(&pDisciplinaCursada[indexDC]);

			 return TST_CompararInt( CondRetEsperada, CondRetObtido, "Retorno errado ao remover Disciplina Cursada.");

		}

		 /*fim ativa: Teste DIC Remove Disciplina Cursada */


/********** Fim do módulo de implementação: Módulo de teste específico **********/
