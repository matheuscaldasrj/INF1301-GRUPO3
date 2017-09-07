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
 *		1.2.6	      pg		04/09/2017   Ajustando reservaSala com nova condRet
 *		1.2.7	      pg		05/09/2017   Ajustes menores de codumentação.
 *		1.2.8		  mc        07/09/2017	 Implementação básica da criaSala, agora recebendo os parametros.
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




/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: SAL Criar sala                                                 *
 *    $FV Valor retornado                                                 *
 *    SAL_CondRetOK  													  *
 *	  SAL_CondRetRecebeuPonteiroNulo                                      *
 *    SAL_CondRetParamInvalido							                  *
                                                                         *
 **************************************************************************/

SAL_tpCondRet SAL_criarSala (SAL_tpSala * pSala,
							 char *codigo,
							 int maxAlunos,
							 int eLaboratorio)
{
	int disponibilidade[HORARIOS][DIAS];

	pSala = NULL;
    
    pSala = ( SAL_tpSala * ) malloc( sizeof( SAL_tpSala )) ;
    if( pSala == NULL )
    {
        return SAL_CondRetFaltouMemoria ;
    }
    
    //contruindo sala
	SAL_setCodigo(pSala,codigo);
	SAL_setMaxAlunos(pSala,maxAlunos);
	SAL_setELaboratorio(pSala,eLaboratorio);
	//SAL_resetDisponibilidade(pSala);

   
  	if(SAL_resetDisponibilidade(pSala) != SAL_CondRetOK){
  		return SAL_resetDisponibilidade(pSala);
  	}

    return SAL_CondRetOK ;
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
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *     SAL_CondRetRecebeuPonteiroNulo                                     *
 **************************************************************************/

SAL_tpCondRet SAL_getAndar (SAL_tpSala *pSala, int *andar)
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
	int hora = horaInicio - ajusteHora;
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;

	if( horaInicio < inicioDiaLetivo || horaInicio >= fimDiaLetivo || horaFim <= inicioDiaLetivo || horaFim > fimDiaLetivo || dia <inicioSemanaLetiva || dia > fimSemanaLetiva)
		return  SAL_CondRetParamInvalido;
	
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

/**************************************************************************
*                                                                         *
* Funcao: Sal get disponibilidade Sala                                    *
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

/*
	Função SAL_getHorarioNoDia

	Retorno:
	
	SAL_tpCondRet, onde:

	- SAL_CondRetRecebeuPonteiroNulo, se a sala recebida for nula
	- SAL_CondRetParamInvalido, se:
	  
	  1. O horário de início for maior ou igual ao horário de fim;
	  2. Se algum dos horários não estiver compreendido no período de 7 a 22 horas
	     durante o qual as aulas ocorrem;
 
	- SAL_CondRetOK, se a função for concluída com sucesso

	Parâmetros:

	- SAL_tpSala: ponteiro para a sala desejada
	- dia: valor inteiro entre 0 e 5 (ambos inclusive) representando um dos dias da semana
	  de segunda a sábado (0 = segunda, 1 = terça, ..., 5 = sábado)
	- horarioInicio: valor entre 7 e 22 representando o horário de início do período a ser
	  verificado
	- horarioFim: valor entre 7 e 22 representando o horário de fim do período a ser verificado
	- estaDisponivel: ponteiro para uma variável inteira onde será armazenado 1 se o intervalo
	  selecionado estiver disponível, 0 se não estiver.

 */

SAL_tpCondRet SAL_getHorarioNoDia(SAL_tpSala *pSala, diasSemana dia, int horarioInicio, int horarioFim, int* estaDisponivel) {
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
			*estaDisponivel = 0;
			return SAL_CondRetOK;
		}
	}

	*estaDisponivel = 1;
	return SAL_CondRetOK;
}

/* Fim da função SAL_getHorarioNoDia */

/********** Fim do modulo de implementacao: Modulo Sala **********/
