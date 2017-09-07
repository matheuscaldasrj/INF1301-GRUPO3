/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTSAL.C
*  Letras identificadoras:      TSAL
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio

*      Vers�o  Autor    Data     Observa��es
*       3.00   MC   05/09/2017  Cria��o do arquivo b�sico de testes
*
*  $ED Descri��o do m�dulo
*     Este modulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo Sala.
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo sala:
*
*     =criarSala        - chama a fun��o SAL_criarSala( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "SALA.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_SAL_CMD       "=criarSala"
#define     GET_COD_CMD         "=getCodigo"


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TARV Efetuar opera��es de teste espec�ficas para Sala
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     Sala sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      SAL_tpCondRet CondRetObtido   = SAL_CondRetOK ;
      SAL_tpCondRet CondRetEsperada = SAL_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar SAL Criar sala */

         if ( strcmp( ComandoTeste , CRIAR_SAL_CMD ) == 0 )
         {

            //params
            //codigo, 1 char pra teste inicial. Vai ser cadeia de char
            //maxAlunos, int
            //eLaboratorio, int (0 ou 1)
            //matriz disponibilidade come�a vazia
            char codigo;
            int maximo;
            int eLaboratorio;

            NumLidos = LER_LerParametros( "siii" ,
                                 &codigo, &maximo, &eLaboratorio, &CondRetEsperada ) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */
         
            tp_SALA  *pSala = null;
            CondRetObtdo = SAL_criarSala(pSala, maximo,codigo,Edisponivel);
         
         
            CondRetObtido = ARV_ObterValorCorr( &ValorObtido ) ;
               

            CondRetObtido = SAL_criarSala( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar sala." );

         } /* fim ativa: Testar SAL Criar sala */

      /* Testar SAL get codigo */

         else if ( strcmp( ComandoTeste , GET_COD_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" ,
                               &ValorEsperado , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = SAL_getCodigo( &ValorObtido ) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter valor corrente." );

            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

            return TST_CompararChar( ValorEsperado , ValorObtido ,
                                     "Conte�do do n� est� errado." ) ;

         } /* fim ativa: Testar SAL getCodigo */

      /* Testar getCodigo */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TSAL Efetuar opera��es de teste espec�ficas para sala */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

