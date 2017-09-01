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
 *	    1.1.0         bp        31/08/2017   Implementacao funcoes getNUmero, getPredio, getAndar
 *	    1.2.0	     pg        31/08/2017   Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
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

/* Inclusão do respectivo módulo de definição */

#define SALA_OWN
#include "SALA.H"
#undef SALA_OWN

/***********************************************************************
 *
 * Tipo de dados: SAL que define a estrutura do tipo SALA
 *
 ***********************************************************************/

typedef struct sala
{   
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
    int[16][5] disponibilidade;
    
} Sala;


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: SAL Criar sala                                                 *
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet SAL_criarSala(Sala * sala)
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
 *                                                                        *
 **************************************************************************/

SAL_tpCondRet Sal_setCodigo(Sala * sala, int codigo)
{
    strcpy(sala->cod, codigo);
	//return especifico
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

SAL_tpCondRet Sal_getCodigo(Sala * sala, char *codigo)
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
 *     SAL_CondRetErroEstrutura                                           *
 *                                                                        *
 **************************************************************************/

int Sal_getNumero (Sala *sala){
	if (sala->cod[4] == NULL)
		return ((sala->cod[1]-'0')*100+(sala->cod[2]-'0')*10+(sala->cod[3]-'0'));
	return ((sala->cod[1]-'0')*1000+(sala->cod[2]-'0')*100+(sala->cod[3]-'0')*10+(sala->cod[4]-'0'));
}
/* Fim funcao: Sal get numero da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get predio da sala                                         *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *                                                                        *
 **************************************************************************/

char* Sal_getPredio (Sala *sala){
	switch (sala->cod[0]){
		case 'L' :
			return ("Leme");
		case 'F' :
			return ("Frings");
		case 'K' :
			return ("Kennedy");
		case 'I' :
			return ("IAG");
		default :
			return NULL;
	}
}
/* Fim funcao: Sal get predio da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get andar da sala                                          *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *                                                                        *
 **************************************************************************/

int Sal_getAndar (Sala *sala){
	int i;
	i = pegaNumero(sala);
	return i/100;
}
/* Fim funcao: Sal get andar da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal set Max Alunos                                             *
 *                                                                        *
 **   $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *                                                                        *
 **************************************************************************/

void Sal_setMaxAlunos(Sala *sala, int numeroAlunos)
{
	sala->maxAlunos = numeroAlunos;
}
/* Fim funcao: Sal set Max Alunos */



/**************************************************************************
 *                                                                        *
 * Funcao: Sal reserva Sala                                               *
 *                                                                        *
 *    $FV Valor retornado                                                 *
 *     SAL_CondRetOK                                                      *
 *     SAL_CondRetErroEstrutura                                           *
 *                                                                        *
 **************************************************************************/

void Sal_reservaSala(Sala *sala, int dia, int horaInicio, int horaFim)
{
	int hora = horaInicio;
	for(hora; hora < horaFim; hora++)
	{
		if(Sal_consultaHoranoDia(&sala, dia, hora) == 0) //fazer função
		{
			printf("A sala %s na hora %d esta indisponivel.\n", sala->cod, hora);
			exit();
		}
	}
	for(hora = horaInicio; hora < horaFim; hora++)
	{
		sala->disponibilidade [hora][dia] = 0;
	}
}
/* Fim funcao: Sal reserva Sala */


/********** Fim do modulo de implementacao: Modulo Sala **********/
