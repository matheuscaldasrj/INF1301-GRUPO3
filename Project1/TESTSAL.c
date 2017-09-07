/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTSAL.C
*  Letras identificadoras:      TSAL
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio

*      Versão  Autor    Data     Observações
*       3.00   MC   05/09/2017  Criação do arquivo básico de testes
*		3.01   PG   07/09/2017  Adição do teste de reservaSala + ajustes no código geral
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo Sala.
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo sala:
*
*     =criarSala        - chama a função SAL_criarSala( )
*	  =reservaSala		- chama a função SAL_reservaSala( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "SALA.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_SAL_CMD       "=criarSala"
#define     GET_COD_CMD         "=getCodigo"
#define		RESERVA_SAL_CMD		"=reservaSala"

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
#define MAX_SALS 10


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      SAL_tpCondRet CondRetObtido   = SAL_CondRetOK ;
      SAL_tpCondRet CondRetEsperada = SAL_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;

      int  NumLidos = -1 ;

	  char codigo;
      int maximo;
      int eLaboratorio;
	  int index;
      SAL_tpSala  pSala[MAX_SALS];

      TST_tpCondRet Ret ;

      /* Testar SAL Criar sala */

         if ( strcmp( ComandoTeste , CRIAR_SAL_CMD ) == 0 )
         {

            //params
            //codigo, 1 char pra teste inicial. Vai ser cadeia de char
            //maxAlunos, int
            //eLaboratorio, int (0 ou 1)
            //matriz disponibilidade começa vazia
            
            NumLidos = LER_LerParametros( "isiii" ,
                                 &index, &codigo, &maximo, &eLaboratorio, &CondRetEsperada ) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */
         
            
            CondRetObtido = SAL_criarSala(pSala+index, &codigo, maximo, eLaboratorio);     


            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar sala." );

         } /* fim ativa: Testar SAL Criar sala */

      /* Testar SAL get codigo */

         else if ( strcmp( ComandoTeste , GET_COD_CMD ) == 0 )
         {
			 /*
			 TODO!!
            NumLidos = LER_LerParametros( "ci" ,
                               &ValorEsperado , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if 

            CondRetObtido = SAL_getCodigo( &ValorObtido ) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter valor corrente." );

            if ( Ret != TST_CondRetOK )
            {
               return Ret ;

            } /* if */

            return TST_CompararChar( ValorEsperado , ValorObtido ,
                                     "Conteúdo do nó está errado." ) ;

         } /* fim ativa: Testar SAL getCodigo */

      /* Testar SAL reserva sala */		
		 else if( strcmp( ComandoTeste , RESERVA_SAL_CMD ) == 0 ) 
		 {
			  NumLidos = LER_LerParametros( "iiiii" ,
                                 &index, &dia, &horaInicio, &horaFim, &CondRetEsperada);

			   if ( NumLidos != 5 )
            {
               return TST_CondRetParm ;
            } 

			  CondRetObtido = SAL_reservaSala(pSala[index], &dia, &horaInicio, &horaFim);    

			  return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao reservar sala." );

		 }
	 /* fim ativa: Testar SAL reserva sala */	

      /* Testar getCodigo */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TSAL Efetuar operações de teste específicas para sala */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

