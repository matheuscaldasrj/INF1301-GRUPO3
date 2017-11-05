#if ! defined( HISTORICO_ )
#define HISTORICO_


/****************************************************************
*$AD Módulo de definição
*	Arquivo: HISTORICO.h
*	Proprietário: Grupo 3 INF1301 17.2
*	Projeto: Trabalho 3
*	Gestor:  DI/PUC-Rio
*	Letras Identificadoras: HIS
*	Autores: 
*		mc - Matheus Caldas
*		bp - Bruno Pedrazza
*		pg - Pedro Gomes
*		va - Vinícius Arcoverde
*		lf - Leon França
*
*$ED Descricao do modulo
*     Este módulo implementa um conjunto de funcoes para criar e manipular
*     atributos do módulo HISTORICO.
*
*
*$HA Alterações:
*       Versao		Autor	Data            Observacoes
*       1.0.0		mc	30/09/2017   	Inicio do desenvolvimento
*	1.0.1		mc	01/10/2017	Implementação da função criarHistorico
*	1.0.2		gc	04/10/2017	Implementação getCrDoPeriodo, getCrTotal, getHistoricoCompleto e getHistoricoDoPeriodo
*	1.0.3		gc	05/10/2017	Implementação getDisciplinasReprovadoPorFalta
*	1.0.4		lf	05/10/2017	Padronização e criação de documentação voltada ao cliente
*	1.0.4		va	05/10/2017	getdisplinas trancadas e imprimehistorico
*   	1.0.5		gc	05/10/2017  	Implementação adicionaDisciplinaCursada
*	1.0.6		bp	02/11/2017	Implementação getCrAcumulado, getCrPeriodo, printHistoricoCompleto, printHistoricoPeriodo
*	1.0.7		mc	04/11/2017	Remoção adicionaDisciplinaCursada, agora encapsulada no módulo Historico
*	1.0.7		mc	04/11/2017	Implementação adiconaDisciplina
*	1.0.8		mc	04/11/2017	Implementação salvaHistoricoEmArquivo e remoção imprimeHistorico
*	1.0.9		mc	04/11/2017	Implementação getDisicplinasReprovadoPorFalta
*	1.1.0		lf	05/11/2017	Documentação printHistoricoCompleto, salvaHistoricoEmArquivo e printHistoricoPeriodo
*	1.1.0		lf	05/11/2017	Manutenção do histórico de alterações
* 
*$.***************************************************************************/

#if defined( HISTORICO_OWN )
   #define HISTORICO_EXT
#else
   #define HISTORICO_EXT extern
#endif

#define tamDisciplina   8
#define tamSituacao     3
#define tamGrau         5
#define tamMatricula    20
#define tamPeriodo      7
#define TAM_NOME_ARQ    35


/***** Declarações exportadas pelo módulo *****/
//TODO
/*Tipo estruturado tpHistorico é constituido por .... */
typedef struct HIS_tagHistorico HIS_tpHistorico;

/***********************************************************************
*
*$TC Tipo de dados: HIS Condicoes de retorno
*$ED Descrição do tipo
*    Condições de retorno das funções da HISTORICO
*
*$.***********************************************************************/

typedef enum {

  HIS_CondRetOK = 0 ,
    /* Executou correto */

  HIS_CondRetFaltouMemoria = 1 ,
    /* Erro ao tentar ciar Historico */

  HIS_CondRetRecebeuPonteiroNulo = 2 ,
		/* Recebeu ponteiro para Historico nulo */

  HIS_CondRetParamInvalido = 3 ,
    /* Erro no parametro recebido em funcao set */

  HIS_CondRetProblemaListaDisciplinas = 4 ,
    /* Erro na criacao/manipulacao da lista de disciplinas */ 

  HIS_CondRetErroAoAbrirArquivo = 5 ,
    /* Erro ao abrir arquivo de texto*/ 

  HIS_CondRetErroInterno = 6
	/* Erro causado por alguma função que se comportou de forma inesperada */

} HIS_tpCondRet ;


/***********************************************************************
*$FC Função: HIS_criarHistorico
*$ED Descrição da função
*	Cria um historico, chamando todas as funções set para preencher todas as dependências nescessárias.
*$FV Valor retornado
*	HIS_CondRetOK
*	HIS_CondRetFaltouMemoria
*	HIS_CondRetRecebeuPonteiroNulo
*	HIS_CondRetProblemaListaDisciplinas
*	HIS_CondRetParamInvalido
*$EP Parametros
*$P	pHistorico: Ponteiro de ponteiro para tipo estruturado historico.
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	ponteiro corrente referencia Histórico do aluno a ser criado
*$EAS Assertivas de saida
*	valem as assertivas estruturais para tipos de dados estruturados.
*	o Histórico do aluno foi criado com êxito
*$.***********************************************************************/


HIS_tpCondRet HIS_criarHistorico(HIS_tpHistorico ** pHistorico);

/***********************************************************************
*$FC Função: HIS_removeHistorico
*$ED Descrição da função
*	Remove um historico, destruindo toda as informações contidas no tipo estruturado.
*$FV Valor retornado
*	HIS_CondRetOK
*	HIS_CondRetRecebeuPonteiroNulo                                     
*$EP Parametros
*$P	pHistorico: Endereço do ponteiro para tipo estruturado historico.
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	ponteiro corrente referencia Histórico do aluno a ser destruido.
*$EAS Assertivas de saida
*	valem as assertivas estruturais para tipos de dados estruturados.
*	o Histórico do aluno foi destruido com êxito.
*$.***********************************************************************/

HIS_tpCondRet HIS_removeHistorico (HIS_tpHistorico ** pHistorico);

/***********************************************************************
*$FC Função: HIS_getHistoricoCompleto
*$ED Descrição da função
*	Obtem todas as disciplinas cursadas por um aluno
*$FV Valor retornado
*	HIS_CondRetOK
*   HIS_CondRetParamInvalido
*$EP Parametros
*$P	pHistorico: Endereço do ponteiro para tipo estruturado historico.
*$P disciplinas: endereço do ponteiro para uma lista onde serão armazenadas as disciplinas do período
*$.***********************************************************************/

HIS_tpCondRet HIS_getHistoricoCompleto(HIS_tpHistorico * pHistorico, struct list** disciplinas);

/***********************************************************************
*$FC Função: HIS_getHistoricoDoPeriodo
*$ED Descrição da função
*	Obtem todas as disciplinas cursadas em um determinado período
*$FV Valor retornado
*	HIS_CondRetOK
* HIS_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pHistorico: Endereço do ponteiro para tipo estruturado historico.
*$P periodo: array de caracteres com o período desejado.
*$P disciplinas: ponteiro para uma lista onde serão armazenadas as disciplinas do período.
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	valem as assertivas estruturais para arrays de caractéres.
* valem as assertivas estruturais para listas encadeadas.
*	ponteiro corrente referencia Histórico do aluno de valor não nulo.
*	segundo ponteiro corrente referencia endereço de lista encadeada de tipo estruturado Disciplina não nulo.
*	periodo valido é um array composto de 6 caracteres, deve vir no formato exemplificado a seguir: 
*	"2016.1" ou "2013.2" etc
*
*$EAS Assertivas de saida
*	valem as assertivas estruturais para tipos de dados estruturados.
* valem as assertivas estruturais para listas encadeadas.
*	ponteiro Disciplinas retorna lista de tipo estruturado Disciplinas cursadas no período.
*
*$.***********************************************************************/

HIS_tpCondRet HIS_getHistoricoDoPeriodo(HIS_tpHistorico * pHistorico, char* periodo, struct list* disciplinas);

/***********************************************************************
*$FC Função: HIS_getCrTotal
*$ED Descrição da função
*	Obtem o CR geral do aluno
*$FV Valor retornado
*	HIS_CondRetOK
*	HIS_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pHistorico: Endereço do ponteiro para tipo estruturado historico.
*$P 	cr: endereço de memória de uma variável float que receberá o valor do CR
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	ponteiro corrente referencia Histórico do aluno de valor não nulo.
*
*$EAS Assertivas de saida
*	a obtenção do CR foi bem sucedida.
*	ponteiro cr retorna CR Total do aluno por referência.
*
*$.***********************************************************************/

HIS_tpCondRet HIS_getCrTotal(HIS_tpHistorico * pHistorico, float* cr);

/***********************************************************************
*$FC Função: HIS_getCrDoPeriodo
*$ED Descrição da função
*	Obtem o CR do aluno referente ao período fornecido.
*$FV Valor retornado
*	HIS_CondRetOK
*	HIS_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pHistorico: Endereço do ponteiro para tipo estruturado historico.
*$P 	periodo: array de caracteres com o período desejado
*$P 	cr: endereço de memória de uma variável float que receberá o valor do CR
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	valem as assertivas estruturais para arrays de caractéres
*	ponteiro corrente referencia Histórico do aluno de valor não nulo.
*	periodo valido é um array composto de 6 caracteres, deve vir no formato exemplificado a seguir: 
*	"2016.1" ou "2013.2" etc.
*$EAS Assertivas de saida
*	a obtenção do CR foi bem sucedida.
*	ponteiro cr retorna CR do período do aluno por referência.
*
*$.***********************************************************************/

HIS_tpCondRet HIS_getCrDoPeriodo(HIS_tpHistorico * pHistorico, char * periodo, float *cr);


/***********************************************************************
*$FC Função: HIS_getDisciplinasTrancadas
*$ED Descrição da função
*	Obtem as disciplinas que foram trancadas 
*$FV Valor retornado
*	HIS_CondRetOK 
*   HIS_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	disciplinasCursadas: List composta pelas disciplinas cursadas
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	valem as assertivas estruturais para arrays de caractéres
*	ponteiro corrente referencia Histórico do aluno de valor não nulo.
*	periodo valido é um array composto de 6 caracteres, deve vir no formato exemplificado a seguir: 
*	"2016.1" ou "2013.2" etc.
*$EAS Assertivas de saida
*	valem as assertivas estruturais para tipos de dados estruturados.
*	valem as assertivas estruturais para listas encadeadas.
*	ponteiro Disciplinas retorna lista de tipo estruturado Disciplinas cursadas no período.
*

*$.***********************************************************************/
HIS_tpCondRet HIS_getDisciplinasTrancadas(HIS_tpHistorico * pHistorico,  struct list* disciplinas);


// Agora encapsulada
//HIS_tpCondRet HIS_adicionaDisciplinaCursada(HIS_tpHistorico * pHistorico, struct DIC_tagDisciplinaCursada* disc );



/***********************************************************************
*$FC Função: HIS_adicionaDisciplina
*$ED Descrição da função
*	Adiciona uma disciplina ao histórico do aluno
*$FV Valor retornado
*	HIS_CondRetOK 
*   HIS_CondRetRecebeuPonteiroNulo
*   HIS_CondRetErroInterno
*$EP Parametros

*$P	pHistorico: ponteiro para historico
*$P	disciplina: ponteiro para disciplina a ser adicionada
*$P	situacao: situacao do aluno
*$P	periodo: periodo da disciplina a ser adicionada
*$P	disciplina: grau obtido na disciplina
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	ponteiro corrente referencia Histórico do aluno de valor não nulo.
*	ponteiro corrente referencia disciplina de valor não nulo.
*	situacao é uma situacao valida não nula
*	periodo é o peridoo válido e não nulo
*	grau é um grau valido não nulo
*	
*$EAS Assertivas de saida
*	valem as assertivas estruturais para tipos de dados estruturados.
*	valem as assertivas estruturais para listas encadeadas.
*	disciplina corretamente adicionada ao historico
*$.***********************************************************************/
HIS_tpCondRet HIS_adicionaDisciplina(HIS_tpHistorico * pHistorico , struct disciplina *disciplina, char *situacao, char* periodo, float grau );

/**************************************************************************
 *  
 *  $FC Funçaão: HIS printHistoricoCompleto
 *
 *  $ED Descrição da função
 *		 Recebe uma matricula, procura o arquivo de histórico e o imprime no terminal.
 *  $EP Parâmetros	
 *	  $P matricula:		número de matricula do aluno
 *	$FV Valor retornado
 *		 HIS_CondRetOK
 *		 HIS_CondRetErroAoAbrirArquivo
 *		 HIS_CondRetErroInterno:		Erro em função interna.
 *	$EAE Assertivas de entrada
 *		Matricula fornecida deve possuir 7 caracteres numéricos.
 *		Valem as assertivas estruturais para tipos de caracteres inteiros unsigned.
 *	$EAS Assertivas de saida
 *		O histórico referente ao período dado foi devidamente impresso no terminal, senão relata mensagem de erro.
 *
*$.***********************************************************************/
HIS_tpCondRet HIS_printHistoricoCompleto (unsigned int matricula);

/**************************************************************************
 *                                                                        
 *  $FC Função: HIS printHistoricoPeriodo
 *
 *  $ED Descrição da função
 *		 Recebe uma matricula, procura no arquivo de histórico a informação referente ao período dado e a imprime no terminal.
 *  $EP Parâmetros
 *	  $P matricula: número de matricula do aluno desejado
 *	  $P periodo: array de caracteres com o período desejado
 *	$FV Valor retornado
 *		 HIS_CondRetOK
 *		 HIS_CondRetErroAoAbrirArquivo
 *		 HIS_CondRetErroInterno:		Erro em função interna.
 *	$EAE Assertivas de entrada
 *		Valem as assertivas estruturais para tipos de caracteres inteiros unsigned.
 *		Valem as assertivas estruturais para arrays de caracteres.
 *		Matricula fornecida deve possuir 7 caracteres numéricos.
 *		Período deve ser composto apenas de um caracter.
 *	$EAS Assertivas de saida
 *		O histórico foi devidamente impresso no terminal, senão relata mensagem de erro.
 *
*$.***********************************************************************/
HIS_tpCondRet HIS_printHistoricoPeriodo (unsigned int matricula, char *periodo);



/**************************************************************************
 *                                                                        
 *  $FC Função: HIS SalvaHistoricoEmArquivo
 *
 *  $ED Descrição da função
 *		Escreve no histórico a relação de matérias que o aluno com a matricula fornecida cursou no período.
 *  $EP Parâmetros
 *	  $P pHistorico - Ponteiro de ponteiro para tipo estruturado Histórico, contendo lista de diciplinas cursadas no período
 *	  $P matricula - número de matricula do aluno desejado
 *	$FV Valor retornado
 *		 HIS_CondRetOK
 *		 HIS_CondRetErroAoAbrirArquivo
 *		 HIS_CondRetErroInterno:		Erro em função interna.
 *	$EAE Assertivas de entrada
 *		Valem as assertivas estruturais para tipos de dados estruturados.
 *		Valem as assertivas estruturais para tipos de caracteres inteiros unsigned.
 *		Ponteiro corrente referencia lista de matérias do aluno a serem adicionadas ao histórico, podendo estar vazia.
 *		Matricula fornecida deve possuir 7 caracteres numéricos.
 *	$EAS Assertivas de saida
 *		O histórico foi editado com exito, senão retorna mensagem de erro no terminal e não aplica nenhuma mudança no arquivo.
 *
*$.***********************************************************************/
HIS_tpCondRet HIS_salvaHistoricoEmArquivo (HIS_tpHistorico ** pHistorico, unsigned int matricula);



/**************************************************************************
 *                                                                        
 *  $FC Função: HIS getDisciplinasReprovadoPorFalta
 *
 *  $ED Descrição da função
 *		Gera lista de disciplinas as quais o aluno reprovou por falta.
 *  $EP Parâmetros
 *	  $P pHistorico:		Ponteiro para tipo estruturado Histórico, contendo lista de diciplinas cursadas do aluno.
 *	  $P disciplinas:		Ponteiro para lista de disciplinas.
 *	$FV Valor retornado
 *		 HIS_CondRetOK
 *		 HIS_CondRetRecebeuPonteiroNulo
 *	$EAE Assertivas de entrada
 *		Valem as assertivas estruturais para tipos de dados estruturados.
 *		Valem as assertivas estruturais para listas duplamente encadeadas.
 *		Primeiro ponteiro corrente não nulo referencia histórico do aluno a ser pesquisado. Pode conter lista vazia de disciplinas cursadas.
 *		Segundo ponteiro corrente não nulo referencia lista de disciplinas a ser preenchida pela função.
 *	$EAS Assertivas de saida
 *		Lista de disciplinas reprovadas por faltas foi gerada com êxito, sendo retornada por referência.
 *		Valem as assertivas estruturais para listas duplamente encadeadas.
 *
*$.***********************************************************************/
HIS_tpCondRet HIS_getDisciplinasReprovadoPorFalta(HIS_tpHistorico * pHistorico, struct list * disciplinas);


#undef HISTORICO_EXT

/********** Fim do módulo de definição: Módulo Historico **********/

#else
#endif
