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
*												set situacao, grau e periodo.
*		1.0.2		  pg		03/09/2017		Adicionando DIC_setDisciplina.
*		1.0.3		  va		03/09/2017		Correção de parametros de criar disciplina
*		1.0.3		  va		03/09/2017		Documentacao setDisciplina
*
*$.***************************************************************************/

#if defined( DISCIPLINACURSADA_OWN )
   #define DISCIPLINACURSADA_EXT
#else
   #define DISCIPLINACURSADA_EXT extern
#endif


/***** Declarações exportadas pelo módulo *****/
/*Tipo estruturado tpDisciplinaCursada é constituido por quatro(4) tipos de dados diferentes criados para identificação, categorização
e manipulação das DISCIPLINAS CURSADAS peloas alunos de informática da PUC-Rio, são eles a disciplinaque foi cursada que é um tipo 
estruturado contendo os dados proprios a ela(para maiores detalhes verificar docuemntacao do modulo), um parâmetro para definir a situação do
aluno após a  conclusão da disciplina que pode ser "AP" como aprovada, "RP" reprovado por nota ou então "RF" reprovado por faltas ou então "TR" que é para as disicplinas q foram trancadas, outro parâmetro 
é o periodo em que a matéria foi feita (exs:2014.1, 2017.2, 3000.3) e por fim o grau final obtido na materia*/
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
*	$P	pDisciplinaCursada: Ponteiro de ponteiro para tipo estruturado DisciplinaCursada onde será armazenada a DisciplinaCursada resultante.
*	$P disciplina: endereco do ponteio para tipo estruturado disciplina
*	$P	situacao: situação na disciplina a ser inserida
*	$P	grau: grau da disciplina ser inserido
*	$P	periodo: periodo da disciplina a ser inserida
$EAE Assertivas de entrada
*	disciplina com os parametros preenchidos
*	situacao == "AP" || situacao ==  "RP" || situacao == "RN" || situacao == "TR" 
*	periodo == string com 7 characteres
*	grau >= 0 && <= 10
*$EAE Assertivas de saída esperadas
*	DIC_COndRetOK
*	valores de disicplina cursada preenchidos com os parâmetros
*
*$.***********************************************************************/


DIC_tpCondRet DIC_criarDisciplinaCursada(DIC_tpDisciplinaCursada ** pDisciplinaCursada, struct disciplina *disciplina, char * situacao, char *periodo, float grau);

/***********************************************************************
*$FC Função: DIC_removeDisciplinaCursada
*$ED Descrição da função
*	Remove uma DisciplinaCursada, destruindo toda as informações contidas no tipo estruturado.
*$FV Valor retornado
*	DIC_CondRetOK 
*   DIC_CondRetParamInvalido                                                   
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
$EAE Assertivas de entrada
*	DisciplinaCursada != NULL
*$EAE Assertivas de saída esperadas
*	DIC_COndRetOK
*	DisciplinaCursada == NULL
*
*$.***********************************************************************/

DIC_tpCondRet DIC_removeDisciplinaCursada (DIC_tpDisciplinaCursada ** pDisciplinaCursada);


/***********************************************************************
*$FC Função: DIC_setDisciplinaCursada
*$ED Descrição da função
*	Define a disciplina que foi cursada
*$FV Valor retornado
*	DIC_CondRetOK 
*   DIC_CondRetParamInvalido  
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	disciplina: endereco do ponteio para tipo estruturado disciplina
$EAE Assertivas de entrada
*	disciplina válida
*$EAE Assertivas de saída esperadas
*pDisciplina->disciplina = disciplina
*
*$.***********************************************************************/

DIC_tpCondRet DIC_setDisciplina (DIC_tpDisciplinaCursada * pDisciplinaCursada, struct disciplina *disciplina);

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
$EAE Assertivas de entrada
*	grau válido
*$EAE Assertivas de saída esperadas
*pDisciplina->grau = grau
*
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
$EAE Assertivas de entrada
*	periodo válido
*$EAE Assertivas de saída esperadas
*pDisciplina->periodo = periodo
*$.***********************************************************************/

DIC_tpCondRet DIC_setPeriodo (DIC_tpDisciplinaCursada * pDisciplinaCursada, char *periodo);

/***********************************************************************
*$FC Função: DIC_setSituacao
*$ED Descrição da função
*	define a situação da disciplina cursada fornecida
*$FV Valor retornado
*	DIC_CondRetOK 
*   DIC_CondRetParamInvalido 
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	situacao: situação na disciplina a ser inserida
$EAE Assertivas de entrada
*	situacao válida
*$EAE Assertivas de saída esperadas
*pDisciplina->situacao = situacao
*$.***********************************************************************/

DIC_tpCondRet DIC_setSituacao (DIC_tpDisciplinaCursada * pDisciplinaCursada, char* situacao);

/***********************************************************************
*$FC Função: DIC_setTodosOsCampos
*$ED Descrição da função
*	insere todos as informações referentes ao aluno em uma disciplina, valendo
*$FV Valor retornado
*	DIC_CondRetOK
*   DIC_CondRetParamInvalido
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	situacao: situação na disciplina a ser inserida
*$P	periodo: periodo da disciplina a ser inserida
*$P	grau: grau da disciplina ser inserido
$EAE Assertivas de entrada
*	disiciplina valida
*	situacao válida
*	grau valido
*	peridoo valido
*$EAE Assertivas de saída esperadas
*	pDisciplina->situacao = situacao
*	pDisciplina->grau = grau
*	pDisciplina->disciplina = disciplina
*	pDisciplina->periodo = periodo
*
*$.***********************************************************************/

DIC_tpCondRet DIC_setTodosOsCampos(DIC_tpDisciplinaCursada *pDisciplinaCursada, struct disciplina *disciplina, char *situacao, char *periodo, float grau);

/***********************************************************************
*$FC Função: DIC_getDisciplina
*$ED Descrição da função
*	pega a disciplina do struct DisciplinaCursada
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	disciplina: ponteiro para a variável que receberá o struct
$EAE Assertivas de entrada
*	pDisciplinaCursada válida
*$EAE Assertivas de saída esperadas
*	*disciplina = pDisciplinaCursada->disciplina
*$.***********************************************************************/

DIC_tpCondRet DIC_getDisciplina(DIC_tpDisciplinaCursada *pDisciplinaCursada, struct disciplina  *disciplina);

/***********************************************************************
*$FC Função: DIC_getGrau
*$ED Descrição da função
*	insere o grau de um aluno em uma disciplina em particular num ponteiro para uma variável float
*$FV Valor retornado
*	DIC_CondRetOK
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	grau: ponteiro para a variável float que receberá o grau
$EAE Assertivas de entrada
*	pDisciplinaCursada válida
*$EAE Assertivas de saída esperadas
*	*grau = pDisciplinaCursada->grau
*$.***********************************************************************/

DIC_tpCondRet DIC_getGrau(DIC_tpDisciplinaCursada * pDisciplinaCursada, float* grau);

/***********************************************************************
*$FC Função: DIC_getSituacao
*$ED Descrição da função
*	insere a situação de um aluno em uma disciplina em um array de caracteres
*$FV Valor retornado
*	DIC_CondRetOK
*   DIC_CondRetParamInvalido
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	situacao: situação na disciplina a ser inserida
$EAE Assertivas de entrada
*	pDisciplinaCursada válida
*$EAE Assertivas de saída esperadas
*	*situacao = pDisciplinaCursada->situacao
*$.***********************************************************************/

DIC_tpCondRet DIC_getSituacao(DIC_tpDisciplinaCursada * pDisciplinaCursada, char* situacao);

/***********************************************************************
*$FC Função: DIC_getPeriodo
*$ED Descrição da função
*	insere o período que um aluno cursou uma disciplina em um array de caracteres
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	periodo: ponteiro para ym array de caracteres que receberá o período da disciplina cursada
$EAE Assertivas de entrada
*	pDisciplinaCursada válida
*$EAE Assertivas de saída esperadas
*	*periodo = pDisciplinaCursada->periodo
*$.***********************************************************************/

DIC_tpCondRet DIC_getPeriodo(DIC_tpDisciplinaCursada * pDisciplinaCursada, char* situacao);

/***********************************************************************
*$FC Função: DIC_getTodosOsCampos
*$ED Descrição da função
*	Retorna por referência todos as informações referentes ao aluno em uma disciplina, sendo elas:
*	ponteiro para disciplina cursada, situação do aluno na disciplina , período cursado e grau referente.
*$FV Valor retornado
*	DIC_CondRetOK
*	CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	disciplina: endereco do ponteio para tipo estruturado disciplina a ser inserida.
*$P	situacao: situação na disciplina a ser retornada
*$P	periodo: periodo da disciplina a ser retornado
*$P	grau: grau da disciplina ser retornado
$EAE Assertivas de entrada
*	pDisciplinaCursada válida
*$EAE Assertivas de saída esperadas
*	*grau = pDisciplinaCursada->grau
*	*periodo = pDisciplinaCursada->periodo
*	*situacao = pDisciplinaCursada->situacao
*	*disciplina = pDisciplinaCursada->disciplina
*$.***********************************************************************/

DIC_tpCondRet DIC_getTodosOsCampos(DIC_tpDisciplinaCursada *pDisciplinaCursada, struct disciplina *disciplina, char *situacao, char *periodo, float *grau);

#undef DISCIPLINACURSADA_EXT

/********** Fim do módulo de definição: Módulo DisciplinaCursada **********/


#else
#endif
