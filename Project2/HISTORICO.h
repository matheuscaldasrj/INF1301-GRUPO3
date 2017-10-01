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
*		 mc - Matheus Caldas
*		 bp - Bruno Pedrazza
*	     pg - Pedro Gomes
*	     va - Vinícius Arcoverde
*	     lf - Leon França
*	     gc - Gabriel Costa
*
*$ED Descricao do modulo
*     Este módulo implementa um conjunto de funcoes para criar e manipular
*     atributos do módulo HISTORICO.
*
*
*$HA Alterações:
*       Versao       Autor         Data            Observacoes
*       1.0.0         mc        30/09/2017   	Inicio do desenvolvimento
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


} HIS_tpCondRet ;


/***********************************************************************
*$FC Função: HIS_criarHistorico
*$ED Descrição da função
*	Cria um historico, chama todas as funções set para preencher todas as dependências nescessárias.
*$FV Valor retornado
*	HIS_CondRetOK
*	HIS_CondRetFaltouMemoria
*	HIS_CondRetRecebeuPonteiroNulo
*	HIS_CondRetParamInvalido
*$EP Parametros
*$P	pHistorico: Ponteiro de ponteiro para tipo estruturado historico onde será armazenada o historico resultante.
*
*$.***********************************************************************/


HIS_tpCondRet HIS_criarHistorico(HIS_tpHistorico ** pHistorico);

/***********************************************************************
*$FC Função: HIS_removeHistorico
*$ED Descrição da função
*	Remove um historico, destruindo toda as informações contidas no tipo estruturado.
*$FV Valor retornado
*	HIS_CondRetOK 
*   HIS_CondRetParamInvalido                                                   
*$EP Parametros
*$P	pHistorico: Endereço do ponteiro para tipo estruturado historico.
*$.***********************************************************************/

HIS_tpCondRet HIS_removeHistorico (HIS_tpHistorico ** pHistorico);


#undef HISTORICO_EXT

/********** Fim do módulo de definição: Módulo Historico **********/

#else
#endif
