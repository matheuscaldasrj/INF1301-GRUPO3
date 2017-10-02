#if ! defined( DISCIPLINACURSADA_ )
#define DISCIPLINACURSADA_

/****************************************************************
*$AD Módulo de definição
*	Arquivo: DISCIPLINACURSADA.h
*	Proprietário: Grupo 3 INF1301 17.2
*	Projeto: Trabalho 1
*	Gestor:  DI/PUC-Rio
*	Letras Identificadoras: DIC
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
*     atributos do módulo DisciplinaCursada.
*
*
*$HA Alterações:
*       Versao       Autor         Data            Observacoes
*       1.0.0         mc        30/09/2017   	Inicio do desenvolvimento
*		1.0.1         va        30/09/2017   	Implementaçacao das funcoes de criar e
												set situacao, grau e periodo.
*
*$.***************************************************************************/

#if defined( DISCIPLINACURSADA_OWN )
   #define DISCIPLINACURSADA_EXT
#else
   #define DISCIPLINACURSADA_EXT extern
#endif


/***** Declarações exportadas pelo módulo *****/
//TODO
/*Tipo estruturado tpDisciplinaCursada é constituido por .... */
typedef struct DIC_tagDisciplinaCursada DIC_tpDisciplinaCursada;

/***********************************************************************
*
*$TC Tipo de dados: DIC Condicoes de retorno
*$ED Descrição do tipo
*    Condições de retorno das funções da DISCIPLINACURSADA
*
*$.***********************************************************************/

typedef enum {

  DIC_CondRetOK = 0 ,
    /* Executou correto */

  DIC_CondRetFaltouMemoria = 1 ,
    /* Erro ao tentar ciar DisciplinaCursada */

  DIC_CondRetRecebeuPonteiroNulo = 2 ,
		/* Recebeu ponteiro para DisciplinaCursada nulo */

  DIC_CondRetParamInvalido = 3 ,
    /* Erro no parametro recebido em funcao set */


} DIC_tpCondRet ;


/***********************************************************************
*$FC Função: DIC_criarDisciplinaCursada
*$ED Descrição da função
*	Cria uma DisciplinaCursada, chama todas as funções set para preencher todas as dependências nescessárias.
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetFaltouMemoria
*	DIC_CondRetRecebeuPonteiroNulo
*	DIC_CondRetParamInvalido
*$EP Parametros
*$P	pDisciplinaCursada: Ponteiro de ponteiro para tipo estruturado DisciplinaCursada onde será armazenada a DisciplinaCursada resultante.
*
*$.***********************************************************************/


DIC_tpCondRet DIC_criarDisciplinaCursada(DIC_tpDisciplinaCursada ** pDisciplinaCursada, int situacao, float grau);

/***********************************************************************
*$FC Função: DIC_removeDisciplinaCursada
*$ED Descrição da função
*	Remove uma DisciplinaCursada, destruindo toda as informações contidas no tipo estruturado.
*$FV Valor retornado
*	DIC_CondRetOK 
*   DIC_CondRetParamInvalido                                                   
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$.***********************************************************************/

DIC_tpCondRet DIC_removeDisciplinaCursada (DIC_tpDisciplinaCursada ** pDisciplinaCursada);

/***********************************************************************
*$FC Função: DIC_setGrau
*$ED Descrição da função
*	define o grau da disciplina cursada fornecida
*$FV Valor retornado
*	DIC_CondRetOK 
*   DIC_CondRetParamInvalido 
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
$P	grau:: grau da disciplina ser inserido
*$.***********************************************************************/

DIC_tpCondRet DIC_setGrau (DIC_tpDisciplinaCursada * pDisciplinaCursada, float grau);

/***********************************************************************
*$FC Função: DIC_setPeriodo
*$ED Descrição da função
*	define o periodo da disciplina cursada fornecida
*$FV Valor retornado
*	DIC_CondRetOK 
*   DIC_CondRetParamInvalido 
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
$P	periodo: periodo da disciplina a ser inserida
*$.***********************************************************************/

DIC_tpCondRet DIC_setSituacao (DIC_tpDisciplinaCursada * pDisciplinaCursada, char *periodo);

/***********************************************************************
*$FC Função: DIC_setGrau
*$ED Descrição da função
*	define o situaacao da disciplina cursada fornecida
*$FV Valor retornado
*	DIC_CondRetOK 
*   DIC_CondRetParamInvalido 
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
$P	situacao: situcao na disciplina a ser inserida
*$.***********************************************************************/

DIC_tpCondRet DIC_setSituacao (DIC_tpDisciplinaCursada * pDisciplinaCursada, float situcao);



#undef DISCIPLINACURSADA_EXT

/********** Fim do módulo de definição: Módulo DisciplinaCursada **********/


#else
#endif
