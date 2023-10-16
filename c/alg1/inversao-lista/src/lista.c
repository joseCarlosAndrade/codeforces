#include"../include/lista.h"
#include"../include/item.h"

typedef struct no_ NO;

struct no_ {
	ITEM * info;
	NO * prox;
};

struct lista_ {
	NO* inicio;
        NO* fim;
	int tam;
};

LISTA *lista_criar(void) {
	LISTA * l = NULL;
	l = (LISTA*) calloc(1, sizeof(LISTA));

	assert(l !=NULL);

	l->inicio = NULL;
	l->fim = NULL;
	l->tam = 0;
	return l;

}

bool lista_inserir(LISTA*lista, ITEM*item) {
	assert(lista !=NULL && item!=NULL);
	
	NO * new_element = NULL;
	new_element = (NO*) calloc(1, sizeof(NO));
	assert(new_element !=NULL);

	new_element->info = item;
	new_element->prox = NULL;

	if(lista_vazia(lista)) {
		lista->inicio = new_element;
		lista->fim = new_element;
	}
	else {  // 0 0 0 0 0 0 0 0 0 
		// i             f
		lista->fim->prox = new_element;
		lista->fim = new_element;
	}

	lista->tam++;
	
	return 1;
	//NO*prox = lista->inicio;
	//for ( ;prox!=NULL ; prox = prox->prox) {
	//}

}

ITEM * lista_remover(LISTA *lista, int chave) {
	assert(lista!=NULL);
	
	NO*part = lista->inicio;
	NO*last_part = lista->inicio;
	for (;part != NULL;) {

		if(item_get_chave( part->info) == chave) {
			last_part->prox= part->prox;
			lista->tam--;
			return part->info;
			break;
		}
		last_part = part;
		part = part->prox;
	}
	return NULL;
}

bool lista_apagar(LISTA**lista) {
	assert(*lista!=NULL);
	if (!lista_vazia(*lista)) {
		NO*part = (*lista)->inicio;
		for (;part !=NULL;part = part->prox) {
			item_apagar(&(part->info));
		}
	}

	free(*lista);
	*lista =NULL;

}

ITEM* lista_busca(LISTA*lista, int chave) {
	assert(lista!=NULL);
	
	NO*part = lista->inicio;
	for (;part != NULL;) {

		if(item_get_chave( part->info) == chave) {
			return part->info;
			break;
		}
		part = part->prox;
	}
	return NULL;

}

int lista_tamanho(LISTA*lista) {
	assert(lista!=NULL);

	return lista->tam;
}

bool lista_vazia(LISTA*lista) {
	assert (lista!=NULL);

	return lista->tam== 0;
}

bool lista_cheia(LISTA*lista) {
	assert(lista!=NULL);

	return lista->tam== TAM_MAX_LISTA;
}


void lista_imprimir(LISTA*lista) {
	assert (lista!=NULL);
	for(NO *p = lista->inicio; p !=NULL; p = p->prox) {
		item_imprimir(p->info);
	} 

}

void inserir_ao_contario(NO* no,  LISTA *aux) {
	if (no->prox== NULL) {
		lista_inserir(aux, no->info);
		return;
	}
	inserir_ao_contario(no->prox, aux);

	lista_inserir(aux, no->info);
}

bool lista_inverter(LISTA**lista) {
	assert(*lista!=NULL);
	LISTA* aux = lista_criar();

	inserir_ao_contario((*lista)->inicio, aux);
	*lista = aux;
	return 1;
}

