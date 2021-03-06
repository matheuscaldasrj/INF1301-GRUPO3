#if ! defined( HISTORICO_ )
#define HISTORICO_


/****************************************************************
*$AD Módulo de definição
*	Arquivo: HISTORICO.h
*	Proprietário: Grupo 3 INF1301 17.2
*	Projeto: Trabalho 1
*	Gestor:  DI/PUC-Rio
*	Letras Identificadoras: HIS
*	Autores: 
*		mc - Matheus Caldas
*		bp - Bruno Pedrazza
*		pg - Pedro Gomes
*		va - Vinícius Arcoverde
*		lf - Leon França
*		gc - Gabriel Costa
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
*   1.0.5		gc	05/10/2017  Implementação adicionaDisciplinaCursada
*
*$.***************************************************************************/

#if defined( HISTORICO_OWN )
   #define HISTORICO_EXT
#else
   #define HISTORICO_EXT extern
#endif


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
*$FC Função: HIS_imprimeHistorico
*$ED Descrição da função
*	Imprime em um arquivo toda a informação contida em um histórico
*$FV Valor retornado
*	HIS_CondRetOK 
*   HIS_CondRetErroAoAbrirArquivo
*   HIS_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P pHistorico: Endereço do ponteiro para tipo estruturado historico.
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
*$.***********************************************************************/

HIS_tpCondRet HIS_imprimeHistorico(HIS_tpHistorico * pHistorico);

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

/***********************************************************************
*$FC Função: HIS_adicionaDisciplinaCursada
*$ED Descrição da função
*	Adiciona uma disciplina cursada ao histórico do aluno
*$FV Valor retornado
*	HIS_CondRetOK 
*   HIS_CondRetRecebeuPonteiroNulo
*   HIS_CondRetErroInterno
*$EP Parametros
*$P	disc: disciplina cursada
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	ponteiro corrente referencia Histórico do aluno de valor não nulo.
*$EAS Assertivas de saida
*	valem as assertivas estruturais para tipos de dados estruturados.
*	valem as assertivas estruturais para listas encadeadas.
*$.***********************************************************************/
HIS_tpCondRet HIS_adicionaDisciplinaCursada(HIS_tpHistorico * pHistorico, struct DIC_tagDisciplinaCursada* disc );

/***********************************************************************
*$FC Função: HIS_removeHistorico
*$ED Descrição da função
*	Remove um historico, destruindo toda as informações contidas no tipo estruturado.
*$FV Valor retornado
*	HIS_CondRetOK 
*   HIS_CondRetErroAoAbrirArquivo
*   HIS_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	disciplinasCursadas: List composta pelas disciplinas cursadas
*$.***********************************************************************/


#undef HISTORICO_EXT

/********** Fim do módulo de definição: Módulo Historico **********/

#else
#endif
