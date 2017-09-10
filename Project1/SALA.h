#if ! defined( SALA_ )
#define SALA_


/***************************************************************************
 *  Modulo de definição: Modulo Sala
 *
 *  Letras identificadoras:      SAL
 *
 *  Autores: mc - Matheus Caldas
 *	     bp - Bruno Pedrazza
 *	     pg - Pedro Gomes
 *	     va - Vinícius Arcoverde
 *	     lf - Leon França
 *	     gc - Gabriel Costa
 *  Historico de evolucao:
 *     Versao       Autor          Data            Observacoes
 *	1.3.0	      mc	10/09/2017	Remove sala agora usa ponteiro de ponteiro
 *	1.2.7	      pg	07/09/2017	Adicionando removeSala, Corrigindo parametros reservaSala
 *	1.2.6	      mc        07/09/2017	Mudança na estrutura básica da criaSala, agora recebendo os parametros.
 *      1.2.5	      gp	05/09/2017	Implementação de SAL
 *      1.2.4	      pg        04/09/2017	Implementação de SAL_CondRetReservada
 *      1.2.3         bp        03/09/2017   	Implementacao funcoes getELaboratorio e setELaboratorio
 *      1.2.2         mc        02/09/2017   	Implementacao funcoes setQtdComputadores e getQtdComputadores
 *      1.2.1         bp        02/09/2017   	Mudanca nas condicoes de retorno funcoes getNumero, getPredio, getAndar, setCodigo
 *      1.2.0         pg        31/08/2017   	Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
 *      1.1.0         bp        31/08/2017   	Implementacao funcoes getNumero, getPredio, getAndar
 *      1.0.0         mc        30/08/2017   	Inicio do desenvolvimento
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
#define tamPredio 10
#define tamCodigoSala 6
#define ajusteHora 7
#define salaReservada 1
#define salaLiberada 0
#define salaLivre 0
#define inicioDiaLetivo 7
#define fimDiaLetivo 23
#define inicioSemanaLetiva 0
#define fimSemanaLetiva 5

/***** Declarações exportadas pelo módulo *****/

/*Tipo estruturado tpSala é constituido por quatro (4) tipos de dados diferentes, criados para identificação, categorização
e manipulação dos horários das salas de aula do curso de informática da PUC-Rio, são eles o Código da sala (exs: L222, F765, K1001), 
a Capacidade Máxima de alunos da mesma (exs: 42, 25, 34), um parametro categorizador entre salas laboratórios e não laboratórios
e por fim uma matriz de disponibilidade que indica em que dia e horário a sala está sendo ultilizada ou não por uma turma de alunos*/
typedef struct SAL_tagSala SAL_tpSala;

/***********************************************************************
*
*  $TC Tipo de dados: SAL Condicoes de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da Sala
*
***********************************************************************/

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

  SAL_CondRetErroAoReservar = 5 ,
	  /* Enviada quando uma sala ja esta reservada */

  SAL_CondRetErroAoLiberar = 6 
    /* Erro ao tentar liberar sala */

} SAL_tpCondRet ;


/***********************************************************************
*$FC Função: SAL_criarSala
*$ED Descrição da função
*	Cria umsa sala, chama todas as funções set para preencher todas as dependências nescessárias.
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetErroEstrutura
*	SAL_CondRetRecebeuPonteiroNulo
*	SAL_CondRetParamInvalido
*$EP Parametros
*$P	psala: Ponteiro de ponteiro para tipo estruturado sala onde será armazenada a sala resultante.
*$P	codigo: Código da sala a ser inserido
*$P	maxAlunos: Capacidade máxima de alunos da sala a ser inserida.
*$P	eLaboratorio: Valor entre 1(é laboratório) e 0(não é laboratório) para a dependência se a sala é ou não um laboratório.
*
*$.***********************************************************************/


SAL_tpCondRet SAL_criarSala(SAL_tpSala ** pSala, char *codigo, int maxAlunos, int eLaboratorio);

/***********************************************************************
*$FC Função: SAL_removeSala
*$ED Descrição da função
*	Remove uma sala, destruindo toda as informações contidas no tipo estruturado.
*$FV Valor retornado
*	SAL_CondRetOK 
* SAL_CondRetRecebeuPonteiroNulo                                                   
*$EP Parametros
*$P	psala: Endereço do ponteiro para tipo estruturado sala.
*$.***********************************************************************/

SAL_tpCondRet SAL_removeSala (SAL_tpSala ** pSala);

/***********************************************************************
*$FC Função: SAL_printSala
*$ED Descrição da função
*	Imprime no terminal todas as informações pertinentes a sala fornecida.
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetErroEstrutura						
*	SAL_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	psala: Ponteiro para tipo estruturado sala.
*$.***********************************************************************/

SAL_tpCondRet SAL_printSala (SAL_tpSala * pSala);

/***********************************************************************
*$FC Função: SAL_setCodigo
*$ED Descrição da função
*	Define o código da sala fornecida.
*$FV Valor retornado
*	SAL_CondRetOK					
*	SAL_CondRetRecebeuPonteiroNulo
*    	SAL_CondRetParamInvalido
*$EP Parametros
*$P	pSala: Ponteiro para tipo estruturado sala.
*$P	codigo: Código da sala a ser inserido.
*$.***********************************************************************/

SAL_tpCondRet SAL_setCodigo(SAL_tpSala * pSala, char *codigo);

/***********************************************************************
*$FC Função: SAL_getCodigo
*$ED Descrição da função
*	Retrona o código da sala fornecida no conteúdo do ponteiro código.
*$FV Valor retornado
*	SAL_CondRetOK                                                      
*	SAL_CondRetErroEstrutura
*	SAL_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pSala: Ponteiro para tipo estruturado sala.
*$P	codigo: Código da sala a ser retornado.
*$.***********************************************************************/

SAL_tpCondRet SAL_getCodigo(SAL_tpSala * pSala, char *codigo);

/***********************************************************************
*$FC Função: SAL_setMaxAlunos
*$ED Descrição da função
*	Insere a capacidade máxima de alunos em uma sala.
*$FV Valor retornado
*	SAL_CondRetOK					
*	SAL_CondRetRecebeuPonteiroNulo
*	SAL_CondRetErroEstrutura	
*$EP Parametros
*$P	pSala: Ponteiro para tipo estruturado sala.
*$P	maxAlunos: Capacidade máxima de alunos na sala.
*$.***********************************************************************/

SAL_tpCondRet SAL_setMaxAlunos (SAL_tpSala * pSala, int maxAlunos);

/***********************************************************************
*$FC Função: SAL_getMaxAlunos
*$ED Descrição da função
*	Retorna no conteúdo de um ponteiro a capacidade máxima de alunos da sala fornecida.
*$FV Valor retornado
*	SAL_CondRetOK					
*	SAL_CondRetRecebeuPonteiroNulo
*	SAL_CondRetErroEstrutura	
*$EP Parametros
*$P	pSala: Ponteiro para tipo estruturado sala.
*$P	maxAlunos: Capacidade máxima de alunos na sala.
*$.***********************************************************************/

SAL_tpCondRet SAL_getMaxAlunos (SAL_tpSala * pSala, int *maxAlunos);

/***********************************************************************	
*$FC Função: SAL_setELaboratorio
*$ED Descrição da função
*	Insere um inteiro (1 se sim, 0 se não) na dependência se a sala fornecida é laboratório. 
*$FV Valor retornado
*	SAL_CondRetOK                                                      
*	SAL_CondRetErroEstrutura
*	SAL_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pSala: ponteiro para tipo estruturado sala.
*$P	eLaboratorio: Indicador de que a sala é laboratório (1 se sim, 0 se não)
*$.***********************************************************************/

SAL_tpCondRet SAL_setELaboratorio (SAL_tpSala * pSala, int eLaboratorio);

/***********************************************************************
*$FC Função: SAL_getELaboratorio
*$ED Descrição da função
*	Retorna se a sala fornecida é um laboratório em um ponteiro (1 se sim, 0 se não).
*$FV Valor retornado
*	SAL_CondRetOK                                                      
*	SAL_CondRetErroEstrutura
*	SAL_CondRetRecebeuPonteiroNulo
*$EP Parametros
$P	pSala: ponteiro para tipo estruturado sala.
$P	eLaboratorio: Indicador de que a sala é laboratório (1 se sim, 0 se não).
*$.***********************************************************************/

SAL_tpCondRet SAL_getELaboratorio (SAL_tpSala * pSala, int *eLaboratorio);

/***********************************************************************
*$FC Função: SAL_getNumero
*$ED Descrição da função
*	Pega numero da sala fornecida e coloca no conteúdo de um ponteiro.
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetRecebeuPonteiroNulo 
*	SAL_CondRetErroEstrutura
*$EP Parametros
*$P	pSala: ponteiro para tipo estruturado sala.
*$P	numero: numero da sala a ser retornado pela função.
*$.***********************************************************************/

SAL_tpCondRet SAL_getNumero (SAL_tpSala * pSala, int *numero);

/***********************************************************************
*$FC Função: SAL_getPredio
*$ED Descrição da função
*	Pega predio da sala.
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetErroEstrutura
*	SAL_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pSala: ponteiro para tipo estruturado sala.
*$P	predio: string para retornar prédio da sala fornecida.
*$.************************************************************************/

SAL_tpCondRet SAL_getPredio (SAL_tpSala * pSala, char *predio);

/***********************************************************************
*$FC Função: SAL_getAndar
*$ED Descrição da função
*	Pega andar da sala.
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetErroEstrutura 
*	SAL_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pSala: ponteiro para tipo estruturado sala.
*$P	andar: andar da sala fornecida.
*$.***********************************************************************/

SAL_tpCondRet SAL_getAndar (SAL_tpSala * pSala, int *andar);

/***********************************************************************
*$FC Função: SAL_reservaSala
*$ED Descrição da função
*	Reserva a sala em um determinado dia em um determinado intervalo.
*
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetRecebeuPonteiroNulo
*	SAL_CondRetErroAoReservar
*	SAL_CondRetParamInvalido
*$EP Parametros
*$P	pSala: ponteiro para tipo estruturado sala.
*$P	dia
*$P	horaInicio: início do intervalo de tempo a ser reservado pela aula na sala.
*$P	horaFim: fim do intervalo de tempo a ser reservado pela aula na sala.
*$.***********************************************************************/

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim);

/***********************************************************************
*$FC Função: SAL_resetDisponibilidade
*$ED Descrição da função
*	Reseta a matriz disponibilidade (todos horarios disponiveis).
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetRecebeuPonteiroNulo
* SAL_CondRetErroAoLiberar
*$EP Parametros
*$P	pSala: ponteiro para tipo estruturado sala.
*$.***********************************************************************/

SAL_tpCondRet SAL_resetDisponibilidade (SAL_tpSala * pSala);

/***********************************************************************
*$FC Função: SAL_printDisponibilidade
*$ED Descrição da função
*	Imprime a matriz disponibilidade da Sala com XXXXXX quando 
*	estiver ocupada e ------ quando livre.
*$FV Valor retornado
*	SAL_CondRetOK
*	SAL_CondRetRecebeuPonteiroNulo
*	SAL_CondRetErroEstrutura
*$EP Parâmetros
*$P pSala: ponteiro para tipo estruturado sala.
***********************************************************************/

SAL_tpCondRet SAL_printDisponibilidade(SAL_tpSala * pSala);

/***********************************************************************
*$FC Função: SAL_getHorarioNoDia
*$ED Descrição da função
*	Pega horário da sala fornecida no dia especificado.
*$FV Valor retornado
*	SAL_CondRetOK, se a função for concluída com sucesso
*	SAL_CondRetRecebeuPonteiroNulo, se a sala recebida for nula
*	SAL_CondRetParamInvalido, se:
*	  1. O horário de início for maior ou igual ao horário de fim;
*	  2. Se algum dos horários não estiver compreendido no período de 7 a 22 horas
*	  durante o qual as aulas ocorrem;
*$EP	Parâmetros
*$PpSala: ponteiro para a sala desejada
*$P	dia: valor inteiro entre 0 e 5 (ambos inclusive) representando um dos dias da semana
*	de segunda a sábado (0 = segunda, 1 = terça, ..., 5 = sábado)
*$P	horarioInicio: valor entre 7 e 22 representando o horário de início do período a ser
*	verificado
*$P	horarioFim: valor entre 7 e 22 representando o horário de fim do período a ser verificado
*$P	estaDisponivel: ponteiro para uma variável inteira onde será armazenado 1 se o intervalo
*	selecionado estiver disponível, 0 se não estiver.
*$.***********************************************************************/

SAL_tpCondRet SAL_getHorarioNoDia(SAL_tpSala * pSala, int dia, int horarioInicio, int horarioFim);

#undef SALA_EXT

/********** Fim do módulo de definição: Módulo Sala **********/

#else
#endif
