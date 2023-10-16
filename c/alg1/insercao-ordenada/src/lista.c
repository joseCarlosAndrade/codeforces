
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

#include"../include/lista.h"



LISTA *lista_criar(void) {
	LISTA*lista = NULL;

	lista = (LISTA*)calloc(1,sizeof(LISTA));
	assert(lista!= NULL);

	lista->fim =-1;
	lista->esta_ordenada = false;
	return lista;
}

bool lista_inserir(LISTA *lista, ITEM *item) {
	assert(lista!=NULL);
	if(lista_cheia(lista)) return false;

	lista->lista[++(lista->fim)] = item;
	return true;
}

ITEM *lista_remover(LISTA *lista, int chave) {
	assert(lista!=NULL);

	if(lista_vazia(lista)) return NULL;
	
	int item_index = -1;
	for (int i  = 0; i <= lista->fim ; i++) {
		if ( item_get_chave( lista->lista[i] ) == chave) {
			item_index = i;
			break;
		}
	}
	if (item_index == -1) return NULL; // item nao encontrado para remover

	// 0 1 2 3 4 5 6 remover 3 -> item_index = 3;
	//       
	// fim = 6
	// inicio iteracao item_idex ate fim-1
	for(int i = item_index; i < lista->fim ; i++) {
		lista->lista[i] = lista->lista[i+1];
	}
	lista->fim--;
	return lista->lista[item_index];

	//lista->fim--;
}

void lista_apagar(LISTA **lista) {
	assert ( *lista !=NULL);
	
	for ( int i = 0; i <= (*lista)->fim ; i++) {
		item_apagar( &(*lista)->lista[i] );
	}
	free(*lista);
	*lista = NULL;
}

ITEM *lista_busca(LISTA *lista, int chave) {
	assert(lista!=NULL && !lista_vazia(lista));
	
	for ( int i = 0; i <= lista->fim ; i++) {
		if ( item_get_chave( lista->lista[i] ) == chave)
			return lista->lista[i];
	}

	return NULL; //  caso nao encontre nenhum item com esta chave'
}

int lista_tamanho(LISTA *lista) {
	assert(lista !=NULL);
	return lista->fim + 1;
}

bool lista_vazia(LISTA *lista) {
	assert(lista !=NULL);

	return lista->fim == -1;
}

bool lista_cheia(LISTA *lista) {
	assert(lista !=NULL);
	return lista->fim+1 == TAM_MAX;
}
void lista_imprimir(LISTA *lista) {
	assert(lista !=NULL);

	for (int i = 0 ; i <= lista->fim ; i++) {
		item_imprimir(lista->lista[i]);	
	}
	printf("\n");
}

