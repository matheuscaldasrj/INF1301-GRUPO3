#if ! defined( SALA_ )
#define SALA_
/***************************************************************************
*
*  Módulo de definição: Módulo árvore
* *
*  Letras identificadoras:      SAL
*
*  Autores: mc - Matheus Caldas
*           bp - Bruno Pedrazza
*  Historico de evolucaoo:
*     Vers‹o       Autor          Data            Observacoes
*      1.00         mc        30/08/2017   Inicio do desenvolvimento
*      1.10         bp        31/08/2017   Implementacao funcoes getNUmero, getPredio, getAndar	
*  $ED Descrição do módulo
*    Este módulo define a interface de Sala com seus métodos de criação
*	 gets, sets assim como define as condicoes de retorno SAL_tpCondRet
*
***************************************************************************/
 
#if defined( SALA_OWN )
   #define SALA_EXT
#else
   #define SALA_EXT extern
#endif


typedef enum {

    SAL_CondRetOK = 0 ,
        /* Executou correto */

    SAL_CondRetFaltouMemoria = 1 ,
        /* Erro ao tentar ciar sala */
			   
		SAL_CondRetRecebeuPonteiroNulo = 2 ,
				/* Recebeu ponteiro para sala nulo */
		SAL_CondRetErroEstrutura
				/* Recebeu estrutura com erro */


   } SAL_tpCondRet ;



/***********************************************************************
*
*  $FC Função: SAL Criar sala
*
*  $ED Descrição da função
*     Cria uma nova sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetFaltouMemoria
*
***********************************************************************/

   SAL_tpCondRet SAL_criarSala( Sala * sala );


/***********************************************************************
*
*  $FC Função: SAL seta codigo da sala
*
*  $ED Descrição da função
*     Seta o codigo recebido pelo parametro no código
*     da sala recebida
*
***********************************************************************/

   SAL_tpCondRet Sal_setCodigo(Sala * sala, int codigo);


/***********************************************************************
*
*  $FC Função: SAL get codigo da sala
*
*  $ED Descrição da função
*     Pega o codigo da sala recebida e armazena no conteudo
*     do ponteiro recebido como codigo
*
***********************************************************************/

  SAL_tpCondRet Sal_getCodigo(Sala * sala, char *codigo);

/***********************************************************************
*
*  $FC Função: SAL get numero da sala
*
*  $ED Descrição da função
*     Pega o codigo da sala recebida e retorna o inteiro correspondente
*     ao numero da sala
***********************************************************************/

int Sal_getNumero (Sala *sala);

/***********************************************************************
*
*  $FC Função: SAL get predio da sala
*
*  $ED Descrição da função
*     Pega o codigo da sala recebida e retorna uma string com o predio
*     que a sala e localizada
***********************************************************************/

int Sal_getPredio (Sala *sala);

/***********************************************************************
*
*  $FC Função: SAL get andar da sala
*
*  $ED Descrição da função
*     Pega o codigo da sala recebida e retorna o inteiro correspondente
*     ao andar da sala
***********************************************************************/

int Sal_getAndar (Sala *sala);



#undef SALA_EXT

/********** Fim do módulo de definição: Módulo Sala **********/

#else
#endif
