/***************************************************************************
 *  $MCD Modulo de implementacao: Modulo Sala
 *
 *	Arquivo gerado
 *  Letras identificadoras:      SAL
 *
 *  Autores: mc - Matheus Caldas
 *	     bp - Bruno Pedrazza
 *	     pg - Pedro Gomes
 *  $HA Historico de evolucao:
 *     Versao       Autor          Data            Observacoes
 *      1.0.0         mc        30/08/2017   Inicio do desenvolvimento
 *	    1.1.0         bp        31/08/2017   Implementacao funcoes getNumero, getPredio, getAndar
 *	    1.2.0	      pg        31/08/2017   Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
 *      1.2.1         bp        02/09/2017   Mudanca nas condicoes de retorno funcoes getNumero, getPredio, getAndar, setCodigo
 *      1.2.2         mc        02/09/2017   Implementacao funcoes setQtdComputadores e getQtdComputadores
 *		1.2.3	      bp		03/09/2017	 Implementacao funcoes getELaboratorio e setELaboratorio
 *		1.2.4         pg		04/09/2017	 Ajustando reservaSala e incluindo novos defines
 *		1.2.5	      bp		04/09/2017   Implementacao resetDisponibilidade, adicao de sábados e novos defines
 *		1.2.6	      pg		04/09/2017   Ajustando reservaSala com nova condRet
 *		1.2.7	      pg		05/09/2017   Ajustes menores de codumentação.
 *		1.2.8		  mc        07/09/2017	 Implementação básica da criaSala, agora recebendo os parametros.
 *      1.2.9         pg        07/09/2017   Adicionando removeSala
 *		1.3.0         bp        07/09/2017	 Ajeitando ponteiros e consicoes de retorno de criarSala e removeSala
 *		1.3.1		  bp		07/09/2017	 Implementacao funcoes imprimeSala e imprimeMatriz
 *  $ED Descrição do módulo
 *     Este módulo implementa um conjunto de funcoes para criar e manipular
 *     atributos do módulo Sala.
 *
 *
 *
 ***************************************************************************/

/* Inclusões do compilador */
#include  <stdio.h>
#include  <string.h>
#include  <malloc.h>



/* Inclusão do respectivo módulo de definição */

#define SALA_OWN
#include "SALA.H"
#undef SALA_OWN

/***********************************************************************
 *
 * Tipo de dados: SAL que define a estrutura do tipo SALA
 *
 ***********************************************************************/

struct SAL_tagSala  {   
    /* Código da sala, ex: L232,
     indicando 'L' o prédio e 232 o número */
	char codigo[tamCodigoSala];

    /* Número máximo de alunos que a sala comporta */
	int maxAlunos;

	/* Indica se a sala é laboratório: 1 se é 0 se não */
	int eLaboratorio;

     /* Matriz de disponibilidade onde 1 representa sala "ocupada"
        e 0 "livre", assim, por exemplo, a sala estaria ocupada
        segunda e quarta (7-9) e
        terca e quinta (21-23)
        |Segunda|Terca|Quarta|Quinta|Sexta|Sábado|
        7|  1    |  0  |  1   |  0   |  0  |  0  |
        8|  1    |  0  |  1   |  0   |  0  |  0  |
        9|  0    |  0  |  0   |  0   |  0  |  0  |
       10|  0    |  0  |  0   |  0   |  0  |  0  |
       11|  0    |  0  |  0   |  0   |  0  |  0  |
       12|  0    |  0  |  0   |  0   |  0  |  0  |
       13|  0    |  0  |  0   |  0   |  0  |  0  |
       14|  0    |  0  |  0   |  0   |  0  |  0  |
       15|  0    |  0  |  0   |  0   |  0  |  0  |
       16|  0    |  0  |  0   |  0   |  0  |  0  |
       17|  0    |  0  |  0   |  0   |  0  |  0  |
       18|  0    |  0  |  0   |  0   |  0  |  0  |
       19|  0    |  0  |  0   |  0   |  0  |  0  |
       20|  0    |  0  |  0   |  0   |  0  |  0  |
       21|  0    |  1  |  0   |  1   |  0  |  0  |
       22|  0    |  1  |  0   |  1   |  0  |  0  |
       --------------------------------------
     */
	int disponibilidade[HORARIOS][DIAS];

};


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: SAL Criar sala                                                 *                                                                 *
 **************************************************************************/

SAL_tpCondRet SAL_criarSala (SAL_tpSala ** pSala,
							 char *codigo,
							 int maxAlunos,
							 int eLaboratorio)
{
	SAL_tpCondRet retorno;

	*pSala = NULL;
    *pSala = ( SAL_tpSala * ) malloc( sizeof( SAL_tpSala )) ;
    
    if( *pSala == NULL )
    	return SAL_CondRetFaltouMemoria ;
    
	retorno = SAL_setCodigo(*pSala,codigo);
	if (retorno != SAL_CondRetOK) return retorno;
	retorno = SAL_setMaxAlunos(*pSala,maxAlunos);
	if (retorno != SAL_CondRetOK) return retorno;
	retorno = SAL_setELaboratorio(*pSala,eLaboratorio);
	if (retorno != SAL_CondRetOK) return retorno;
	retorno = SAL_resetDisponibilidade(*pSala);
	if (retorno != SAL_CondRetOK) return retorno;

    return SAL_CondRetOK ;
} 
/* Fim funcao: SAL Criar sala */


/**************************************************************************
 *                                                                        *
 * Funcao: SAL remove sala                                            	  *
 **************************************************************************/
 
SAL_tpCondRet SAL_removeSala (SAL_tpSala * pSala)
{
	if (pSala != NULL)
	{
		free(pSala);
		pSala = NULL;
	}
	return SAL_CondRetOK ;
}
 /* Fim funcao: SAL remove sala */


/**************************************************************************
 *                                                                        *
 * Funcao: SAL imprime sala                                            	  *
 **************************************************************************/

SAL_tpCondRet SAL_printSala (SAL_tpSala * pSala)
{
	SAL_tpCondRet retorno;
	char codigo [tamCodigoSala];
	char predio [tamPredio];
	int andar, maxAlunos, eLab;

	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	retorno = SAL_getCodigo(pSala,codigo);
	if (retorno != SAL_CondRetOK)
		return retorno;
	retorno = SAL_getPredio(pSala,predio);
	if (retorno != SAL_CondRetOK)
		return retorno;
	retorno = SAL_getAndar(pSala,&andar);
	if (retorno != SAL_CondRetOK)
		return retorno;
	retorno = SAL_getMaxAlunos(pSala,&maxAlunos);
	if (retorno != SAL_CondRetOK)
		return retorno;
	retorno = SAL_getELaboratorio(pSala,&eLab);
	if (retorno != SAL_CondRetOK)
		return retorno;

	printf ("Sala %s\nLocalizada no %do andar do edificio %s\nCapacidade: %d alunos\n",codigo,andar,predio,maxAlunos);
	if (eLab)
		printf("É laboratorio\n");
	else 
		printf("Nao é laboratorio\n");

	return SAL_CondRetOK;	
}

/* Fim funcao: SAL imprime sala */


/**************************************************************************
 *                                                                        *
 * Funcao: SAL seta codigo da sala                                        *
 **************************************************************************/

SAL_tpCondRet SAL_setCodigo (SAL_tpSala * pSala, char *codigo)
{
	if (pSala == NULL){
		return SAL_CondRetRecebeuPonteiroNulo;
	}
	if (codigo == NULL || strlen(codigo) > tamCodigoSala)
		return SAL_CondRetParamInvalido;

	strcpy(pSala->codigo, codigo);

	return SAL_CondRetOK;
} 
/* Fim funcao: SAL seta codigo da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get codigo da sala                                         *
 **************************************************************************/

SAL_tpCondRet SAL_getCodigo (SAL_tpSala * pSala, char *codigo)
{
    if(pSala == NULL){
    	return SAL_CondRetRecebeuPonteiroNulo;
    }

    strcpy(codigo, pSala->codigo);

    if (codigo == NULL || strlen(codigo) > tamCodigoSala)
    	return SAL_CondRetErroEstrutura;

    return SAL_CondRetOK;
}
/* Fim funcao: Sal get codigo da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal set Max Alunos                                             *
 **************************************************************************/

SAL_tpCondRet SAL_setMaxAlunos (SAL_tpSala * pSala, int maxAlunos)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	if (maxAlunos <= 0)
		return SAL_CondRetParamInvalido;
	
	pSala->maxAlunos = maxAlunos;
	return SAL_CondRetOK;
}
/* Fim funcao: Sal set Max Alunos */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get Max Alunos                                             *
 **************************************************************************/

SAL_tpCondRet SAL_getMaxAlunos (SAL_tpSala * pSala, int *maxAlunos)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	*maxAlunos = pSala->maxAlunos;

	if (*maxAlunos <= 0)
		return SAL_CondRetErroEstrutura;

	return SAL_CondRetOK;
}
/* Fim funcao: Sal get Max Alunos */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal set eLaboratorio                                           *
 **************************************************************************/

SAL_tpCondRet SAL_setELaboratorio (SAL_tpSala * pSala, int eLaboratorio)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	if (eLaboratorio != 1 && eLaboratorio != 0)
		return SAL_CondRetParamInvalido;

	pSala->eLaboratorio = eLaboratorio;

	return SAL_CondRetOK;
}
/* Fim funcao: Sal set eLaboratorio */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get eLaboratorio                                           *
 **************************************************************************/

SAL_tpCondRet SAL_getELaboratorio (SAL_tpSala * pSala, int *eLaboratorio)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	*eLaboratorio = pSala->eLaboratorio;
	
	if (*eLaboratorio != 1 && *eLaboratorio != 0)
		return SAL_CondRetErroEstrutura;

	return SAL_CondRetOK;
}
/* Fim funcao: Sal get eLaboratorio */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get numero da sala                                         *
 **************************************************************************/

SAL_tpCondRet SAL_getNumero (SAL_tpSala * pSala, int *numero)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	if (pSala->codigo[4] == '\0'){
		*numero = (pSala->codigo[1]-'0')*100+(pSala->codigo[2]-'0')*10+(pSala->codigo[3]-'0');
		return SAL_CondRetOK;
	}
	else{
		*numero = (pSala->codigo[1]-'0')*1000+(pSala->codigo[2]-'0')*100+(pSala->codigo[3]-'0')*10+(pSala->codigo[4]-'0');
		return SAL_CondRetOK;
	}

	if (numero == NULL)
		return SAL_CondRetErroEstrutura;
}
/* Fim funcao: Sal get numero da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get predio da sala                                         *
 **************************************************************************/

SAL_tpCondRet SAL_getPredio (SAL_tpSala * pSala, char *predio)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	switch (pSala->codigo[0]){
		case 'L' :
			strcpy(predio, "Leme");
			break;
		case 'F' :
			strcpy(predio, "Frings");
			break;
		case 'K' :
			strcpy(predio, "Kennedy");
			break;
		case 'I' :
			strcpy(predio, "IAG");
			break;
		default :
			return SAL_CondRetErroEstrutura;
	}
	return SAL_CondRetOK;
}
/* Fim funcao: Sal get predio da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get andar da sala                                          *
 **************************************************************************/

SAL_tpCondRet SAL_getAndar (SAL_tpSala * pSala, int *andar)
{	
	SAL_tpCondRet retorno;
	int numero;

	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	retorno = SAL_getNumero (pSala,&numero);

	if (retorno != SAL_CondRetOK)
		return retorno;

	*andar = numero/100;

	return SAL_CondRetOK;
}
/* Fim funcao: Sal get andar da sala */



/**************************************************************************
 *                                                                        *
 * Funcao: Sal -Reserva a Sala                                            *
 **************************************************************************/

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim)
{	
	int hora = horaInicio - ajusteHora;
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	if( horaInicio < inicioDiaLetivo || horaInicio >= fimDiaLetivo || horaFim <= inicioDiaLetivo || horaFim > fimDiaLetivo || dia <inicioSemanaLetiva || dia > fimSemanaLetiva)
		return  SAL_CondRetParamInvalido;
	
	for(hora; hora < horaFim - ajusteHora; hora++)
	{
		if (pSala->disponibilidade[hora][dia] != salaLivre && pSala->disponibilidade[hora][dia] != salaReservada)
				return SAL_CondRetErroEstrutura;
		if(pSala->disponibilidade[hora][dia] == salaReservada)
		{
			return SAL_CondRetReservada;
		}
	}

	for(hora = horaInicio -ajusteHora; hora < horaFim -ajusteHora; hora++)
	{
		pSala->disponibilidade [hora][dia] = salaReservada;
	}
	return SAL_CondRetOK;
}

/* Fim funcao: Sal reserva Sala */


/**************************************************************************
 *                                                                        *  
 * Funcao: Sal reset disponibilidade Sala                                 *
 **************************************************************************/

SAL_tpCondRet SAL_resetDisponibilidade (SAL_tpSala * pSala){
	int i, j;
	if (pSala == NULL){
		return SAL_CondRetRecebeuPonteiroNulo; 
	}

	for (i = 0 ; i < HORARIOS ; i++){
		for (j = 0; j < DIAS ; j++){
			pSala->disponibilidade[i][j] = salaLivre;
		}
	}

	return SAL_CondRetOK;
}

/* Fim funcao: Sal reset disponibilidade Sala */

/***************************************************************************
 *                                                                         *
 * Funcao: Sal imprime matriz disponibilidade Sala                         *
 **************************************************************************/

SAL_tpCondRet SAL_printDisponibilidade(SAL_tpSala * pSala) {
	int i, j;
	if (pSala == NULL) 
		return SAL_CondRetRecebeuPonteiroNulo;
	printf("\n\tSegunda\tTerca\tQuarta\tQuinta\tSexta\tSabado\n");
	for (i = 0 ; i < HORARIOS ; i++){
		printf("%d-%d\t",i+7,i+8);
		for (j = 0 ; j < DIAS ; j++){
			if (pSala->disponibilidade[i][j] != salaLivre || pSala->disponibilidade[i][j] != salaReservada)
				return SAL_CondRetErroEstrutura;
			if (pSala->disponibilidade[i][j] == salaReservada)
				printf("XXXXXX\t");
			else
				printf("\t");
		}
		printf("\n");
	}
	printf("\n");
	
	return SAL_CondRetOK;
}

/* Fim funcao: Sal reset disponibilidade Sala */

/***************************************************************************
 *                                                                         *
 * Funcao: Sal get horario da sala em determinado dia                      *
 **************************************************************************/

SAL_tpCondRet SAL_getHorarioNoDia(SAL_tpSala * pSala, diasSemana dia, int horarioInicio, int horarioFim){
	int i;

	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	horarioInicio -= 7;
	horarioFim -= 7;

	if (horarioInicio >= horarioFim) {
		return SAL_CondRetParamInvalido;
	}

	if (horarioInicio < 0 || horarioInicio >= HORARIOS) {
		return SAL_CondRetParamInvalido;
	}

	if (horarioFim < 0 || horarioFim >= HORARIOS) {
		return SAL_CondRetParamInvalido;
	}

	for (i = horarioInicio; i < horarioFim; i++) {
		if (pSala->disponibilidade[dia][i] != salaLivre) {
			return SAL_CondRetReservada;
		}
	}

	return SAL_CondRetOK;
}

/* Fim da função SAL_getHorarioNoDia */

/********** Fim do modulo de implementacao: Modulo Sala **********/