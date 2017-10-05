/***************************************************************************
 *  $MCD Modulo de implementacao: Modulo Historico
 *
 *	Arquivo gerado
 *  Letras identificadoras:      HIS
 *
 *  Autores: 
*		 mc - Matheus Caldas
 *	     bp - Bruno Pedrazza
 *	     pg - Pedro Gomes
 *	     va - Vinícius Arcoverde
 *	     lf - Leon França
 *	     gc - Gabriel Costa
 *  $HA Historico de evolucao:
 *  Versao       Autor		Data            Observacoes
 *	0.0.1		  mc       28/09/17			Criacao inicial do modulo
 *	0.0.2		  va       04/09/17			inicio implementacao de imprimeHistorico
 *	0.0.3		  gc       04/09/17			Implementacao de getHistórico do perido, getHistoricoCompleto, getCrPeriodo,getCrcompleto
 *	0.0.4		  va       05/09/17			Implementacao de imprimeHistorico
 *  0.0.5		  gc	   05/10/17			Implementação de adicionarDisciplinaCursada
 *  $ED Descrição do módulo
 *     Este módulo implementa um conjunto de funcoes para criar e manipular
 *     atributos do módulo Historico.
 *
 *
 *
 ***************************************************************************/

/* Inclusões do compilador */
#include  <stdio.h>
#include  <string.h>
#include  <malloc.h>
#include "listas.h"
#include "disciplina.h"
#include "DISCIPLINACURSADA.h"


/* Inclusão do respectivo módulo de definição */
#define HISTORICO_OWN
#include "HISTORICO.H"
#undef HISTORICO_OWN

/***********************************************************************
 *
 *  $TC Tipo de dados: HIS que define a estrutura do tipo HISTORICO
 *
 *	$ED Descrição do tipo
 *		Descreve a estrutura de um HISTORICO
 *
 ***********************************************************************/

struct HIS_tagHistorico  {   
	//TODO
	List *disciplinasCursadas;
	//Lista<DisplinaCursadas>;
};


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: HIS Criar Historico                                                 *
 **************************************************************************/

HIS_tpCondRet HIS_criarHistorico (HIS_tpHistorico ** pHistorico)
{
	LIS_tpCondRet retCriacao;

	*pHistorico = NULL;
    *pHistorico = ( HIS_tpHistorico * ) malloc( sizeof( HIS_tpHistorico )) ;

    if( *pHistorico == NULL ){
		return HIS_CondRetFaltouMemoria ;
		}
		
	retCriacao = createList(&((*pHistorico)->disciplinasCursadas));


	if(retCriacao  != LIS_CondRetOK){
		return HIS_CondRetProblemaListaDisciplinas;
	}


    return HIS_CondRetOK ;
} 
/* Fim funcao: HIS Criar Historico */


/**************************************************************************
 *                                                                        *
 * Funcao: HIS remove removeHistorico                                            	  *
 **************************************************************************/
 
HIS_tpCondRet HIS_removeHistorico (HIS_tpHistorico ** pHistorico)
{
	if (*pHistorico == NULL)
		return HIS_CondRetRecebeuPonteiroNulo; 

	free(*pHistorico);
	*pHistorico = NULL;
	return HIS_CondRetOK ;
}
 /* Fim funcao: HIS remove Historico */

 /**************************************************************************
 *                                                                        *
 * Funcao: HIS get historico completo                                  	  *
 **************************************************************************/

HIS_tpCondRet HIS_getHistoricoCompleto(HIS_tpHistorico * pHistorico, List* disciplinasCursadas)
{
	if (pHistorico == NULL || disciplinasCursadas == NULL)
		return HIS_CondRetRecebeuPonteiroNulo;	

	disciplinasCursadas = pHistorico->disciplinasCursadas;
	return HIS_CondRetOK;
}
/* Fim funcao: HIS remove Historico */

/**************************************************************************
*                                                                        *
* Funcao: HIS get historico do período                                 	  *
**************************************************************************/

HIS_tpCondRet HIS_getHistoricoDoPeriodo(HIS_tpHistorico * pHistorico, char* periodo, List* disciplinas)
{
	// Inicialização de variáveis
	int listResponse = -1;
	int functionResponse = -1;
	char* discPeriodo = (char*) malloc(sizeof(char) * 7);
	Disciplina *disciplina = NULL;
	DIC_tpDisciplinaCursada *disciplinaCursada = NULL;
	List *disciplinasPeriodo = NULL;
	HIS_tpHistorico copiaHistorico;

	// Verificação dos parâmetros
	if (pHistorico == NULL || disciplinas == NULL) {
		free(discPeriodo);
		free(disciplina);
		free(disciplinaCursada);
		free(disciplinasPeriodo);
		return HIS_CondRetRecebeuPonteiroNulo;
	}

	if (strlen(periodo) != 6) {
		free(discPeriodo);
		free(disciplina);
		free(disciplinaCursada);
		free(disciplinasPeriodo);
		return HIS_CondRetParamInvalido;
	}

	// Copia o valor de pHistorico para uma variável local
	copiaHistorico = *pHistorico;

	// Apenas pra alocar o struct na memória
	functionResponse = DIS_gera_param(&disciplina, "X", "X", 0, "X", "X");

	if (functionResponse != DIS_CondRetOK) {
		free(discPeriodo);
		free(disciplina);
		free(disciplinaCursada);
		free(disciplinasPeriodo);
		return HIS_CondRetErroInterno;
	}

	functionResponse = DIC_criarDisciplinaCursada(&disciplinaCursada, disciplina, "AP", "2017.2", 10.0);

	if (functionResponse != DIC_CondRetOK) {
		free(discPeriodo);
		free(disciplina);
		free(disciplinaCursada);
		free(disciplinasPeriodo);
		return HIS_CondRetErroInterno;
	}

	// Instancia uma nova lista vazia
	functionResponse = createList(&disciplinasPeriodo);

	if (functionResponse != LIS_CondRetOK) {
		free(discPeriodo);
		free(disciplina);
		free(disciplinaCursada);
		free(disciplinasPeriodo);
		return HIS_CondRetErroInterno;
	}

	// Percorre a lista até que ela esteja vazia
	while (listResponse != LIS_CondRetListaVazia) {
		listResponse = pop_front(copiaHistorico.disciplinasCursadas, (void**) disciplinaCursada);

		if (listResponse != LIS_CondRetOK && listResponse != LIS_CondRetListaVazia) {
			free(discPeriodo);
			free(disciplina);
			free(disciplinaCursada);
			free(disciplinasPeriodo);
			return HIS_CondRetErroInterno;
		}

		functionResponse = DIC_getPeriodo(disciplinaCursada, discPeriodo);

		if (functionResponse != DIC_CondRetOK) {
			free(discPeriodo);
			free(disciplina);
			free(disciplinaCursada);
			free(disciplinasPeriodo);
			return HIS_CondRetErroInterno;
		}

		if (strcmp(periodo, discPeriodo) == 0) {
			functionResponse = push_back(disciplinasPeriodo, disciplinaCursada);

			if (functionResponse != DIC_CondRetOK) {
				free(discPeriodo);
				free(disciplina);
				free(disciplinaCursada);
				free(disciplinasPeriodo);
				return HIS_CondRetErroInterno;
			}
		}
	}

	disciplinas = disciplinasPeriodo;
	free(discPeriodo);
	free(disciplina);
	free(disciplinaCursada);
	free(disciplinasPeriodo);

	return HIS_CondRetOK;
}
/* Fim funcao: HIS get historico completo */

/**************************************************************************
*                                                                        *
* Funcao: HIS get cr total                                  			 *
**************************************************************************/

HIS_tpCondRet HIS_getCrTotal(HIS_tpHistorico * pHistorico, float* cr)
{
	// Inicialização de variáveis
	int functionResponse = -1;
	int listResponse = -1;

	float grau = 0;
	float somaGraus = 0;	
	
	int creditos = 0;
	int somaCreditos = 0;

	float crTotal = 0;

	Disciplina *disciplina = NULL;
	DIC_tpDisciplinaCursada *disciplinaCursada = NULL;
	List *disciplinasPeriodo = NULL;
	HIS_tpHistorico copiaHistorico;

	// Verificação dos parâmetros
	if (pHistorico == NULL || cr == NULL)
		return HIS_CondRetRecebeuPonteiroNulo;

	// Copia o valor de pHistorico para uma variável local
	copiaHistorico = *pHistorico;

	// Apenas pra alocar o struct na memória
	functionResponse = DIS_gera_param(&disciplina, "X", "X", 0, "X", "X");

	if (functionResponse != DIS_CondRetOK) {
		free(disciplina);
		free(disciplinaCursada);
		free(disciplinasPeriodo);
		return HIS_CondRetErroInterno;
	}

	functionResponse = DIC_criarDisciplinaCursada(&disciplinaCursada, disciplina, "AP", "2017.2", 10.0);

	if (functionResponse != DIC_CondRetOK) {
		free(disciplina);
		free(disciplinaCursada);
		free(disciplinasPeriodo);
		return HIS_CondRetErroInterno;
	}

	// Percorre a lista até que ela esteja vazia
	while (listResponse != LIS_CondRetListaVazia) {
		listResponse = pop_front(copiaHistorico.disciplinasCursadas, (void**) disciplinaCursada);

		if (listResponse != LIS_CondRetOK && listResponse != LIS_CondRetListaVazia) {
			free(disciplina);
			free(disciplinaCursada);
			free(disciplinasPeriodo);
			return HIS_CondRetErroInterno;
		}

		functionResponse = DIC_getDisciplina(disciplinaCursada, disciplina);

		if (functionResponse != DIC_CondRetOK) {
			free(disciplina);
			free(disciplinaCursada);
			free(disciplinasPeriodo);
			return HIS_CondRetErroInterno;
		}
		
		functionResponse = DIC_getGrau(disciplinaCursada, &grau);

		if (functionResponse != DIC_CondRetOK) {
			free(disciplina);
			free(disciplinaCursada);
			free(disciplinasPeriodo);
			return HIS_CondRetErroInterno;
		}

		functionResponse = DIS_get_creditos(disciplina, &creditos);

		if (functionResponse != DIS_CondRetOK) {
			free(disciplina);
			free(disciplinaCursada);
			free(disciplinasPeriodo);
			return HIS_CondRetErroInterno;
		}

		somaGraus += grau;
		somaCreditos += creditos;
	}

	crTotal = somaGraus / somaCreditos;
	*cr = crTotal;

	free(disciplina);
	free(disciplinaCursada);
	free(disciplinasPeriodo);

	return HIS_CondRetOK;
}
/* Fim funcao: HIS get historico completo */

/**************************************************************************
*                                                                        *
* Funcao: HIS get cr do período		                                  	  *
**************************************************************************/
HIS_tpCondRet HIS_getCrDoPeriodo(HIS_tpHistorico * pHistorico, char * periodo, float *cr) {
	// Inicialização de variáveis
	int response = -1;
	char* periodoDisc = (char*)malloc(sizeof(char) * 7);

	float grau = 0;
	float somaGraus = 0;

	int creditos = 0;
	int somaCreditos = 0;

	float crTotal = 0;

	Disciplina *disciplina = NULL;
	DIC_tpDisciplinaCursada *disciplinaCursada = NULL;
	List *disciplinasPeriodo = NULL;
	HIS_tpHistorico copiaHistorico;

	// Verificação dos parâmetros
	if (pHistorico == NULL || cr == NULL)
		return HIS_CondRetRecebeuPonteiroNulo;

	// Copia o valor de pHistorico para uma variável local
	copiaHistorico = *pHistorico;

	// Apenas pra alocar o struct na memória
	DIS_gera_param(&disciplina, "X", "X", 0, "X", "X");
	DIC_criarDisciplinaCursada(&disciplinaCursada, disciplina, "AP", "2017.2", 10.0);

	// Percorre a lista até que ela esteja vazia
	while (response != LIS_CondRetListaVazia) {
		response = pop_front(copiaHistorico.disciplinasCursadas, (void**) disciplinaCursada);
		DIC_getDisciplina(disciplinaCursada, disciplina);

		DIC_getGrau(disciplinaCursada, &grau);
		DIC_getPeriodo(disciplinaCursada, periodoDisc);
		DIS_get_creditos(disciplina, &creditos);

		if (strcmp(periodoDisc, periodo) == 0) {
			somaGraus += grau;
			somaCreditos += creditos;
		}
	}

	crTotal = somaGraus / somaCreditos;
	*cr = crTotal;

	free(disciplina);
	free(disciplinaCursada);
	free(disciplinasPeriodo);

	return HIS_CondRetOK;
}

/* Fim funcao: HIS get cr do período */

/**************************************************************************
*                                                                        *
* Funcao: HIS get disciplinas reprovado por falta                     	  *
**************************************************************************/

HIS_tpCondRet HIS_getDisciplinasReprovadoPorFalta(HIS_tpHistorico * pHistorico, List* disciplinas)
{
	// Inicialização de variáveis
	int response = -1;
	char* situacao = (char*)malloc(sizeof(char) * 3);
	Disciplina *disciplina = NULL;
	DIC_tpDisciplinaCursada *disciplinaCursada = NULL;
	List *disciplinasPeriodo = NULL;
	HIS_tpHistorico copiaHistorico;

	// Verificação dos parâmetros
	if (pHistorico == NULL || disciplinas == NULL)
		return HIS_CondRetRecebeuPonteiroNulo;

	// Copia o valor de pHistorico para uma variável local
	copiaHistorico = *pHistorico;

	// Apenas pra alocar o struct na memória
	DIS_gera_param(&disciplina, "X", "X", 0, "X", "X");
	DIC_criarDisciplinaCursada(&disciplinaCursada, disciplina, "AP", "2017.2", 10.0);

	// Instancia uma nova lista vazia
	createList(&disciplinasPeriodo);

	// Percorre a lista até que ela esteja vazia
	while (response != LIS_CondRetListaVazia) {
		response = pop_front(copiaHistorico.disciplinasCursadas, (void**) disciplinaCursada);
		DIC_getSituacao(disciplinaCursada, situacao);

		if (strcmp(situacao, "RP") == 0) {
			push_back(disciplinasPeriodo, disciplinaCursada);
		}
	}

	disciplinas = disciplinasPeriodo;
	free(situacao);
	free(disciplina);
	free(disciplinaCursada);
	free(disciplinasPeriodo);

	return HIS_CondRetOK;
}
 /* Fim funcao: HIS reprovados por falta */

/**************************************************************************
*                                                                        *
* Funcao: HIS get disciplinas trancadas                    	  *
**************************************************************************/

HIS_tpCondRet HIS_getDisciplinasTrancadas(HIS_tpHistorico * pHistorico, List* disciplinas)
{
	// Inicialização de variáveis
	int response = -1;
	char* situacao = (char*)malloc(sizeof(char) * 3);
	Disciplina *disciplina = NULL;
	DIC_tpDisciplinaCursada *disciplinaCursada = NULL;
	List *disciplinasPeriodo = NULL;
	HIS_tpHistorico copiaHistorico;

	// Verificação dos parâmetros
	if (pHistorico == NULL || disciplinas == NULL)
		return HIS_CondRetRecebeuPonteiroNulo;

	// Copia o valor de pHistorico para uma variável local
	copiaHistorico = *pHistorico;

	// Apenas pra alocar o struct na memória
	DIS_gera_param(&disciplina, "X", "X", 0, "X", "X");
	DIC_criarDisciplinaCursada(&disciplinaCursada, disciplina, "AP", "2017.2", 10.0);

	// Instancia uma nova lista vazia
	createList(&disciplinasPeriodo);

	// Percorre a lista até que ela esteja vazia
	while (response != LIS_CondRetListaVazia) {
		response = pop_front(copiaHistorico.disciplinasCursadas, (void**) disciplinaCursada);
		DIC_getSituacao(disciplinaCursada, situacao);

		if (strcmp(situacao, "TR") == 0) {
			push_back(disciplinasPeriodo, disciplinaCursada);
		}
	}

	disciplinas = disciplinasPeriodo;
	free(situacao);
	free(disciplina);
	free(disciplinaCursada);
	free(disciplinasPeriodo);

	return HIS_CondRetOK;
}
 /* Fim funcao: HIS trancadas */

/**************************************************************************
 *                                                                        *
 * Funcao: HIS imprimeHistorico                                            	  *
 **************************************************************************/
HIS_tpCondRet HIS_imprimeHistorico(HIS_tpHistorico * pHistorico, List* disciplinasCursadas)
{
	// Inicialização de variáveis
	int response = -1;
	int creditos = 0;
	float grau = 0; 

	char* situacao = (char*)malloc(sizeof(char) * 3);
	char* periodoDisc = (char*)malloc(sizeof(char) * 7);
	char* codigoDaDisc = (char*)malloc(sizeof(char) * 8);

	Disciplina *disciplina = NULL;
	DIC_tpDisciplinaCursada *disciplinaCursada = NULL;
	List *disciplinasPeriodo = NULL;
	HIS_tpHistorico copiaHistorico;

	FILE* f = fopen("historico.txt", "w");	

	if (f == NULL)
	{
		printf("Error opening file!\n");
		fclose(f);
		//return HIS_CondRetErroAoAbrirArquivo;
	}

	// Verificação dos parâmetros
	if(disciplinasCursadas == NULL || pHistorico == NULL)
		return HIS_CondRetRecebeuPonteiroNulo;

	// Apenas pra alocar o struct na memória
	DIS_gera_param(&disciplina, "X", "X", 0, "X", "X");
	DIC_criarDisciplinaCursada(&disciplinaCursada, disciplina, "AP", "2017.2", 10.0);
	

	while(response != LIS_CondRetListaVazia) 
	{
		response = pop_front(copiaHistorico.disciplinasCursadas, (void**) disciplinaCursada);
		DIC_getDisciplina(disciplinaCursada, &disciplina);

		DIC_getGrau(disciplinaCursada, &grau);
		DIC_getPeriodo(disciplinaCursada, periodoDisc);
		DIS_get_creditos(disciplina, &creditos);
		DIS_get_codigo(disciplina, &codigoDaDisc);

		/*fprintf(f, "Periodo: " + *periodoDisc);
		fprintf(f, "\n");
		fprintf(f, codigoDaDisc);
		fprintf(f, ": ");
		fprintf(f, "%f", grau);
		fprintf(f, "  ");
		fprintf(f, situacao);
		fprintf(f, "\n\n");*/
	}
	
	fclose(f);

	free(situacao);
	free(periodoDisc);
	free(codigoDaDisc);
	free(situacao);
	free(disciplina);
	free(disciplinaCursada);
	free(disciplinasPeriodo);

	return HIS_CondRetOK;
}

 /* Fim funcao: HIS imprime Historico */

/**************************************************************************
 *                                                                        *
 * Funcao: HIS adiciona disciplina cursada                                *
 **************************************************************************/
HIS_tpCondRet HIS_adicionaDisciplinaCursada(HIS_tpHistorico * pHistorico, DIC_tpDisciplinaCursada* disc ) {
	int listResponse = -1;
	
	if (pHistorico == NULL || disc == NULL) {
		return HIS_CondRetRecebeuPonteiroNulo;
	}

	listResponse = push_front(pHistorico->disciplinasCursadas, disc);
	if (listResponse != LIS_CondRetOK) {
		return HIS_CondRetErroInterno;
	}

	return HIS_CondRetOK;
}


/********** Fim do modulo de implementacao: Modulo Historico **********/
