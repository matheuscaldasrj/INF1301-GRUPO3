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
*		 		mc - Matheus Caldas
*		 		bp - Bruno Pedrazza
*	    	pg - Pedro Gomes
*	    	va - Vinícius Arcoverde
*	    	lf - Leon França
*	    	gc - Gabriel Costa
*
*$ED Descricao do modulo
*     Este módulo implementa um conjunto de funcoes para criar e manipular
*     atributos do módulo DisciplinaCursada.
*
*
*$HA Alterações:
*				Versao       Autor         Data            Observacoes
*       1.0.0         mc        30/09/2017   	Inicio do desenvolvimento
*		1.0.1         va        30/09/2017   	Implementaçacao das funcoes de criar e
*												set situacao, grau e periodo.
*		1.0.2		  pg		03/09/2017		Adicionando DIC_setDisciplina.
*		1.0.3		  va		03/09/2017		Correção de parametros de criar disciplina
*		1.0.3		  va		03/09/2017		Documentacao setDisciplina
*		1.0.4		  mc		05/09/2017		Updating getDisciplina header
*
*				1.0.4		  		va		05/10/2017		Documentacao setDisciplina
*				1.0.5					lf		05/10/2017		Correção e finalização de documentação voltada ao cliente
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
*
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetFaltouMemoria
*	DIC_CondRetRecebeuPonteiroNulo
*	DIC_CondRetParamInvalido
*
*$EP Parametros
*	$P	pDisciplinaCursada: Ponteiro de ponteiro para tipo estruturado DisciplinaCursada onde será armazenada a DisciplinaCursada resultante.
*	$P  disciplina: endereco do ponteio para tipo estruturado disciplina
*	$P	situacao: situação na disciplina a ser inserida
*	$P	grau: grau da disciplina ser inserido
*	$P	periodo: periodo da disciplina a ser inserida
*
*$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro corrente referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada a ser criada.
*	segundo ponteiro corrente referencia um tipo estruturado Disciplina não nulo.
*	situacao válida é composta de 2 caracteres não nulos, podendo tomar os valores:
* "AP" para *	condição de aluno AProvado, "RN" para condição de aluno Reprovado por Nota 
* e "RF" para *	condição Reprovado por Falta.
*	periodo valido é composto de 6 caracteres, deve vir no formato exemplificado a seguir: 
*	"2016.1" ou "2013.2" etc.
*	grau valido é caracterizado por um número (float) maior que zero (>0) e menor que 10 (<10), 
*	limitando-se a uma única casa decimal.
*
*$EAS Assertivas de saida
*	valem as assertivas estruturais para tipos estruturados.
*	A disciplina cursada foi criada com êxito.
*	primeiro ponteiro corrente aponta para Disciplina Cursada resultante.
*	campos de disicplina cursada foram devidamente preenchidos.
*
*$.***********************************************************************/


DIC_tpCondRet DIC_criarDisciplinaCursada(DIC_tpDisciplinaCursada ** pDisciplinaCursada, struct disciplina *disciplina, char * situacao, char *periodo, float grau);

/***********************************************************************
*$FC Função: DIC_removeDisciplinaCursada
*$ED Descrição da função
*	Remove uma DisciplinaCursada, destruindo toda as informações contidas no tipo estruturado.
*$FV Valor retornado
*	DIC_CondRetOK 
* 	DIC_CondRetParamInvalido                                                   
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	ponteiro corrente referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada a ser removida.
*
*$EAS Assertivas de saída
*	A disciplina cursada foi removida, juntamente com todos os dados contidos nela.
*
*$.***********************************************************************/
DIC_tpCondRet DIC_removeDisciplinaCursada (DIC_tpDisciplinaCursada ** pDisciplinaCursada);


/***********************************************************************
*$FC Função: DIC_setDisciplinaCursada
*$ED Descrição da função
*		Define a disciplina que foi cursada.
*$FV Valor retornado
*	DIC_CondRetOK 
*   	DIC_CondRetParamInvalido  
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*	$P	disciplina: endereco do ponteio para tipo estruturado disciplina
*
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro referencia tipo estruturado DisciplinaCursada.
*	segundo ponteiro referencia endereço de lista encadeada de tipo estruturado Disciplina não nulo.
*
*$EAE Assertivas de saída esperadas
*	ponteiro para tipo estruturado DisciplinaCursada contém a disciplina fornecida.
*	valem as assertivas estruturais para tipos de dados estruturados.
*
*$.***********************************************************************/

DIC_tpCondRet DIC_setDisciplina (DIC_tpDisciplinaCursada * pDisciplinaCursada, struct disciplina *disciplina);

/***********************************************************************
*$FC Função: DIC_setGrau
*$ED Descrição da função
*	define o grau da disciplina cursada fornecida
*$FV Valor retornado
*	DIC_CondRetOK 
*   	DIC_CondRetParamInvalido 
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*	$P	grau: grau da disciplina a ser inserido
$EAE Assertivas de entrada
* valem as assertivas estruturais para tipos de dados estruturados.
*	grau valido é caracterizado por um número (float) maior que zero (>0) e menor que 10 (<10), 
*	limitando-se a uma única casa decimal.
*
*$EAE Assertivas de saída esperadas
*	 O grau do aluno foi inserido na disciplina cursada.
*
*$.***********************************************************************/
DIC_tpCondRet DIC_setGrau (DIC_tpDisciplinaCursada * pDisciplinaCursada, float grau);

/***********************************************************************
*$FC Função: DIC_setPeriodo
*$ED Descrição da função
*	define o periodo da disciplina cursada fornecida
*$FV Valor retornado
*	DIC_CondRetOK 
*  	DIC_CondRetParamInvalido 
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*	$P	periodo: periodo da disciplina a ser inserida
*
$EAE Assertivas de entrada
* valem as assertivas estruturais para tipos de dados estruturados.
*	periodo valido é composto de 6 caracteres, deve vir no formato exemplificado a seguir: 
*	"2016.1" ou "2013.2" etc.
*
*$EAE Assertivas de saída esperadas
* O período do aluno foi inserido na disciplina cursada.
*
*$.***********************************************************************/

DIC_tpCondRet DIC_setPeriodo (DIC_tpDisciplinaCursada * pDisciplinaCursada, char *periodo);

/***********************************************************************
*$FC Função: DIC_setSituacao
*$ED Descrição da função
*	define a situação da disciplina cursada fornecida
*$FV Valor retornado
*	DIC_CondRetOK 
*  	DIC_CondRetParamInvalido 
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	situacao: situação na disciplina a ser inserida
$EAE Assertivas de entrada
* valem as assertivas estruturais para tipos de dados estruturados.
*	situacao válida é composta de 2 caracteres não nulos, podendo tomar os valores:
* "AP" para condição de aluno AProvado, "RN" para condição de aluno Reprovado por Nota 
* e "RF" para	condição Reprovado por Falta.
*
*$EAE Assertivas de saída esperadas
* A situação do aluno foi inserida na disciplina cursada.
*
*$.***********************************************************************/

DIC_tpCondRet DIC_setSituacao (DIC_tpDisciplinaCursada * pDisciplinaCursada, char* situacao);

/***********************************************************************
*$FC Função: DIC_setTodosOsCampos
*$ED Descrição da função
*		insere todas as informações referentes ao aluno em uma disciplina
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetParamInvalido
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*	$P	situacao: situação na disciplina a ser inserida
*	$P	periodo: periodo da disciplina a ser inserida
*	$P	grau: grau da disciplina ser inserido
*
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada a ser preenchida.
*	segundo ponteiro referencia um tipo estruturado Disciplina não nulo.
*	situacao válida é composta de 2 caracteres não nulos, podendo tomar os valores:
* "AP" para *	condição de aluno AProvado, "RN" para condição de aluno Reprovado por Nota 
* e "RF" para *	condição Reprovado por Falta.
*	periodo valido é composto de 6 caracteres, deve vir no formato exemplificado a seguir: 
*	"2016.1" ou "2013.2" etc.
*	grau valido é caracterizado por um número (float) maior que zero (>0) e menor que 10 (<10), 
*	limitando-se a uma única casa decimal.
*
*$EAE Assertivas de saída esperadas
*	valem as assertivas estruturais para tipos de dados estruturados.
*	Todos os dados do aluno foram preenchidos na disciplina cursada com êxito.
*
*$.***********************************************************************/

DIC_tpCondRet DIC_setTodosOsCampos(DIC_tpDisciplinaCursada *pDisciplinaCursada, struct disciplina *disciplina, char *situacao, char *periodo, float grau);

/***********************************************************************
*$FC Função: DIC_getDisciplina
*$ED Descrição da função
*	pega a disciplina do do tipo estruturado DisciplinaCursada
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*	$P	disciplina: ponteiro para a variável que receberá o struct
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro corrente referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada.
*	segundo ponteiro referencia um tipo estruturado Disciplina.
*
*$EAE Assertivas de saída esperadas
*	**disciplina = endereço de pDisciplinaCursada->disciplina
*$.***********************************************************************/

DIC_tpCondRet DIC_getDisciplina(DIC_tpDisciplinaCursada *pDisciplinaCursada, struct disciplina  **disciplina);

/***********************************************************************
*$FC Função: DIC_getGrau
*$ED Descrição da função
*	obtem o grau de um aluno em uma disciplina 
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*	$P	grau: ponteiro para a variável float que receberá o grau
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro corrente referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada.
*
*$EAE Assertivas de saída esperadas
*	retorna endereço para valor do grau de aluno em disciplina cursada por referência.
*$.***********************************************************************/

DIC_tpCondRet DIC_getGrau(DIC_tpDisciplinaCursada * pDisciplinaCursada, float* grau);

/***********************************************************************
*$FC Função: DIC_getSituacao
*$ED Descrição da função
*	obtém a situação de um aluno em uma disciplina
*$FV Valor retornado
*	DIC_CondRetOK
*   	DIC_CondRetParamInvalido
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*	$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*	$P	situacao: ponteiro para array situação na disciplina
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro corrente referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada.
*
*$EAE Assertivas de saída esperadas
*	retorna endereço para situacao do aluno em disciplina cursada por referência
*$.***********************************************************************/

DIC_tpCondRet DIC_getSituacao(DIC_tpDisciplinaCursada * pDisciplinaCursada, char* situacao);

/***********************************************************************
*$FC Função: DIC_getPeriodo
*$ED Descrição da função
*	obtem o período que um aluno cursou uma disciplina
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	periodo: ponteiro para ym array de caracteres que receberá o período da disciplina cursada
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro corrente referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada.
*
*$EAE Assertivas de saída esperadas
*	retorna período em que uma disciplina foi cursada pelo aluno por referência
*
*$.***********************************************************************/

DIC_tpCondRet DIC_getPeriodo(DIC_tpDisciplinaCursada * pDisciplinaCursada, char* situacao);

/***********************************************************************
*$FC Função: DIC_getTodosOsCampos
*$ED Descrição da função
*	Retorna por referência todos as informações referentes ao aluno em uma disciplina, sendo elas:
*	ponteiro para disciplina cursada, situação do aluno na disciplina , período cursado e grau referente.
*$FV Valor retornado
*	DIC_CondRetOK
*	DIC_CondRetRecebeuPonteiroNulo
*$EP Parametros
*$P	pDisciplinaCursada: Endereço do ponteiro para tipo estruturado DisciplinaCursada.
*$P	disciplina: endereco do ponteio para tipo estruturado disciplina a ser inserida.
*$P	situacao: situação na disciplina a ser retornada
*$P	periodo: periodo da disciplina a ser retornado
*$P	grau: grau da disciplina ser retornado
$EAE Assertivas de entrada
*	valem as assertivas estruturais para tipos de dados estruturados.
*	primeiro ponteiro corrente referenecia um endereço não nulo para tipo 
* estruturado DisciplinaCursada.
*
*$EAE Assertivas de saída esperadas
*	foram retornados todos os dados referentes ao aluno na disciplina cursada por referência
*
*$.***********************************************************************/
DIC_tpCondRet DIC_getTodosOsCampos(DIC_tpDisciplinaCursada *pDisciplinaCursada, struct disciplina *disciplina, char *situacao, char *periodo, float *grau);

#undef DISCIPLINACURSADA_EXT

/********** Fim do módulo de definição: Módulo DisciplinaCursada **********/


#else
#endif
