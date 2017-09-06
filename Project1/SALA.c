/***************************************************************************
 *  Modulo de implementacao: Modulo Sala
 *
 *  Letras identificadoras:      SAL
 *
 *  Autores: mc - Matheus Caldas
 *	     bp - Bruno Pedrazza
 *	     pg - Pedro Gomes
 *  Historico de evolucao:
 *     Versao       Autor          Data            Observacoes
 *      1.0.0         mc        30/08/2017   Inicio do desenvolvimento
 *	    1.1.0         bp        31/08/2017   Implementacao funcoes getNumero, getPredio, getAndar
 *	    1.2.0	      pg        31/08/2017   Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
 *      1.2.1         bp        02/09/2017   Mudanca nas condicoes de retorno funcoes getNumero, getPredio, getAndar, setCodigo
 *      1.2.2         mc        02/09/2017   Implementacao funcoes setQtdComputadores e getQtdComputadores
 *		1.2.3	      bp		03/09/2017	 Implementacao funcoes getELaboratorio e setELaboratorio
 *		1.2.4         pg		04/09/2017	 Ajustando reservaSala e incluindo novos defines
 *		1.2.5	      bp		04/09/2017   Implementacao resetDisponibilidade, adicao de sábados e novos defines
 		1.2.6	      pg		04/09/2017   Ajustando reservaSala com nova condRet
		1.2.7	      pg		05/09/2017   Ajustes menores de codumentação.
 *
 *  Descrição do módulo
 *     Este módulo implementa um conjunto de funcoes para criar e manipular
 *     atributos do módulo Sala.
 *
 *
 *
 ***************************************************************************/

/* Inclusões do compilador */
#include  <stdio.h>
#include  <string.h>

#define HORARIOS 16
#define DIAS 6
#define tamCodigoSala 6
#define ajusteHora 7
#define salaReservada 1
#define salaLivre 0
#define reservaFalhou 0
#define inicioDiaLetivo 7
#define fimDiaLetivo 23
#define inicioSemanaLetiva 0
#define fimSemanaLetiva 5

/* Inclusão do respectivo módulo de definição */

#define SALA_OWN
#include "SALA.H"
#undef SALA_OWN

/***********************************************************************
 *
 * Tipo de dados: SAL que define a estrutura do tipo SALA
 *
 ***********************************************************************/

typedef struct SAL_tagSala  {   
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

} SAL_tpSala;


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: SAL Criar sala                                                 *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_criarSala (SAL_tpSala * pSala)
{
    //TODO

} 
/* Fim funcao: SAL Criar sala */



/**************************************************************************
 *                                                                        *
 * Funcao: SAL seta codigo da sala                                        *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *    SAL_CondRetOK  													  *
 *	  SAL_CondRetRecebeuPonteiroNulo                                      *
 *    SAL_CondRetParamInvalido							                  *
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
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK    												  *
 *	   SAL_CondRetRecebeuPonteiroNulo                                     *
 *     SAL_CondRetErroEstrutura 										  *
 *	   						                                              *
 *                                                                        *
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
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetParamInvalido                                           *
 *     SAL_CondRetRecebeuPonteiroNulo									  *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_setMaxAlunos (SAL_tpSala * pSala, int maxAlunos)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	if (maxAlunos == NULL || maxAlunos <= 0)
		return SAL_CondRetParamInvalido;
	
	pSala->maxAlunos = maxAlunos;
	return SAL_CondRetOK;
}
/* Fim funcao: Sal set Max Alunos */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get Max Alunos                                             *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *     SAL_CondRetRecebeuPonteiroNulo									  *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_getMaxAlunos (SAL_tpSala * pSala, int *maxAlunos)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	*maxAlunos = pSala->maxAlunos;

	if (maxAlunos == NULL || maxAlunos <= 0)
		return SAL_CondRetErroEstrutura;

	return SAL_CondRetOK;
}
/* Fim funcao: Sal get Max Alunos */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal set eLaboratorio                                           *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetParamInvalido                                           *
 *     SAL_CondRetRecebeuPonteiroNulo									  *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_setELaboratorio (SAL_tpSala * pSala, int eLaboratorio)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	if (eLaboratorio == NULL || (eLaboratorio != 1 && eLaboratorio != 0))
		return SAL_CondRetParamInvalido;

	pSala->eLaboratorio = eLaboratorio;

	return SAL_CondRetOK;
}
/* Fim funcao: Sal set eLaboratorio */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get eLaboratorio                                           *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *     SAL_CondRetRecebeuPonteiroNulo									  *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_getELaboratorio (SAL_tpSala * pSala, int *eLaboratorio)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	*eLaboratorio = pSala->eLaboratorio;
	
	if (eLaboratorio == NULL || (eLaboratorio != 1 && eLaboratorio != 0))
		return SAL_CondRetErroEstrutura;

	return SAL_CondRetOK;
}
/* Fim funcao: Sal get eLaboratorio */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get numero da sala                                         *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetRecebeuPonteiroNulo                                     *
 *     SAL_CondRetErroEstrutura  										  *
 *     						                                              *
 **************************************************************************/

SAL_tpCondRet SAL_getNumero (SAL_tpSala *pSala, int *numero)
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
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura	                                          *
 *     SAL_CondRetRecebeuPonteiroNulo                                     *
 **************************************************************************/

SAL_tpCondRet SAL_getPredio (SAL_tpSala * pSala, char *predio)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	switch (pSala->codigo[0]){
		case 'L' :
		*predio = "Leme";
		case 'F' :
		*predio = "Frings";
		case 'K' :
		*predio = "Kennedy";
		case 'I' :
		*predio = "IAG";
		default :
		return SAL_CondRetErroEstrutura;
	}
	return SAL_CondRetOK;
}
/* Fim funcao: Sal get predio da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get andar da sala                                          *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *     SAL_CondRetRecebeuPonteiroNulo                                     *
 **************************************************************************/

SAL_tpCondRet SAL_getAndar (SAL_tpSala *pSala, int *andar)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	SAL_tpCondRet retorno;
	int numero;

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
 *                                                                        *
 *    $FV Valor retornado 						  *
 *	   SAL_CondRetRecebeuPonteiroNulo  				  *
 *	SAL_CondRetParamInvalido					  *
 *	SAL_CondRetReservada						  *
 *	SAL_CondRetOK       						  *  
 *									  *
 *    $ED Descrição da Função     					  *
 *	Atualiza a matriz disponibilidade para reservar a sala em	  *
 *	determinador horários.						  *
 **************************************************************************/

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	if( horaInicio < inicioDiaLetivo || horaInicio >= fimDiaLetivo || horaFim <= inicioDiaLetivo || horaFim > fimDiaLetivo || dia <inicioSemanaLetiva || dia > fimSemanaLetiva)
		return  SAL_CondRetParamInvalido;

	int hora = horaInicio - ajusteHora;
	for(hora; hora < horaFim - ajusteHora; hora++)
	{
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
 *                                                                        *
 *    $FV Valor retornado 												  *
 *	   SAL_CondRetRecebeuPonteiroNulo                                     *
 *     SAL_CondRetOK                                                      *
 *                                                						  *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_resetDisponibilidade (SAL_tpSala *pSala){
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo; 
	int i, j;
	for (i = 0 ; i < HORARIOS ; i++){
		for (j = 0; j < DIAS ; j++){
			pSala->disponibilidade[i][j] = salaLivre;
		}
	}

	return SAL_CondRetOK;
}

/* Fim funcao: Sal reset disponibilidade Sala */

/**************************************************************************
*                                                                         *
* Funcao: Sal pega disponibilidade Sala                                   *
*                                                                         *
*    $FV Valor retornado 												  *
*	  SAL_CondRetRecebeuPonteiroNulo                                      *
*     SAL_CondRetOK                                                       *
*                                                						  *
*                                                                         *
**************************************************************************/

SAL_tpCondRet SAL_getDisponibilidade(SAL_tpSala *pSala, int disponibilidade[16][6]) {
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	
	disponibilidade = pSala->disponibilidade;
	return SAL_CondRetOK;
}

/* Fim funcao: Sal reset disponibilidade Sala */

/********** Fim do modulo de implementacao: Modulo Sala **********/
