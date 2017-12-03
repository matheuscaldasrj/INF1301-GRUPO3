/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              listas.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores:   mrol - Matheus Rodrigues de Oliveira Leal
*             SaintL - Leonardo Abreu Santos
*	      	  ngtgmp - Felipe Nogueira de Souza
	          LL - Clayton Lucas Mendes Lima
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   ngtgmp   10/09/2017 Início do desenvolvimento
*		0.02   ngtgmp   21/09/2017 Implementação de mais funções
*		0.03   ngtgmp   27/09/2017 Preparo para os testes automatizados e revisão do código
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização dos Nós em uma Lista
*
***********************************************************************/
struct node
{
	struct node* next;	//Aponta para o próximo nó
	struct node* prev;  //Aponta para o nó anterior
	void* val;			//Aponta para variável val
};
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma Lista pelo cabeçalho. Pode-se fazer Listas de Listas.
*
***********************************************************************/
struct list
{
	Node* first;  //Aponta para o primeiro nó
	Node* last;	  //Aponta para o último nó
	Node* cursor; //Aponta para o nó cursor
};
/***************************************************************************
*
*  Função: LIS create list
*  ****/
LIS_tpCondRet createList(List** l){ (*l) = (List*) calloc(1, sizeof(List)); if(!l) return LIS_CondRetFaltouMemoria; (*l)->first = NULL; (*l)->last = NULL; (*l)->cursor = NULL; return LIS_CondRetOK; }
/* Fim função: LIS create lista */
/***************************************************************************
*
*  Função: LIS del
*  ****/
LIS_tpCondRet del(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while(tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	free(l);
	return LIS_CondRetOK;
}/* Fim função: LIS del */
/***************************************************************************
*
*  Função: LIS clear
*  ****/
LIS_tpCondRet clear(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while(tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	l->first = NULL;
	l->last = NULL;
	l->cursor = NULL;
	return LIS_CondRetOK;
}/* Fim função: LIS del */
/***************************************************************************
*
*  Função: LIS push back
*  ****/
LIS_tpCondRet push_back(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) calloc (1, sizeof(Node));
	if(!Nnode)
		return LIS_CondRetFaltouMemoria;
	Nnode->val = val;
	Nnode->next = NULL;
	if(l->first == NULL)//Se a lista estiver vazia, primeiro nó = último nó = nó cursor.
	{
		l->first = Nnode;
		l->cursor = Nnode;
		Nnode->prev = NULL;
	}
	else
	{
		Nnode->prev = l->last;
		l->last->next = Nnode;
	}
	l->last = Nnode;
	return LIS_CondRetOK;
} /* Fim função: LIS push back */
/***************************************************************************
*
*  Função: LIS push front
*  ****/
LIS_tpCondRet push_front(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) calloc(1, sizeof(Node));
	if(!Nnode)
		return LIS_CondRetFaltouMemoria;
	Nnode->val = val;
	Nnode->prev = NULL;
	if(l->first == NULL)
	{
		l->last = Nnode;
		l->cursor = Nnode;
		Nnode->next = NULL;
	}
	else
	{
		Nnode->next = l->first;
		l->first->prev = Nnode;
	}
	l->first = Nnode;
	return LIS_CondRetOK;
} /* Fim função: LIS push front */
/***************************************************************************
*
*  Função: LIS pop back
*  ****/
LIS_tpCondRet pop_back(List* l, void** val)
{
	Node* tnode;
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return LIS_CondRetListaVazia; }

	*val = l->last->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if(l->cursor == l->last)
		l->cursor = l->last->prev;
	tnode = l->last;
	l->last = l->last->prev;
	l->last->next = NULL;
	tnode->prev = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS pop back */
/***************************************************************************
*
*  Função: LIS pop front
*  ****/
LIS_tpCondRet pop_front(List* l, void** val)
{
	Node* tnode;
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return LIS_CondRetListaVazia;}

	*val = l->first->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if(l->cursor == l->first)
		l->cursor = l->first->next;
	tnode = l->first;
	l->first = l->first->next;
	l->first->prev = NULL;
	tnode->next = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS pop front */
/***************************************************************************
*
*  Função: LIS pop cursor
*  ****/
LIS_tpCondRet pop_cursor(List* l, void** val)
{
	Node* tnode;
	if(l->cursor == l->first)
		return pop_front(l, val);
	else if(l->cursor == l->last)
		return pop_back(l, val);
	else
	{
		if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return LIS_CondRetListaVazia;}

		*val = l->cursor->val;

		if (l->first == l->last)
		{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
		}
		tnode = l->cursor;
		l->cursor->prev->next = l->cursor->next;
		l->cursor->next->prev = l->cursor->prev;
		l->cursor = l->cursor->next;
		tnode->next = NULL;
		tnode->prev = NULL;
		return LIS_CondRetOK;
		}
} /* Fim função: LIS pop cursor */
/***************************************************************************
*
*  Função: LIS get val cursor
*  ****/
LIS_tpCondRet get_val_cursor(List* l, void** val)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return LIS_CondRetListaVazia;}
	*val = l->cursor->val;
	return LIS_CondRetOK;
}/* Fim função: LIS get val cursor */
/***************************************************************************
*
*  Função: LIS list size
*  ****/
LIS_tpCondRet list_size(List* l, unsigned int size)
{
	Node* Tnode;
	size = 0;
	Tnode = l->first;
	if(l->first == NULL)
		return LIS_CondRetListaVazia;
	while(Tnode != l->last)
		size++;
	return LIS_CondRetOK;
} /* Fim função: LIS list size */
/***************************************************************************
*
*  Função: LIS next
*  ****/
LIS_tpCondRet next(List* l)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");return LIS_CondRetListaVazia;}
	else if(l->cursor->next == NULL)
	{
		printf("\n\n <!> Cursor ja posicionado no final da lista <!> \n\n");
		return LIS_CondRetCursorNoFinal;
	}
	else l->cursor = l->cursor->next;
	return LIS_CondRetOK;
} /* Fim função: LIS next */
/***************************************************************************
*
*  Função: LIS prev
*  ****/
LIS_tpCondRet prev(List* l)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return LIS_CondRetListaVazia;}
	else if(l->cursor->prev == NULL)
	{
		printf("\n\n <!> Cursor ja posicionado no inicio da lista <!> \n\n");
		return LIS_CondRetCursorNoInicio;
	}
	else l->cursor = l->cursor->prev;
	return LIS_CondRetOK;
} /* Fim função: LIS prev */



#ifdef _DEBUG

// DETURPACOES E VERIFICACOES
LIS_tpCondRet deturpaListaNull(List **l) {
	*l = NULL;

	return LIS_CondRetOK;
}


LIS_tpCondRet verificaListaNull(List** l, int *erro) {
	
	*erro = 0;
	if(* l == NULL){
		*erro = 1;
	}

	return LIS_CondRetOK;
}

LIS_tpCondRet deturpaCursorNull(List* l) {
	
	l->cursor = NULL;

	return LIS_CondRetOK;
	
}

LIS_tpCondRet verificaCursorNull(List* l, int *erro){

	if(l == NULL) {
		*erro = 1;
		return LIS_CondRetOK;
	}

	*erro = 0;
	if(l->cursor == NULL)
	{		
		*erro = 1;
	}
	return LIS_CondRetOK;
}

LIS_tpCondRet deturpaLastNull(List* l) {
	l->last = NULL;

	return LIS_CondRetOK;

}
LIS_tpCondRet verificaLastNull(List* l, int *erro) {

	if(l == NULL) {
		*erro = 1;
		return LIS_CondRetOK;
	}


	*erro = 0;
	if(l->last == NULL) {
		*erro = 1;
	}

	return LIS_CondRetOK;
}

LIS_tpCondRet deturpapAnteriorNull(List* l) {

	l->cursor->prev = NULL;

	return LIS_CondRetOK;
}
LIS_tpCondRet verificapAnteriorNull(List* l, int *erro) {

	
	if(l == NULL) {
		*erro = 1;
		return LIS_CondRetOK;
	}

	*erro = 0;

	if(l->cursor->prev == NULL) {
		*erro = 1;
	}

	return LIS_CondRetOK;

}

LIS_tpCondRet deturpaFirstNull(List* l) {
	l->first = NULL;

	return LIS_CondRetOK;
}
LIS_tpCondRet verificaFirstNull(List* l, int *erro) {
	
	
	if(l == NULL) {
		*erro = 1;
		return LIS_CondRetOK;
	}

	*erro = 0;

	if(l->first == NULL){
		*erro = 1;
	}

	return LIS_CondRetOK;
}


LIS_tpCondRet deturpaValorCorrenteNull(List* l) {
	l->cursor->val = NULL;

	return LIS_CondRetOK;
}
LIS_tpCondRet verificaValorCorrenteNull(List* l, int * erro) {
	if(l == NULL) {
		*erro = 1;
		return LIS_CondRetOK;
	}

	*erro = 0;

	if(l->cursor->val == NULL){
		*erro = 1;
	}

	return LIS_CondRetOK;
}

#endif