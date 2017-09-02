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
 *	    1.2.0	       pg        31/08/2017   Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
 *      1.2.1         bp        02/09/2017   Mudanca nas condicoes de retorno funcoes getNumero, getPredio, getAndar, setCodigo
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
    char codigo[6];

    /* Quantidade de computadores na sala */
    int qtdComputadores;

    /* Número máximo de alunos que a sala comporta */
    int maxAlunos;

     /* Matriz de disponibilidade onde 1 representa sala "ocupada"
        e 0 "livre", assim, por exemplo, a sala estaria ocupada
        segunda e quarta (7-9) e
        terca e quinta (21-23)

        |Segunda|Terca|Quarta|Quinta|Sexta|
        7|  1    |  0  |  1   |  0   |  0  |     
        8|  1    |  0  |  1   |  0   |  0  |   
        9|  0    |  0  |  0   |  0   |  0  |   
       10|  0    |  0  |  0   |  0   |  0  |   
       11|  0    |  0  |  0   |  0   |  0  |   
       12|  0    |  0  |  0   |  0   |  0  |   
       13|  0    |  0  |  0   |  0   |  0  |   
       14|  0    |  0  |  0   |  0   |  0  |   
       15|  0    |  0  |  0   |  0   |  0  |   
       16|  0    |  0  |  0   |  0   |  0  |   
       17|  0    |  0  |  0   |  0   |  0  |   
       18|  0    |  0  |  0   |  0   |  0  |   
       19|  0    |  0  |  0   |  0   |  0  |   
       20|  0    |  0  |  0   |  0   |  0  |   
       21|  0    |  1  |  0   |  1   |  0  |   
       22|  0    |  1  |  0   |  1   |  0  |   
       --------------------------------------
     */
    int disponibilidade[16][5];
    
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
 *    SAL_CondRetOK                                                       *
 *    SAL_CondRetErroEstrutura                                            *
 *    SAL_CondRetPredioNaoExiste                                          *
 **************************************************************************/

SAL_tpCondRet SAL_setCodigo (SAL_tpSala * pSala, char *codigo)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
    strcpy(pSala->cod, codigo);
	return SAL_CondRetOK;
} 
/* Fim funcao: SAL seta codigo da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get codigo da sala                                         *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_getCodigo (SAL_tpSala * pSala, char *codigo)
{
    //TODO

} 
/* Fim funcao: Sal get codigo da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get numero da sala                                         *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetRecebeuPonteiroNulo                                     *
 *     SAL_CondRetErroCodSala                                             *
 **************************************************************************/

SAL_tpContRet SAL_getNumero (SAL_tpSala *pSala, int *numero)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	if (sala->cod[4] == NULL){
		*numero = (pSala->cod[1]-'0')*100+(pSala->cod[2]-'0')*10+(pSala->cod[3]-'0');
		return SAL_CondRetOK;
	}
	else{
		*numero = (pSala->cod[1]-'0')*1000+(pSala->cod[2]-'0')*100+(pSala->cod[3]-'0')*10+(pSala->cod[4]-'0');
		return SAL_CondRetOK;
	}
	return SAL_CondRetErroCodSala;
}
/* Fim funcao: Sal get numero da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get predio da sala                                         *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetPredioNaoExiste                                         *
 *     SAL_CondRetRecebeuPonteiroNulo                                     *
 **************************************************************************/

SAL_tpCondRet SAL_getPredio (SAL_tpSala * pSala, char *predio)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	switch (pSala->cod[0]){
		case 'L' :
			*predio = "Leme";
		case 'F' :
			*predio = "Frings";
		case 'K' :
			*predio = "Kennedy";
		case 'I' :
			*predio = "IAG";
		default :
			return SAL_CondRetPredioNaoExiste;
	}
	return SAL_CondRetOK
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
 * Funcao: Sal set Max Alunos                                             *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *     SAL_CondRetRecebeuPonteiroNulo									  *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_setMaxAlunos (SAL_tpSala * pSala, int numeroAlunos)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	pSala->maxAlunos = numeroAlunos;
	return SAL_CondRetOK;
}
/* Fim funcao: Sal set Max Alunos */



/**************************************************************************
 *                                                                        *
 * Funcao: Sal reserva Sala                                               *
 *                                                                        *
 *    $FV Valor retornado 												  *
 *	   SAL_CondRetRecebeuPonteiroNulo                                     *
 *     SAL_CondRetOK                                                      *
 *                                                *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim)
{
	if (pSala == NULL)
		return SAL_CondRetRecebeuPonteiroNulo;
	int hora = horaInicio -7;
	for(hora; hora < horaFim - 7; hora++)
	{
		if(Sal_consultaHoranoDia(&pSala, dia, hora) == 0) //fazer função
		{
			printf("A sala %s na hora %d esta indisponivel.\n", pSala->cod, hora);
			exit();
		}
	}
	for(hora = horaInicio -7; hora < horaFim -7; hora++)
	{
		pSala->disponibilidade [hora][dia] = 0;
	}
}
/* Fim funcao: Sal reserva Sala */


/********** Fim do modulo de implementacao: Modulo Sala **********/
