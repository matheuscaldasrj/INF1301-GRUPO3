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
*      1.10         bp        31/08/2017   Adicionada funcoes getNUmero, getPredio, getAndar	
*      1.11         mc        02/09/2017   Adiconada funcoes setQtdComputadores e getQtdComputadores e SAL_CondRetParamSetInvalido

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

  SAL_CondRetErroEstrutura = 3 ,
		/* Recebeu estrutura com erro */

  SAL_CondRetPredioNaoExiste = 4 ,
      /* O predio não existe */

  SAL_CondRetErroCodSala = 5 ,
      /* Erro no código da sala */

  SAL_CondRetParamSetInvalido = 6
    /* Erro no parametro recebido em funcao set */

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

SAL_tpCondRet SAL_criarSala(SAL_tpSala * pSala);


/***********************************************************************
*
*  $FC Função: SAL seta codigo da sala
*
*  $ED Descrição da função
*     Seta o codigo recebido pelo parametro no código
*     da sala recebida
*
*  $FV Valor retornado
*    SAL_CondRetOK                                                       
*    SAL_CondRetErroEstrutura                                            
*    SAL_CondRetPredioNaoExiste
* 
***********************************************************************/

SAL_tpCondRet SAL_setCodigo(SAL_tpSala * pSala, char *codigo);


/***********************************************************************
*
*  $FC Função: SAL get codigo da sala
*
*  $ED Descrição da função
*     Pega o codigo da sala recebida e armazena no conteudo
*     do ponteiro recebido como codigo
*
*  $FV Valor retornado
*    SAL_CondRetOK                                                      
*    SAL_CondRetErroEstrutura
*
***********************************************************************/

SAL_tpCondRet SAL_getCodigo(SAL_tpSala * pSala, char *codigo);

/***********************************************************************
*
*  $FC Função: SAL_getNumero
*
*  $ED Descrição da função
*     Pega numero da sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetRecebeuPonteiroNulo 
*     SAL_CondRetErroCodSala
*
***********************************************************************/

SAL_tpContRet SAL_getNumero (SAL_tpSala *pSala, int *numero);

/***********************************************************************
*
*  $FC Função: SAL_getPredio
*
*  $ED Descrição da função
*     Pega predio da sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetPredioNaoExiste
*     SAL_CondRetRecebeuPonteiroNulo
*
***********************************************************************/

SAL_tpCondRet SAL_getPredio (SAL_tpSala * pSala, char *predio);

/***********************************************************************
*
*  $FC Função: SAL_getAndar
*
*  $ED Descrição da função
*     Pega andar da sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetErroCodSala
*     SAL_CondRetRecebeuPonteiroNulo
***********************************************************************/

SAL_tpCondRet SAL_getAndar (SAL_tpSala *pSala, int *andar);

/***********************************************************************
*
*  $FC Função: SAL_setQtdComputadores
*
*  $ED Descrição da função
*     Seta numero max de computadores/alunos da sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetRecebeuPonteiroNulo
*     SAL_CondRetErroEstrutura
*
***********************************************************************/

SAL_tpCondRet SAL_setQtdComputadores (SAL_tpSala * pSala, int qtdComputadores);

/***********************************************************************
*
*  $FC Função: SAL_getQtdComputadores
*
*  $ED Descrição da função
*     Retorna pelo ponteiro qtdComputadores a capacidade
*     de computadores/alunos na sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetRecebeuPonteiroNulo
*     SAL_CondRetErroEstrutura
*
***********************************************************************/

SAL_tpCondRet SAL_getQtdComputadores (SAL_tpSala * pSala, int *qtdComputadores);


/***********************************************************************
*
*  $FC Função: SAL_reservaSala
*
*  $ED Descrição da função
*     Rserva horario na sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetRecebeuPonteiroNulo
*
*     
*
***********************************************************************/

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim);

#undef SALA_EXT

/********** Fim do módulo de definição: Módulo Sala **********/

#else
#endif
