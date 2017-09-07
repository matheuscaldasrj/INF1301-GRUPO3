#if ! defined( SALA_ )
#define SALA_


/***************************************************************************
 *  Modulo de definição: Modulo Sala
 *
 *  Letras identificadoras:      SAL
 *
 *  Autores: mc - Matheus Caldas
 *       bp - Bruno Pedrazza
 *       pg - Pedro Gomes
 *  Historico de evolucao:
 *     Versao       Autor          Data            Observacoes
 *      1.0.0         mc        30/08/2017   Inicio do desenvolvimento
 *      1.1.0         bp        31/08/2017   Implementacao funcoes getNumero, getPredio, getAndar
 *      1.2.0         pg        31/08/2017   Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
 *      1.2.1         bp        02/09/2017   Mudanca nas condicoes de retorno funcoes getNumero, getPredio, getAndar, setCodigo
 *      1.2.2         mc        02/09/2017   Implementacao funcoes setQtdComputadores e getQtdComputadores
 *      1.2.3         bp        03/09/2017   Implementacao funcoes getELaboratorio e setELaboratorio
 *      1.2.4	      pg        04/09/2017	Implementação de SAL_CondRetReservada
 *      1.2.6		  gp		05/09/2017		Implementação de SAL
 *		1.2.7		  mc        07/09/2017	  Mudança na estrutura básica da criaSala, agora recebendo os parametros.
 *	1.2.9	      pg	    07/09/2017	     Adicionando removeSala
 *  Descrição do módulo
 *     Este módulo implementa um conjunto de funcoes para criar e manipular
 *     atributos do módulo Sala.
 *
 *
 *
 ***************************************************************************/

#if defined( SALA_OWN )
   #define SALA_EXT
#else
   #define SALA_EXT extern
#endif

#define HORARIOS 16
#define DIAS 6
#define tamCodigoSala 6
#define ajusteHora 7
#define salaReservada 1
#define salaLivre 0
#define reservaFalhou 0
#define inicioDiaLetivo 7
#define fimDiaLetivo 23
#define inicioSemanaLetiva 0
#define fimSemanaLetiva 5


typedef struct SAL_tagSala SAL_tpSala;

typedef enum {

  SAL_CondRetOK = 0 ,
      /* Executou correto */

  SAL_CondRetFaltouMemoria = 1 ,
      /* Erro ao tentar ciar sala */

  SAL_CondRetRecebeuPonteiroNulo = 2 ,
		/* Recebeu ponteiro para sala nulo */

  SAL_CondRetErroEstrutura = 3 ,
		/* Recebeu estrutura com erro */

  SAL_CondRetParamInvalido = 4 ,
    /* Erro no parametro recebido em funcao set */

  SAL_CondRetReservada = 5
	/* Enviada quando uma sala ja esta reservada */

} SAL_tpCondRet ;

typedef enum {
	SEGUNDA,
	TERCA,
	QUARTA,
	QUINTA,
	SEXTA,
	SABADO
} diasSemana;


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

SAL_tpCondRet SAL_criarSala(SAL_tpSala * pSala, char *codigo, int maxAlunos, int eLaboratorio);

/**************************************************************************
 *                                                                        *
 * Funcao: SAL remove sala	                                          *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *    SAL_CondRetOK  							  *
 *									  *
 **************************************************************************/

SAL_tpCondRet Sal_removeSala (Sal_tpSala *pSala);

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
*    SAL_CondRetRecebeuPonteiroNulo
*    SAL_CondRetParamInvalido
***********************************************************************/

SAL_tpCondRet SAL_setCodigo(SAL_tpSala *pSala, char *codigo);


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
*    SAL_CondRetRecebeuPonteiroNulo
***********************************************************************/

SAL_tpCondRet SAL_getCodigo(SAL_tpSala * pSala, char *codigo);

/***********************************************************************
*
*  $FC Função: SAL set max de alunos que a sala comporta
*
*  $ED Descrição da função
*     Seta na estrutura a qtd max de alunos
*
*  $FV Valor retornado
*    SAL_CondRetOK                                                      
*    SAL_CondRetErroEstrutura
*    SAL_CondRetRecebeuPonteiroNulo
***********************************************************************/

SAL_tpCondRet SAL_setMaxAlunos (SAL_tpSala * pSala, int maxAlunos);

/***********************************************************************
*
*  $FC Função: SAL get maxAlunos
*
*  $ED Descrição da função
*     Pega o inteiro maxAlunos recebido e armazena no conteudo
*     do ponteiro recebido 
*
*  $FV Valor retornado
*    SAL_CondRetOK                                                      
*    SAL_CondRetErroEstrutura
*    SAL_CondRetRecebeuPonteiroNulo
***********************************************************************/

SAL_tpCondRet SAL_getMaxAlunos (SAL_tpSala * pSala, int *maxAlunos);

/***********************************************************************
*
*  $FC Função: SAL set se é laboratorio (1 se sim, 0 se não)
*
*  $ED Descrição da função
*     Seta se a sala é laboratório
*
*  $FV Valor retornado
*    SAL_CondRetOK                                                      
*    SAL_CondRetErroEstrutura
*    SAL_CondRetRecebeuPonteiroNulo
***********************************************************************/

SAL_tpCondRet SAL_setELaboratorio (SAL_tpSala * pSala, int eLaboratorio);

/***********************************************************************
*
*  $FC Função: SAL get se é laboratorio (1 se sim, 0 se não)
*
*  $ED Descrição da função
*     Pega se a sala é laboratório
*
*  $FV Valor retornado
*    SAL_CondRetOK                                                      
*    SAL_CondRetErroEstrutura
*    SAL_CondRetRecebeuPonteiroNulo
***********************************************************************/

SAL_tpCondRet SAL_getELaboratorio (SAL_tpSala * pSala, int *eLaboratorio);

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
*     SAL_CondRetErroEstrutura
*
***********************************************************************/

SAL_tpCondRet SAL_getNumero (SAL_tpSala *pSala, int *numero);

/***********************************************************************
*
*  $FC Função: SAL_getPredio
*
*  $ED Descrição da função
*     Pega predio da sala.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetErroEstrutura
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
*     SAL_CondRetErroEstrutura 
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

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim, int *pSucesso);


/***********************************************************************
*
*  $FC Função: SAL_resetDisponibilidade
*
*  $ED Descrição da função
*     Reseta a matriz disponibilidade (todos horarios disponiveis)
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetRecebeuPonteiroNulo
*
*     
*
***********************************************************************/

SAL_tpCondRet SAL_resetDisponibilidade (SAL_tpSala *pSala);

/***********************************************************************
*
*  $FC Função: SAL_pegaDisponibilidade
*
*  $ED Descrição da função
*     Passa o valor da matriz disponibilidade (todos os horários disponiveis)
*     para uma matriz passada como argumento.
*
*  $FV Valor retornado
*     SAL_CondRetOK
*     SAL_CondRetRecebeuPonteiroNulo
*
*
*
***********************************************************************/

SAL_tpCondRet SAL_getDisponibilidade(SAL_tpSala *pSala, int disponibilidade[16][6]);

/*
	Função SAL_getHorarioNoDia

	Retorno:
	
	SAL_tpCondRet, onde:

	- SAL_CondRetRecebeuPonteiroNulo, se a sala recebida for nula
	- SAL_CondRetParamInvalido, se:
	  
	  1. O horário de início for maior ou igual ao horário de fim;
	  2. Se algum dos horários não estiver compreendido no período de 7 a 22 horas
	     durante o qual as aulas ocorrem;
 
	- SAL_CondRetOK, se a função for concluída com sucesso

	Parâmetros:

	- SAL_tpSala: ponteiro para a sala desejada
	- dia: valor inteiro entre 0 e 5 (ambos inclusive) representando um dos dias da semana
	  de segunda a sábado (0 = segunda, 1 = terça, ..., 5 = sábado)
	- horarioInicio: valor entre 7 e 22 representando o horário de início do período a ser
	  verificado
	- horarioFim: valor entre 7 e 22 representando o horário de fim do período a ser verificado
	- estaDisponivel: ponteiro para uma variável inteira onde será armazenado 1 se o intervalo
	  selecionado estiver disponível, 0 se não estiver.

 */

SAL_tpCondRet SAL_getHorarioNoDia(SAL_tpSala *pSala, diasSemana dia, int horarioInicio, int horarioFim, int* estaDisponivel);

#undef SALA_EXT

/********** Fim do módulo de definição: Módulo Sala **********/

#else
#endif
