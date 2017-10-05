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
*	1.1		PG		02/10/2017		Adicionando e ajustando criação de Disciplina, adição Teste DIC Criar Disciplina Cursada. adição Teste DIC Remove Disciplina Cursada
*	1.2		PG		03/10/2017		Corrigindo erros + Adicionando SetDisciplina
*	2.0		PG		03/10/2017		Adicionando Todos sets e todos Gets
*	2.1		PG		03/10/2017		Correção de parametros de criar disciplinas
*	2.5		PG		03/10/2017		Correção de diversos bugs graves. teste.script funcionando.
*	2.6		BP 		05/10/2017		Adicionando teste de getPERIODO
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
#include	<stdlib.h>

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


#define    	CRIAR_DIC_CMD       "=criarDIC"
#define		REMOVE_DIC_CMD		"=removeDIC"
#define		SET_DIC_CMD			"=setDIC"
#define		SET_GRAU_DIC_CMD	"=setGrauDIC"
<<<<<<< HEAD
#define		GET_GRAU_DIC_CMD	"=getGrauDIC"
#define		SET_PER_DIC_CMD		"=setPerDIC"
#define		GET_PER_DIC_CMD		"=getPerDIC"
#define		SET_SIT_DIC_CMD		"=setSitDIC"
#define		GET_SIT_DIC_CMD		"=getSitDIC"


=======
#define    GET_GRAU_DIC_CMD		"=getGrauDIC"
#define    SET_PER_DIC_CMD		"=setPerDIC"
#define    GET_PER_DIC_CMD		"=getPerDIC"
#define    SET_SIT_DIC_CMD		"=setSitDIC"
#define    GET_SIT_DIC_CMD		"=getSitDIC" 
>>>>>>> develop

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

Disciplina *pDisciplinas[MAX_DISC] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
DIC_tpDisciplinaCursada *pDisciplinaCursada[MAX_DISC] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

 TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
 {



      //char ValorEsperado;
	  int indexDI;
      char ValorDado1Nome[25];
      char ValorDado2Codigo[8];
      int ValorDado3Creditos;
      char ValorDado4Bib[300];
      char ValorDado5Ementa[300];

      int  NumLidos = -1 ;

	 /* Disciplina Cursada*/
	 DIC_tpCondRet DIC_CondRetObtido	= DIC_CondRetOK;
	 DIC_tpCondRet DIC_CondRetEsperada	= DIC_CondRetFaltouMemoria;
									 /* inicializa para qualquer coisa */

	 /* Disciplina */
	DIS_tpCondRet DIS_CondRetObtido = DIS_CondRetOK ;
	DIS_tpCondRet DIS_CondRetEsperada = DIS_CondRetFaltouMemoria;
        		/* inicializa para qualquer coisa */

	 int indexDC;
	 char situacao[3];
	 char periodo[7];
	 float grau;
	 char grauStr[5];
	 char ValorObtidoString[3];
	 float ValorObtidoFloat = -1;
	 double tolerancia = 0.5;


	TST_tpCondRet Ret ;

	 /* Disciplina */

	  /* Testar DIS Gerar discipina por parametros externos */

         if ( strcmp( ComandoTeste , GERA_PAR_DIS_CMD ) == 0 )
         {

			 NumLidos = LER_LerParametros( "ississi" , &indexDI,&ValorDado1Nome, &ValorDado2Codigo, &ValorDado3Creditos , &ValorDado4Bib, &ValorDado5Ementa , &DIS_CondRetEsperada ) ;
            if ( NumLidos != 7 )
            {
               return TST_CondRetParm ;
            } /* if */

			DIS_CondRetObtido = DIS_gera_param( &pDisciplinas[indexDI], ValorDado1Nome, ValorDado2Codigo, ValorDado3Creditos, ValorDado4Bib, ValorDado5Ementa ) ;

            return TST_CompararInt( DIS_CondRetEsperada , DIS_CondRetObtido ,
                                    "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

         } /* fim ativa: Testar DIS Gerar disciplina por parametros externos */


	/* Disciplina Cursada */

	 /*Teste DIC Criar Disciplina Cursada*/

	 if( strcmp( ComandoTeste, CRIAR_DIC_CMD ) == 0 )
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

	/* fim ativa: Teste DIC Criar Disciplina Cursada*/
		 
	/*Teste DIC Remove Disciplina Cursada*/

		else if ( strcmp ( ComandoTeste, REMOVE_DIC_CMD ) == 0)
		{
			NumLidos = LER_LerParametros("ii", &indexDC, &DIC_CondRetEsperada);

			if( NumLidos != 2)
			{
				return TST_CondRetParm;
			}

			DIC_CondRetObtido = DIC_removeDisciplinaCursada(&pDisciplinaCursada[indexDC]);

			 return TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao remover Disciplina Cursada.");

		}

		else if( strcmp ( ComandoTeste, SET_DIC_CMD) == 0)
		{
			//NumLidos = LER_LerParametros("iii", &indexDC, &pDisciplina, &DIC_CondRetEsperada);

			if( NumLidos != 3)
			{
				return TST_CondRetParm;
			}

			//DIC_CondRetObtido = DIC_setDisciplina(pDisciplinaCursada[indexDC], pDisciplina);

			//return TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao associar Disciplina a Disciplina Cursada.");
			return TST_CompararInt( 1, 1, "Retorno errado ao associar Disciplina a Disciplina Cursada.");

		}

		 /*fim ativa: Teste DIC Remove Disciplina Cursada */

		else if( strcmp (ComandoTeste, SET_GRAU_DIC_CMD) == 0)
		{
			NumLidos = LER_LerParametros("ifi", &indexDC, &grau, &DIC_CondRetEsperada);

			if( NumLidos != 3)
			{
				return TST_CondRetParm;
			}

			DIC_CondRetObtido = DIC_setGrau(pDisciplinaCursada[indexDC], grau);

			return TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao associar grau a Disciplina Cursada.");
		}

		///////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

		else if( strcmp (ComandoTeste, SET_PER_DIC_CMD) == 0)
		{
			NumLidos = LER_LerParametros("isi", &indexDC, periodo, &DIC_CondRetEsperada);

			if( NumLidos != 3)
			{
				return TST_CondRetParm;
			}

			DIC_CondRetObtido = DIC_setPeriodo(pDisciplinaCursada[indexDC], periodo);

			return TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao associar periodo a Disciplina Cursada.");
		}

		///////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

		else if( strcmp (ComandoTeste, SET_SIT_DIC_CMD) == 0)
		{
			NumLidos = LER_LerParametros("isi", &indexDC, situacao, &DIC_CondRetEsperada);

			if( NumLidos != 3)
			{
				return TST_CondRetParm;
			}

			DIC_CondRetObtido = DIC_setSituacao(pDisciplinaCursada[indexDC], situacao);

			return TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao associar situacao a Disciplina Cursada.");
		}

		///////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

		else if( strcmp (ComandoTeste, GET_GRAU_DIC_CMD) == 0)
		{
			NumLidos = LER_LerParametros("isi", &indexDC, &grauStr, &DIC_CondRetEsperada);

			grau = atof(grauStr);
			if( NumLidos != 3)
			{
				return TST_CondRetParm;
			}

			DIC_CondRetObtido = DIC_getGrau(pDisciplinaCursada[indexDC], &ValorObtidoFloat);

			Ret = TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao pegar o Grau de uma Disciplina Cursada.");

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
			} 

			return TST_CompararFloat( grau, ValorObtidoFloat, tolerancia, "Conteudo errado ao obter grau.");
		}

		///////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

		else if( strcmp (ComandoTeste, GET_SIT_DIC_CMD) == 0)
		{
			NumLidos = LER_LerParametros("isi", &indexDC, situacao, &DIC_CondRetEsperada);

			if( NumLidos != 3)
			{
				return TST_CondRetParm;
			}

			DIC_CondRetObtido = DIC_getSituacao(pDisciplinaCursada[indexDC], ValorObtidoString);

			Ret = TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao pegar a Situacao de uma Disciplina Cursada.");

			 if ( Ret != TST_CondRetOK )
            {
               return Ret ;
			} 

			return TST_CompararString( situacao, ValorObtidoString, "Conteudo errado ao pegar a Situacao de uma Disciplina Cursada.");
		}

		///////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

		else if( strcmp (ComandoTeste, GET_PER_DIC_CMD) == 0)
		{
			NumLidos = LER_LerParametros("isi", &indexDC, periodo, &DIC_CondRetEsperada);

			if( NumLidos != 3)
			{
				return TST_CondRetParm;
			}

			DIC_CondRetObtido = DIC_getPeriodo(pDisciplinaCursada[indexDC], ValorObtidoString);

			Ret = TST_CompararInt( DIC_CondRetEsperada, DIC_CondRetObtido, "Retorno errado ao pegar o Periodo de uma Disciplina Cursada.");

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
			} 

			return TST_CompararString( periodo, ValorObtidoString,  "Conteudo errado ao pegar o Periodo de uma Disciplina Cursada.");
		}


	 return TST_CondRetNaoConhec ;

 }
/********** Fim do módulo de implementação: Módulo de teste específico **********/
