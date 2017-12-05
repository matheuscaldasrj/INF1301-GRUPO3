/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              testelista.C
*  Letras identificadoras:      TLIS
*
*  Nome da base de software:    teste automatizado para lista
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Matheus Rodrigues de Oliveira Leal - mrol
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   mrol   27/09/2017 Início do desenvolvimento
*       2.00   mrol   30/09/2017 Reestruturação de código
*	3.00   mrol   04/10/2017 Atualização da documentação
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo lista. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo lista:
*
*     "=geralist" <Int>
*			-Criar lista
*     "=pushb" <Int>
*                      - Insere um elemento no final da lista
*     "=pushf"  <Int>
*                      - Insere um elemento no começo da lista
*     "=sizelist" <Int> <Int>
*                      - Obtem tamanho da lista
*     "=pegaval" <Int>
*                      -  Pega valor do cursor
*     "=nextno" <Int>
*			-Atualiza o cursor para o proximo no
*     "=prevno" <Int>
*                      - Atualiza o cursor para o no anterior
*     "=popb"  <Int>
*                      - Retorna a referencia para o valor do ultimo no, e retira o no da lista
*     "=popf" <Int>
*                      - Retorna a referencia para o valor do começo no, e retira o no da lista
*     "=firstlist" <Int>
*                      -  Atualiza para o primeiro no da lista
*     "=clearlist" <Int>
*                      - Limpa uma lista
*     "=dellist" <Int>
*                      - Deleta uma lista
*
***************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include    "tst_espc.h"
#include    "generico.h"
#include    "lerparm.h"
#include    "listas.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     GERA_LIST    "=geralist"
#define     PUSH_BACK    "=pushb"
#define     PUSH_FRONT   "=pushf"
#define     POP_BACK     "=popb"
#define     POP_FRONT    "=popf"
#define     SIZE_LIST    "=sizelist"
#define     NEXT_NO      "=nextno"
#define     PREV_NO      "=prevno"
#define     PEGA_VALOR   "=pegaval"
#define     DEL_LIST     "=dellist"
#define     CLEAR_LIST   "=clearlist"
#define     FIRST_LIST   "=firstlist"

#define DETURPA					"=deturpa"
#define VERIFICA				"=verifica"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS Efetuar operações de teste específicas para lista
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     lista sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver LIS_tpCondRet definido em lista.h
*
***********************************************************************/

List *lst = NULL;

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      LIS_tpCondRet CondRetObtido  ;
      LIS_tpCondRet CondRetEsperada  ;

      /* inicializa para qualquer coisa */
      int ValorEsperado33 = 0;
      void *structX = NULL;
	  int NumLidos = -1;
	  int a[3] = {10,120,570};
      TST_tpCondRet Ret;
	  int deturpacaoNumero = -1;
      /* Testar LST Gerar lista */

         if ( strcmp( ComandoTeste , GERA_LIST ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,&CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = createList( &lst ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao gerar lista.\n" );

         } /* fim ativa: Testar  LST Gerar lista */

       /* Testar inserir um elemento no final da lista */

         else if ( strcmp( ComandoTeste , PUSH_BACK ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = push_back( lst, &(a[1]) ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir um elemento no final da lista." );

         } /* fim ativa: Testar inserir um elemento no final da lista */


      /* Testar Testar inserir um elemento no comeco da listas */

         else if ( strcmp( ComandoTeste , PUSH_FRONT ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = push_front( lst, &(a[0]) ) ;

			return TST_CompararInt ( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir um elemento no inicio da lista.\n" );

         } /* fim ativa: Testar inserir um elemento no comeco da lista */

      /* Testar atualizar o parâmetro val, referenciado, para o último elemento da lista, que é removido da mesma */

         else if ( strcmp( ComandoTeste , POP_BACK ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = pop_back(lst, &structX);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar retornar a referência para o valor do último nó, e retira o nó da lista." );

         } /* fim ativa: Testar atualizar o parâmetro val, referenciado, para o último elemento da lista, que é removido da mesma  */

         /* Testar atualizar o parâmetro val, referenciado, para o primeiro elemento da lista, que é removido da mesma */

            else if ( strcmp( ComandoTeste , POP_FRONT ) == 0 )
            {

               NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
               if ( NumLidos != 1 )
               {
                  return TST_CondRetParm ;
               } /* if */

               CondRetObtido = pop_front(lst, &structX);

               return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                       "Retorno errado ao tentar retornar a referência para o valor do último nó, e retira o nó da lista." );

            } /* fim ativa: Testar atualizar o parâmetro val, referenciado, para o primeiro elemento da lista, que é removido da mesma */

      /* Testar obter tamanho da lista*/

         else if ( strcmp( ComandoTeste , SIZE_LIST ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii", &ValorEsperado33,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = list_size( lst, &ValorEsperado33 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter tamanho da lista.\n" );

         } /* fim ativa: Testar obter tamanho da lista */
	/* Testar atualizar o cursor para o próximo nó */

         else if ( strcmp( ComandoTeste , NEXT_NO ) == 0 )
         {

            NumLidos = LER_LerParametros( "i", &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = next( lst ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar atualizar o cursor para o próximo nó.\n" );

         } /* fim ativa: Testar atualizar o cursor para o próximo nó */
	       /* Testar atualizar o cursor para o nó anterior */

         else if ( strcmp( ComandoTeste , PREV_NO ) == 0 )
         {

            NumLidos = LER_LerParametros( "i", &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = prev( lst ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar atualizar o cursor para o nó anterior.\n" );

         } /* fim ativa: Testar atualizar o cursor para o nó anterior */

		    /* Testar atualizar o parâmetro val para o valor no nó cursor*/
   else if ( strcmp( ComandoTeste , PEGA_VALOR ) == 0 )
   {

      NumLidos = LER_LerParametros( "i", &CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = get_val_cursor(lst, &structX) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao tentar atualizar o cursor para o próximo nó.\n" );

   } /* fim ativa: Testar atualizar o parâmetro val para o valor no nó cursor*/

   /* Testar limpar uma lista criada para zero nós*/

   else if ( strcmp( ComandoTeste , CLEAR_LIST ) == 0 )
   {

      NumLidos = LER_LerParametros( "i", &CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = clear(lst) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao tentar atualizar o cursor para o próximo nó.\n" );

   } /* fim ativa: Testar limpar uma lista criada para zero nós*/

   /*Testar atualizar para o primeiro nó da lista */

   else if ( strcmp( ComandoTeste , FIRST_LIST ) == 0 )
   {

      NumLidos = LER_LerParametros( "i", &CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = first(lst) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao tentar atualizar o cursor para o próximo nó.\n" );

   } /* fim ativa: Testar atualizar para o primeiro nó da lista*/

   /* Testar deletar uma lista já criada */

   else if ( strcmp( ComandoTeste , DEL_LIST ) == 0 )
   {

      NumLidos = LER_LerParametros( "i", &CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = del(lst) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao tentar atualizar o cursor para o próximo nó.\n" );

   } /* fim ativa: Testar deletar uma lista já criada */

   	else if( strcmp( ComandoTeste , DETURPA ) == 0 ) {   
		   
		   NumLidos = LER_LerParametros("ii", &deturpacaoNumero, &CondRetEsperada);

			if ( NumLidos != 2 )
			{
				return TST_CondRetParm ;
			} 

			return TST_CompararInt( CondRetEsperada , LIS_deturpaLista(&lst, deturpacaoNumero), "Erro ao tentar deturpar"  ) ;
		   
	   }
	else if( strcmp( ComandoTeste , VERIFICA ) == 0 ) {   
		   
			NumLidos = LER_LerParametros("i", &CondRetEsperada);

			if ( NumLidos != 1 )
			{
				return TST_CondRetParm ;
			} 
					
			return TST_CompararInt( CondRetEsperada , LIS_verificaLista(lst) , "Verificacao indiciou erro"  ) ;
		   
	}


      return TST_CondRetNaoConhec ;

   } /* Fim função: TLIS Efetuar operações de teste específicas para lista */
/********** Fim do módulo de implementação: Módulo de teste específico **********/
