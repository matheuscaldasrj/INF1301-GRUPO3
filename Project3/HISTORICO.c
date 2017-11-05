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
 *  1.0.0		  bp       02/11/17			Implementação printHistoricoCompleto, printHistoricoPeriodo, getCrAcumulado, getCrPeriodo
 *	1.0.1		  bp	   02/11/17			Implementacao montaNomeArq
 *	1.0.2		  mc	   03/11/17			Implmentacao da adicionaDisciciplina e mudanca na adicionaDisciplina cursada para ser um método interno
 *
 *	1.0.2		  bp       04/11/17			Ajustando ondicoes de retorno getCR	
 *  1.0.3         bp       04/11/17			Ajustando printHistoricoCompleto e printHistoricoPeriodo
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



/* Declaração funções internas */

static HIS_tpCondRet HIS_getCrAcumulado (FILE *historico, float *CR);
static HIS_tpCondRet HIS_getCrPeriodo (FILE *historico, char *periodo, float *CR);
static char* HIS_montaNomeArq (unsigned int matricula);
static HIS_tpCondRet HIS_adicionaDisciplinaCursada(HIS_tpHistorico * pHistorico, DIC_tpDisciplinaCursada* disc );

/* Fim declaração funções internas */



/***********************************************************************
 *
 *  $TC Tipo de dados: HIS que define a estrutura do tipo HISTORICO
 *
 *	$ED Descrição do tipo
 *		Descreve a estrutura de um HISTORICO
 *
 ***********************************************************************/

struct HIS_tagHistorico  {   
	List *disciplinasCursadas;
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
 * Funcao: HIS Salva Historico                                                 *
 **************************************************************************/

HIS_tpCondRet HIS_salvaHistoricoEmArquivo (HIS_tpHistorico ** pHistorico, unsigned int matricula)
{
	// Inicialização de variáveis
	int creditos = 0;
	float grau = 0; 
	char situacao[3];
	char periodoDisc[7];

	// por malloc porque a funcao da disciplina exige ** char (?)
	char* codigoDaDisc = (char*)malloc(sizeof(char) * 8);
	char* nome = (char*)malloc(sizeof(char) * 40);

	Disciplina *pDisciplina;
 
	List* list;
	List *listAux;
	void *retVoid;
	DIC_tpDisciplinaCursada *pDisciplinaCursada;
	char *nomeDoArquivo = HIS_montaNomeArq(matricula);
	FILE* file = fopen(nomeDoArquivo, "a"); 
	

	HIS_tpCondRet ret = HIS_getHistoricoCompleto(*pHistorico, &list);

	createList(&listAux);
 
	  if (file == NULL)
	  {
		printf("Error opening file!\n");
		return HIS_CondRetErroAoAbrirArquivo;
	  }


	//ussando pop_back e re-adcionando pois o next não está legal
	while(pop_back(list,&retVoid) != LIS_CondRetListaVazia){
		pDisciplinaCursada = (struct DIC_tagDisciplinaCursada*)retVoid;


		DIC_getGrau(pDisciplinaCursada, &grau);
		DIC_getPeriodo(pDisciplinaCursada, periodoDisc);
		DIC_getSituacao(pDisciplinaCursada,situacao);
		DIC_getDisciplina(pDisciplinaCursada,&pDisciplina);
		DIS_get_nome(pDisciplina,&nome);
		DIS_get_codigo(pDisciplina,&codigoDaDisc);
		DIS_get_creditos(pDisciplina,&creditos);

		fprintf(file,"%s %s %.1f %s %d\n", periodoDisc, codigoDaDisc, grau, situacao, creditos);

		//adicionando de volta ao historico
		push_back(listAux,pDisciplinaCursada);
	}
	
	(*pHistorico)->disciplinasCursadas = listAux;
	fclose(file);
	return HIS_CondRetOK;
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

HIS_tpCondRet HIS_getHistoricoCompleto(HIS_tpHistorico * pHistorico, List** disciplinasCursadas)
{
	if (pHistorico == NULL || disciplinasCursadas == NULL)
		return HIS_CondRetRecebeuPonteiroNulo;	

	*disciplinasCursadas = pHistorico->disciplinasCursadas;
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

		functionResponse = DIC_getDisciplina(disciplinaCursada, &disciplina);

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
		DIC_getDisciplina(disciplinaCursada, &disciplina);

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
/* Fim funcao: HIS adiciona disciplina cursada */

/**************************************************************************
 * Funcao: HIS adiciona disciplina ao historico                           *
 **************************************************************************/
HIS_tpCondRet HIS_adicionaDisciplina(HIS_tpHistorico * pHistorico , Disciplina *disciplina, char *situacao, char* periodo, float grau ) {

	DIC_tpDisciplinaCursada * disciplinaCursada;
	DIC_tpCondRet retCriacao;
	HIS_tpCondRet retAdicaoDisciplinaCursada;
	
	if (pHistorico == NULL || disciplina == NULL) {
		return HIS_CondRetRecebeuPonteiroNulo;
	}

	retCriacao = DIC_criarDisciplinaCursada(&disciplinaCursada, disciplina, situacao, periodo, grau);

	if(retCriacao != DIC_CondRetOK) {
		return HIS_CondRetProblemaListaDisciplinas;
	}

	return HIS_adicionaDisciplinaCursada(pHistorico, disciplinaCursada);
	

}
/* Fim funcao: HIS adiciona disciplina*/


/**************************************************************************
 *                                                                        *
 * Funcao: HIS printHistoricoCompleto                                     *
 **************************************************************************/

HIS_tpCondRet HIS_printHistoricoCompleto (unsigned int matricula){
	FILE *historico;
	HIS_tpCondRet respostaCR;
	float CR;
	unsigned int creditos;
	char periodo[tamPeriodo], disciplina[tamDisciplina], situacao[tamSituacao], grau[tamGrau], periodoCorrente[tamPeriodo] ;
	
	historico = fopen(HIS_montaNomeArq(matricula),"r");
	if (historico == NULL) {printf("\nNao foi encontrado registro de historico do aluno de matricula %u.\n",matricula); return HIS_CondRetErroAoAbrirArquivo;}
	
	respostaCR = HIS_getCrAcumulado (historico,&CR);
	if (respostaCR != HIS_CondRetOK) {fclose(historico); return respostaCR;}

	if (CR == -1){
		printf("\nAluno de matricula %u nao realizou nenhuma disciplina.\n",matricula);
		fclose(historico);
		return HIS_CondRetOK;
	}

	rewind(historico);
	printf("\n\t\tCR Acumulado : %.1f\n\n",CR);
	
	printf("Periodo\t\tDisciplina\tGrau\tSituacao\tCreditos\n");
	
	while (fscanf(historico,"%s%s%s%s%u",periodo,disciplina,grau,situacao,&creditos) == 5){
		if (strcmp(periodo,periodoCorrente) != 0){
			strcpy(periodoCorrente,periodo);
			printf("\n");
		}
		printf("%s\t\t%s\t\t%s\t%s\t\t%u\n",periodo, disciplina, grau, situacao, creditos);
	}

	printf("\n");	
	fclose(historico);
	return HIS_CondRetOK;
}

/* Fim funcao: HIS printHistoricoCompleto */


/**************************************************************************
 *                                                                        *
 * Funcao: HIS printHistoricoPeriodo                                      *
 **************************************************************************/

HIS_tpCondRet HIS_printHistoricoPeriodo (unsigned int matricula, char *periodo){
	FILE *historico;
	HIS_tpCondRet respostaCR;
	float CR;
	unsigned int creditos;
	char periodoArq[tamPeriodo], disciplina[tamDisciplina], situacao[tamSituacao], grau[tamGrau] ;

	historico = fopen(HIS_montaNomeArq(matricula),"r");
	if (historico == NULL) {printf("\nNao foi encontrado registro de historico do aluno de matricula %u.\n",matricula); return HIS_CondRetErroAoAbrirArquivo;}
	
	respostaCR = HIS_getCrPeriodo (historico,periodo,&CR);
	if (respostaCR != HIS_CondRetOK) {fclose(historico); return respostaCR;}

	if (CR == -1){
		printf("\nAluno nao matriculado no periodo %s\n",periodo);
		fclose(historico);
		return HIS_CondRetOK;
	}

	rewind(historico);
	printf("\n\t\tCR Periodo %s : %.1f\n\n",periodo,CR);
	
	printf("Periodo\t\tDisciplina\tGrau\tSituacao\tCreditos\n\n");
	while (fscanf(historico,"%s%s%s%s%u",periodoArq,disciplina,grau,situacao,&creditos) == 5){
		if (strcmp(periodoArq,periodo) == 0)
			printf("%s\t\t%s\t\t%s\t%s\t\t%u\n",periodoArq, disciplina, grau, situacao, creditos);
	}
	
	printf("\n");	
	fclose(historico);
	return HIS_CondRetOK;
}

/* Fim funcao: HIS printHistoricoPeriodo */


/**************************************************************************
 *                                                                        *
 * Funcao interna: HIS getCrAcumulado                                     *
 **************************************************************************/

static HIS_tpCondRet HIS_getCrAcumulado (FILE *historico, float *CR){
	char lixo[10];
	float grau, cred, somaCred=0, somaGrau=0;

	while (fscanf(historico,"%s %s %f %s %f",&lixo,&lixo,&grau,&lixo,&cred) == 5){
		somaGrau += grau*cred;
		somaCred += cred;
	}

	if (somaCred == 0){
		*CR = -1;
		return HIS_CondRetOK;
	}

	*CR = somaGrau/somaCred;

	if (*CR < 0 || *CR > 10) return HIS_CondRetErroInterno;

	return HIS_CondRetOK;
}

/* Fim funcao: HIS getCrAcumulado */


/**************************************************************************
 *                                                                        *
 * Funcao interna: HIS getCrPeriodo                                       *
 **************************************************************************/

static HIS_tpCondRet HIS_getCrPeriodo (FILE *historico, char *periodo, float *CR){
	char lixo[10], periodoaux[tamPeriodo];
	float grau, cred, somaCred=0, somaGrau=0;

	if (periodo == NULL) return  HIS_CondRetErroInterno;

	while (fscanf(historico," %s %s %f %s %f",&periodoaux,&lixo,&grau,&lixo,&cred) == 5){
		if (!strcmp(periodoaux,periodo)){
			somaGrau += grau*cred;
			somaCred += cred;
		}
	}

	if (somaCred == 0){
		*CR = -1;
		return HIS_CondRetOK;
	}

	*CR = somaGrau/somaCred;
	if (*CR < 0 || *CR > 10) return HIS_CondRetErroInterno;

	return HIS_CondRetOK;
}

/* Fim funcao: HIS getCrPeriodo */

/**************************************************************************
 *                                                                        *
 * Funcao interna: HIS montaNomeArq                                       *
 **************************************************************************/
static char* HIS_montaNomeArq (unsigned int matricula){
	char *nomeArq, mat[tamMatricula];

	nomeArq = (char*) malloc (sizeof(char)*TAM_NOME_ARQ);
	if (nomeArq == 	NULL) return NULL;

	sprintf(mat,"%u",matricula);
	strcpy(nomeArq,"Historico\\");
	strcat(mat,".txt");
	strcat(nomeArq,mat);
	return nomeArq;
}

/* Fim funcao: HIS montaNomeArq */

/********** Fim do modulo de implementacao: Modulo Historico **********/
