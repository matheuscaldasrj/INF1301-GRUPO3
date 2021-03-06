/***************************************************************************
*$MCI Módulo de implementação: Módulo de teste específico
*	Arquivo: TESTSAL.C
*	Proprietário: Grupo 3 INF1301 17.2
*	Projeto: Trabalho 1
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
*	1.16	LF	10/09/2017	Criação e padronização da documentação
*	1.15	MC	10/09/2017	Corrigindo bug do tamanho da variavel codigo
*	1.14	VA	08/09/2017	Adiconado   resetDisponibilidade
*	1.13	VA	08/09/2017	Adicionado getELabortorio
*	1.12	PG	08/09/2017  	Adicionando removeSala e ajustando demais funções.
*	1.11	MC   	08/09/2017  	Adicionada funcao de testes p/ setCodigo, getCodigo,setMaxAlunos, getMaxAlunos, getAndar,getPredio,getAndar, setELaboratorio
*	1.10	PG	07/09/2017  	Inicialização de variaveis, correção de bugs
*	1.01	PG   	07/09/2017  	Adição do teste de reservaSala + ajustes no código geral
*       1.00	MC   	05/09/2017  	Criação do arquivo básico de testes
*$ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo Sala.
*$EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo sala:
*
*	"=criarSala"		-chama a função SAL_criarSala(pSala, codigo, maxAlunos, eLaboratorio)
*	"=reservaSala"		-chama a função SAL_reservaSala (pSala, dia, horaInicio, horaFim)
*	"=printSala"		-chama a função SAL_printSala (pSala)
*	"=getCodigo"		-chama a função SAL_getCodigo(pSala, pcodigo)
*	"=liberaSala"		-chama a função SAL_liberaSala (pSala, dia, horaInicio, horaFim)
*	"=printDisponibilidade" -chama a função SAL_printDisponibilidade(SpSala)
*	"=removeSala"		-chama a função SAL_removeSala (pSala)
*	"=setMaxAlunos"		-chama a função SAL_setMaxAlunos (pSala, pMaxAlunos);
*	"=setCodigo"		-chama a função SAL_setCodigo(pSala, pCodigo)
*	"=setELaboratorio"	-chama a função SAL_setELaboratorio (pSala, eLaboratorio)
*	"=getMaxAlunos"		-chama a função SAL_getMaxAlunos (pSala, pMaxAlunos)
*	"=getAndar"		-chama a função SAL_getAndar (pSala, pAndar)
*	"=getPredio"		-chama a função SAL_getPredio (pSala, pPredio)
*	"=getNumero"		-chama a função SAL_getNumero (pSala, pNumero)
*	"=getELaboratorio"	-chama a função SAL_getELaboratorio (pSala, pELaboratorio)
*	"=resetDisponibilidade"	-chama a função SAL_resetDisponibilidade (pSala)
*	"=getHorarioNoDia"	-chama a função SAL_getHorarioNoDia(pSala, dia, horarioInicio, horarioFim)
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "SALA.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define    	CRIAR_SAL_CMD       	"=criarSala"
#define     	PRINT_SAL_CMD		"=printSala"
#define    	GET_COD_CMD         	"=getCodigo"
#define		RESERVA_SAL_CMD		"=reservaSala"
#define    	LIBERA_SAL_CMD    	"=liberaSala"
#define		PRINT_DISP_CMD		"=printDisponibilidade"
#define		REMOVE_SALA_CMD		"=removeSala"
#define		SET_MAX_ALUNOS_CMD	"=setMaxAlunos"
#define		SET_CODIGO_CMD		"=setCodigo"
#define		SET_E_LAB_CMD		"=setELaboratorio"
#define		GET_MAX_ALUNOS_CMD	"=getMaxAlunos"
#define		GET_ANDAR_CMD		"=getAndar"
#define		GET_PREDIO_CMD		"=getPredio"
#define		GET_NUMERO_CMD		"=getNumero"
#define		GET_E_LAB_CMD		"=getELaboratorio"
#define		RESET_DISP_CMD		"=resetDisponibilidade"
#define		GET_HORARIO_CMD		"=getHorarioNoDia"



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
#define MAX_SIZE_STRING 15

SAL_tpSala  *pSalas[MAX_SALS] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      SAL_tpCondRet CondRetObtido   = SAL_CondRetOK ;
      SAL_tpCondRet CondRetEsperada = SAL_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      	char ValorEsperado = '?'  ;
	char ValorObtido   = '!'  ;
	int ValorObtidoInt = -1;
	char ValorObtidoString[MAX_SIZE_STRING];
      	char ValorDado     = '\0' ;
	  
      	int  NumLidos = -1 ;
	
	char codigo[MAX_SIZE_STRING];
      	int maximoAlunos;
      	int eLaboratorio;
	int index;
	int dia;
	int horaInicio;
	int horaFim;
	int andar;
	char predio[MAX_SIZE_STRING];
	int numeroDaSala;
	int eLab;
	  

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

	/* Teste SAL print sala */

		 else if ( strcmp( ComandoTeste, PRINT_SAL_CMD) == 0)
		 {
			 NumLidos = LER_LerParametros("ii", &index, &CondRetEsperada);

			if( NumLidos != 2 )
			{
				 return TST_CondRetParm;
			 }

			 CondRetObtido = SAL_printSala(pSalas[index]);

			 return TST_CompararInt( CondRetEsperada, CondRetObtido, "Retorno errado ao imprimir sala.");
		}
	   /* fim ativa: Testar SAL print Sala */

	/* Teste SAL Remove sala */
		 else if ( strcmp( ComandoTeste, REMOVE_SALA_CMD) == 0)
		 {
			 NumLidos = LER_LerParametros("ii", &index, &CondRetEsperada);

			if( NumLidos != 2 )
			{
				 return TST_CondRetParm;
			 }

			 CondRetObtido = SAL_removeSala(&pSalas[index]);

			 return TST_CompararInt( CondRetEsperada, CondRetObtido, "Retorno errado ao remover sala.");
		}
	   /* fim ativa: Testar SAL Remove Sala */
	   
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

      /* Testar SAL reservaSala */		
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
		/* fim ativa: Testar SAL reservaSala */	

 		/* Testar SAL liberaSala */		
		 else if( strcmp( ComandoTeste , LIBERA_SAL_CMD ) == 0 ) 
		 {
			  NumLidos = LER_LerParametros( "iiiii" ,
                                 &index, &dia, &horaInicio, &horaFim, &CondRetEsperada);

			   if ( NumLidos != 5 )
				{
				 return TST_CondRetParm ;
				} 

			  CondRetObtido = SAL_liberaSala(pSalas[index], dia, horaInicio, horaFim);    

			  return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao liberar sala." );

		 }
		/* fim ativa: Testar SAL liberaSala */

		/* Teste SAL print disponibilidade */

		 else if ( strcmp( ComandoTeste, PRINT_DISP_CMD) == 0)
		 {
			 NumLidos = LER_LerParametros("ii", &index, &CondRetEsperada);

			if( NumLidos != 2 )
			{
				 return TST_CondRetParm;
			 }

			 CondRetObtido = SAL_printDisponibilidade(pSalas[index]);

			 return TST_CompararInt( CondRetEsperada, CondRetObtido, "Retorno errado ao imprimir matriz disponibilidade.");
		}
	    /* fim ativa: Testar SAL print Disponibilidade */

		/* Testar SAL setMaximoAlunos */		
		else if( strcmp( ComandoTeste , SET_MAX_ALUNOS_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "iii" ,
								&index, &maximoAlunos, &CondRetEsperada);

			if ( NumLidos != 3 )
			{
				return TST_CondRetParm ;
			} 

			CondRetObtido = SAL_setMaxAlunos(pSalas[index], maximoAlunos);    

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
								"Retorno errado ao setar maximo alunos da sala." );

		}
		/* fim ativa: Testar SAL setMaximoAlunos */

		 /* Testar SAL setCodigo */		
		else if( strcmp( ComandoTeste , SET_CODIGO_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "isi" ,
								&index, codigo, &CondRetEsperada);

			if ( NumLidos != 3 )
			{
				return TST_CondRetParm ;
			} 

			CondRetObtido = SAL_setCodigo(pSalas[index],codigo);    

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
								"Retorno errado ao setar codigo da sala." );

		}
		/* fim ativa: Testar SAL setCodigo */

		/* Testar SAL setELaboratorio */		
		else if( strcmp( ComandoTeste , SET_E_LAB_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "iii" ,
								&index, &eLab, &CondRetEsperada);

			if ( NumLidos != 3 )
			{
				return TST_CondRetParm ;
			} 

			CondRetObtido = SAL_setELaboratorio(pSalas[index], eLab);    

			return TST_CompararInt( CondRetEsperada , CondRetObtido ,
								"Retorno errado ao setar se a sala é ou não laboratorio." );

		}
		/* fim ativa: Testar SAL setELaboratorio */


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
                                     "Conteudo errado ao obter Maximo alunos de sala." ) ;

		}
		/* fim ativa: Testar SAL getMaximoAlunos */

			/* Testar SAL getAndar */		
		else if( strcmp( ComandoTeste , GET_ANDAR_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "iii" ,
                               &index, &andar , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

			CondRetObtido = SAL_getAndar(pSalas[index], &ValorObtidoInt);

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter andar de sala" );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } 

			return TST_CompararInt( andar,ValorObtidoInt,
                                     "Conteudo errado no andar de sala." ) ;

		}
		/* fim ativa: Testar SAL getAndar */

		/* Testar SAL getPredio */		
		else if( strcmp( ComandoTeste , GET_PREDIO_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "isi" ,
                               &index, predio , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

			CondRetObtido = SAL_getPredio(pSalas[index], ValorObtidoString);

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter predio de sala" );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } 

			return TST_CompararString( predio,ValorObtidoString,
                                     "Conteudo errado no predio de sala." ) ;

		}
		/* fim ativa: Testar SAL getPredio */
		/* Testar SAL getNumero */		
		else if( strcmp( ComandoTeste , GET_NUMERO_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "iii" ,
                               &index, &numeroDaSala , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

			CondRetObtido = SAL_getNumero(pSalas[index], &ValorObtidoInt);

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter numero de sala" );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } 

			return TST_CompararInt( numeroDaSala,ValorObtidoInt,
                                     "Conteudo errado no numero de sala." ) ;

		}
		/* fim ativa: Testar SAL getNumero */

		 /* Testar SAL getELaboratorio */		
		else if( strcmp( ComandoTeste , GET_E_LAB_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "iii" ,
                               &index, &eLaboratorio , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

			CondRetObtido = SAL_getELaboratorio(pSalas[index], &ValorObtidoInt);

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter se e laboratorio" );
            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } 

			return TST_CompararInt( eLaboratorio,ValorObtidoInt,
                                     "Conteudo errado ao verificar se e laboratorio." ) ;

		}
		/* fim ativa: Testar SAL getELaboratorio */

		/* Testar SAL resetDisponibilidade */		
		else if( strcmp( ComandoTeste , RESET_DISP_CMD ) == 0 ) 
		{
			NumLidos = LER_LerParametros( "ii" ,
                               &index, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            }

			CondRetObtido = SAL_resetDisponibilidade(pSalas[index]);

			return TST_CompararInt( CondRetEsperada, CondRetObtido,
                                     "Conteudo errado ao verificar se resetou a disponibilidade." ) ;

		}
		/* fim ativa: Testar SAL resetDisponibilidade */

		/* Testar SAL getHorarioNoDia */
		else if (strcmp(ComandoTeste, GET_HORARIO_CMD) == 0)
		{
			NumLidos = LER_LerParametros("iiiii", &index, &dia, &horaInicio, &horaFim, &CondRetEsperada);

			if (NumLidos != 5)
			{
				return TST_CondRetParm;
			}

			CondRetObtido = SAL_getHorarioNoDia(pSalas[index], dia, horaInicio, horaFim);

			return TST_CompararInt(CondRetEsperada, CondRetObtido, "Conteudo errado ao verificar o horario no dia.");
		}
		/* fim ativa: Testar SAL getHorarioNoDia */

      return TST_CondRetNaoConhec ;




   } /* Fim função: TSAL Efetuar operações de teste específicas para sala */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
