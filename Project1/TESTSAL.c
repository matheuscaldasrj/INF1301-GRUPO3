/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTSAL.C
*  Letras identificadoras:      TSAL
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*      Versão  Autor    Data     Observações
*       1.00   MC   05/09/2017  Criação do arquivo básico de testes
*		1.01   PG   07/09/2017  Adição do teste de reservaSala + ajustes no código geral
*		1.10   PG	07/09/2017  Inicialização de variaveis, correção de bugs
*		1.11   MC   08/09/2017  Adicionada funcao de testes p/ getCodigo e setMaxAlunos
*		1.12   PG	08/09/2017  Adicionando removeSala e ajustando demais funções.
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

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "SALA.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_SAL_CMD       "=criarSala"
#define     GET_COD_CMD         "=getCodigo"
#define		RESERVA_SAL_CMD		"=reservaSala"
#define		REMOVE_SALA_CMD		"=removeSala"
#define		SET_MAX_ALUNOS_CMD	"=setMaxAlunos"
#define		GET_MAX_ALUNOS_CMD	"=getMaxAlunos"

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
#define MAX_SALS 3
SAL_tpSala  *pSalas[MAX_SALS] = {NULL, NULL, NULL};

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      SAL_tpCondRet CondRetObtido   = SAL_CondRetOK ;
      SAL_tpCondRet CondRetEsperada = SAL_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
	  int ValorObtidoInt = -1;
	  char ValorObtidoString[tamCodigoSala];
      char ValorDado     = '\0' ;
	  

      int  NumLidos = -1 ;

	  char codigo[tamCodigoSala];
      int maximoAlunos;
      int eLaboratorio;
	  int index;
	  int dia;
	  int horaInicio;
	  int horaFim;
	  

      TST_tpCondRet Ret ;

      /* Teste SAL Criar sala */

         if ( strcmp( ComandoTeste , CRIAR_SAL_CMD ) == 0 )
         {
           
            NumLidos = LER_LerParametros( "isiii" ,
                                 &index, codigo, &maximoAlunos, &eLaboratorio, &CondRetEsperada ) ;
            if ( NumLidos != 5 )
            {
               return TST_CondRetParm ;
            } /* if */
         
            
            CondRetObtido = SAL_criarSala(&pSalas[index], codigo, maximoAlunos, eLaboratorio);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar sala." );

         } /* fim ativa: Testar SAL Criar sala */

		/* Teste SAL Criar sala */
		 else if ( strcmp( ComandoTeste, REMOVE_SALA_CMD) == 0)
		 {
			 NumLidos = LER_LerParametros("ii", &index, &CondRetEsperada);

			if( NumLidos != 2 )
			{
				 return TST_CondRetParm;
			 }

			 CondRetObtido = SAL_removeSala(pSalas[index]);

			 return TST_CompararInt( CondRetEsperada, CondRetObtido, "Retorno errado ao remover sala.");
		}
	   /* fim ativa: Testar SAL setMaxAlunos */
	   
      /* Testar SAL get codigo */

         else if ( strcmp( ComandoTeste , GET_COD_CMD ) == 0 )
         {
			 
			
            NumLidos = LER_LerParametros( "isi" ,
                               &index, codigo , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

			CondRetObtido = SAL_getCodigo(pSalas[index], ValorObtidoString);

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter o codigo de Sala" );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } 

			return TST_CompararString( codigo , ValorObtidoString ,
                                     "Conteudo ao obter get de sala errado." ) ;

         } 
	  /* fim ativa: Testar SAL getCodigo */

      /* Testar SAL reserva sala */		
		 else if( strcmp( ComandoTeste , RESERVA_SAL_CMD ) == 0 ) 
		 {
			  NumLidos = LER_LerParametros( "iiiii" ,
                                 &index, &dia, &horaInicio, &horaFim, &CondRetEsperada);

			   if ( NumLidos != 5 )
				{
				 return TST_CondRetParm ;
				} 

			  CondRetObtido = SAL_reservaSala(pSalas[index], dia, horaInicio, horaFim);    

			  return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao reservar sala." );

		 }
		/* fim ativa: Testar SAL reserva sala */	

		/* Testar SAL setMaximoAlunos */		
		else if( strcmp( ComandoTeste , SET_MAX_ALUNOS_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "iii" ,
								&index, &maximoAlunos, &CondRetEsperada);

			if ( NumLidos != 3 )
			{
				return TST_CondRetParm ;
			} 

			CondRetObtido = SAL_setMaxAlunos(pSalas[index],maximoAlunos);    

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
								"Retorno errado ao setar maximo alunos." );

		}
		/* fim ativa: Testar SAL setMaximoAlunos */

		/* Testar SAL getMaximoAlunos */		
		else if( strcmp( ComandoTeste , GET_MAX_ALUNOS_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "iii" ,
                               &index, &maximoAlunos , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

			CondRetObtido = SAL_getMaxAlunos(pSalas[index], &ValorObtidoInt);

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter o maximo de alunos da Sala" );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } 

			return TST_CompararInt( maximoAlunos,ValorObtidoInt,
                                     "Conteudo errado ao obter get Maximo alunos de sala errado." ) ;

		}
		/* fim ativa: Testar SAL getMaximoAlunos */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TSAL Efetuar operações de teste específicas para sala */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
