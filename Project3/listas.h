/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              listas.h
*  Letras identificadoras:      LIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores:		mrol - Matheus Rodrigues de Oliveira Leal
*				SaintL - Leonardo Abreu Santos
*	      		ngtgmp - Felipe Nogueira de Souza
*				LL - Clayton Lucas Mendes Lima
*				mc - Matheus Caldas
*				lf - Leon França
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   ngtgmp   10/09/2017 Início do desenvolvimento
*		0.02   ngtgmp   21/09/2017 Implementação de mais funções
*		0.03   ngtgmp   27/09/2017 Preparo para os testes automatizados e revisão do código
*		0.04   ngtgmp   01/10/2017 Reparos após testes e revisão
*		1.0		mc		05/12/2017 Adicao de verificacoes e deturpacoes completas
*		1.1		lf		05/12/2017 Documentação de verificadores e deturpadores
*  $ED Descrição do módulo
*     Este módulo implementa o módulo lista duplamente encadeada para ser utilizada pelos demais módulos do projeto "Sistema Acadêmico da turma 3wb".
*	  Uma lista(list) contém um cabeçalho, com um nó apontanto para o primeiro item da lista, um apontando para o último e outro apontando para o nó cursor.
*	  Nós(node(s)) são estrutura contendo o próximo nó e o anterior (duplamente encadeada) e contém um ponteiro para um valor (void*)
***************************************************************************/

typedef struct node Node;

typedef struct list List;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Condições de retorno
*
*
***********************************************************************/
   typedef enum {
     LIS_CondRetOK = 0 ,
     /* Executou correto */
     LIS_CondRetListaVazia = 1,
     /* Estrutura list está deletada */
     LIS_CondRetFaltouMemoria = 2 ,
     /* Faltou memória ao alocar dados */
     LIS_CondRetCursorNoFinal = 3,
	   /* Impossível obter próximo */
	   LIS_CondRetCursorNoInicio = 4,
	   /* Impossível obter anterior*/

   #ifdef _DEBUG

	   LIS_ErroNaEstrutura = 5,
     LIS_ErroNoTipo = 6

   #endif

   }LIS_tpCondRet;
/***********************************************************************
*
*  $FC Função: LIS create List
*
*  $ED Descrição da função
*    Cria uma lista vazia
*
***********************************************************************/
LIS_tpCondRet createList(List** l 
#ifdef _DEBUG 
	, char tipoin 
#endif
	);
/***********************************************************************
*
*  $FC Função: LIS del
*
*  $ED Descrição da função
*    Deleta uma lista já criada
*
***********************************************************************/
LIS_tpCondRet del(List* l);
/***********************************************************************
*
*  $FC Função: LIS clear
*
*  $ED Descrição da função
*    Limpa uma lista criada para zero nós
*
***********************************************************************/
LIS_tpCondRet clear(List* l);
/***********************************************************************
*
*  $FC Função: LIS push back
*
*  $ED Descrição da função
*    Insere um elemento no final da List
*
***********************************************************************/
LIS_tpCondRet push_back(List* l, void* val 
#ifdef _DEBUG 
	, char tipoin 
#endif
	);
/***********************************************************************
*
*  $FC Função: LIS push front
*
*  $ED Descrição da função
*    Insere um elemento no começo da List
*
***********************************************************************/
LIS_tpCondRet push_front(List* l, void* val 
#ifdef _DEBUG 
	, char tipoin 
#endif
	);
/***********************************************************************
*
*  $FC Função: LIS pop back
*
*  $ED Descrição da função
*    Atualiza o parâmetro val, referenciado, para o último elemento da lista, que é removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_back(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS pop front
*
*  $ED Descrição da função
*    Atualiza o parâmetro val, referenciado, para o primeiro elemento da lista, que é removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_front(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS pop cursor
*
*  $ED Descrição da função
*    Remove o nó cursor da lista e retorna a referência para seu valor. 
*	 Caso o nó cursor seja o último nó, o cursor se torna o anterior, caso seja o primeiro
*	 o cursor se torna o seguinte. Em qualquer outro caso o cursor se torna o próximo.
*
***********************************************************************/
LIS_tpCondRet pop_cursor(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS get val cursor
*
*  $ED Descrição da função
*    Atualiza o parâmetro val para o valor no nó cursor.
*
***********************************************************************/
LIS_tpCondRet get_val_cursor(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS list size
*
*  $ED Descrição da função
*    Atualiza o parametro size para o tamanho da lista.
*
***********************************************************************/
LIS_tpCondRet list_size(List* l, unsigned int* size); //retorna a quantidade de elementos na List
/***********************************************************************
*
*  $FC Função: LIS first
*
*  $ED Descrição da função
*    Atualiza para o primeiro nó da lista
*
***********************************************************************/
LIS_tpCondRet first(List* l);
/***********************************************************************
*
*  $FC Função: LIS next
*
*  $ED Descrição da função
*    Atualiza o cursor para o próximo nó
*
***********************************************************************/
LIS_tpCondRet next(List* l);//atualiza o cursor para o próximo nó
/***********************************************************************
*
*  $FC Função: LIS prev
*
*  $ED Descrição da função
*    Atualiza o cursor para o nó anterior
*
***********************************************************************/
LIS_tpCondRet prev(List* l);//atualiza o cursor para o nó anterior




#ifdef _DEBUG
/***************************************************************************
*
*$FC	Funcao: LIS deturpaListaNull
*$ED	Descricao da funcao:
*	Deturpa endereco para lista, modificando-o para um endereco nulo.
*
$.**************************************************************************/
LIS_tpCondRet deturpaListaNull(List** l);
/***************************************************************************
*
*$FC	Funcao: LIS verificaListaNull
*$ED	Descricao da funcao:
*	Verifica se endereco para lista esta vazio. Retorna condicao de erro por referencia.
*
$.**************************************************************************/
LIS_tpCondRet verificaListaNull(List** l, int * error);
/***************************************************************************
*
*$FC	Funcao: LIS deturpaCursorNull
*$ED	Descricao da funcao:
*	Deturpa ponteiro para no cursor modificando-o para um endereco nulo.
*
$.**************************************************************************/
LIS_tpCondRet deturpaCursorNull(List* l);
/***************************************************************************
*
*$FC	Funcao: LIS verificaCursorNull
*$ED	Descricao da funcao:
*	Verifica se ponteiro para no cursor esta vazio. Retorna condicao de erro por referencia.
*
$.**************************************************************************/
LIS_tpCondRet verificaCursorNull(List* l, int * error);
/***************************************************************************
*
*$FC	Funcao: LIS deturpaLastNull
*$ED	Descricao da funcao:
*	Deturpa ponteiro para ultimo no da lista modificando-o para um endereco nulo.
*
$.**************************************************************************/
LIS_tpCondRet deturpaLastNull(List* l);
/***************************************************************************
*
*$FC	Funcao: LIS verificaLastNull
*$ED	Descricao da funcao:
*	Verifica se ponteiro para ultimo no da lista esta vazio. Retorna condicao de erro por referencia.
*
$.**************************************************************************/
LIS_tpCondRet verificaLastNull(List* l, int * error);
/***************************************************************************
*
*$FC	Funcao: LIS deturpapAnteriorNull
*$ED	Descricao da funcao:
*	Deturpa ponteiro para no anterior ao cursor da lista modificando-o para um endereco nulo.
*
$.**************************************************************************/
LIS_tpCondRet deturpapAnteriorNull(List* l);
/***************************************************************************
*
*$FC	Funcao: LIS verificapAnteriorNull
*$ED	Descricao da funcao:
*	Verifica se ponteiro para no anterior ao cursor esta vazio. Retorna condicao de erro por referencia.
*
$.**************************************************************************/
LIS_tpCondRet verificapAnteriorNull(List* l, int * error);
/***************************************************************************
*
*$FC	Funcao: LIS deturpaFirstNull
*$ED	Descricao da funcao:
*	Deturpa ponteiro para para primeiro no da lista modificando-o para um endereco nulo.
*
$.**************************************************************************/
LIS_tpCondRet deturpaFirstNull(List* l);
/***************************************************************************
*
*$FC	Funcao: LIS verificaFirstNull
*$ED	Descricao da funcao:
*	Verifica se ponteiro para primeiro no da lista esta vazio. Retorna condicao de erro por referencia.
*
$.**************************************************************************/
LIS_tpCondRet verificaFirstNull(List* l, int * error);
/***************************************************************************
*
*$FC	Funcao: LIS deturpaValorCorrenteNull
*$ED	Descricao da funcao:
*	Deturpa valor contido em no corrente da lista modificando-o para um valor nulo.
*
$.**************************************************************************/
LIS_tpCondRet deturpaValorCorrenteNull(List* l);
/***************************************************************************
*
*$FC	Funcao: LIS verificaValorCorrenteNull
*$ED	Descricao da funcao:
*	Verifica se valor contido em no corrente da lista esta vazio. Retorna condicao de erro por referencia.
*
$.**************************************************************************/
LIS_tpCondRet verificaValorCorrenteNull(List* l, int * error);

/***************************************************************************
*
*$FC	Funcao: LIS verificaLista
*$ED	Descricao da funcao:
*	Faz a verificacao de todas as condicoes de erro supracitadas
*
$.**************************************************************************/
LIS_tpCondRet LIS_verificaLista(List * list);

/***************************************************************************
*
*$FC	Funcao: LIS deturpaLista
*$ED	Descricao da funcao:
*	Faz a deturpacao em todas as condicoes de erro supracitadas
*
$.**************************************************************************/
LIS_tpCondRet LIS_deturpaLista (List ** list , int acaoDeDeturpacao );
#endif
