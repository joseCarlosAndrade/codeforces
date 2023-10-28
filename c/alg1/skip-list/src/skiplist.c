#include"../include/skiplist.h"
#include<stdlib.h>

#define MAX_LEVEL 10

struct _no {
	elem valor;
	item_t * item;
	no_t * next;
	no_t * down;
	int level;
};

struct _skiplist {
	no_t * upperleft;
	int max_level;
};

no_t * no_criar(elem valor, no_t* next, no_t*down, int level) {
	no_t * n = NULL;
	n= (no_t*)calloc(1, sizeof(no_t));
	if(!n) exit(EXIT_FAILURE);

	n->valor = valor;
	n->next = next;
	n->down = down;
	n->level = level;

	return n;
}

skiplist_t* sl_criar() {
	skiplist_t * sl = NULL;
	srand(time(NULL));

	sl = (skiplist_t *)calloc(1, sizeof(skiplist_t));
	if (!sl) exit(EXIT_FAILURE);

	sl->max_level = MAX_LEVEL;

	// define todos os headers da esquerda
	sl->upperleft =no_criar(-1, NULL, NULL, MAX_LEVEL);
	
		
	// criar um no NULL NULL
	// fazer o anterior apontar para ele
	// acessar este no criado
	
	no_t* hold = sl->upperleft;
	for(int i = 0; i < sl->max_level-1 ; i++) {
		no_t*aux = no_criar(-1, NULL, NULL, MAX_LEVEL);

		hold->down = aux;
		hold = hold->down;

	}
	

	return sl;
}


int sl_buscar(skiplist_t * sl, item *it) {
	if(!sl && !it) exit(EXIT_FAILURE);
}

no_t *_inserir(no_t*no, item_t*it) {
	
	// sem elementos a frente
	if (no->next ==NULL) {
		if(no->down==NULL) { // sem elementos nem em frente nem abaixo
			//inserir elemento a frente
			no->next = no_criar(item_get_valor(it), NULL, NULL, MAX_LEVEL);
			
			// retorna novo elemento para ser apontado ou NULL
			int coin = rand() %2;

			if (coin) return no->next;
			else return NULL;
		}
		//sem elementos a frente , ha abaixo
		else {
			no_t *temp= _inserir(no->down, it);
		
			// insere novo na fileira de caso temp!=NULL (50% de chance);
			if (temp!=NULL) {
				no->next = no_criar(temp->valor, NULL, temp, MAX_LEVEL); 
				int coin = rand() %2;
				if (coin) return temp;
				else return NULL;
			}
			return NULL;
		}

	}

	// elemento a frente existe
	else {
		// elemento a ser inserido eh maior que o a frente
		if ( item_get_valor(it) > no->next->valor ) {
			return _inserir(no->next, it);
		}
		// elemento a ser inserido eh menor que o da frente (inserir se ultima camada, descer se nao)
		else {
			// ultima camada, inserir
			if (no->down ==NULL) {
				no_t*aux = no_criar(item_get_valor(it), no->next, NULL, MAX_LEVEL);
				no->next = aux;
			
				int coin = rand() %2;
				if (coin) return aux;
				else return NULL;

			}
			//nao eh ultima camada, descer
			else {
				no_t * temp = _inserir(no->down, it);

				// insere caso temp!=NULL (moeda deu 1)
				if (temp!=NULL) {
					no_t * aux = no->next;
					no->next = no_criar(temp->valor, aux, temp, MAX_LEVEL);

					int coin = rand() %2;
					if (coin) return temp;
					else return NULL;
				}
				return NULL;
			}
		}
	}
	return NULL;
}

void sl_inserir(skiplist_t * sl, item_t*it) {
	if (!sl || !it) exit(EXIT_FAILURE);
	// se o elemento ja existe, retorna
	printf("inserindo valor: %d\n", item_get_valor(it));
	//if(_buscar(sl->upperleft, it)) return ;
	_inserir(sl->upperleft, it);
	
}


void sl_imprimir(skiplist_t *sl) {
	no_t * h = sl->upperleft;

	for (;h!=NULL;h = h->down) {
		no_t * linha = h->next;
		for(;;) {
			if(linha == NULL) break;
			printf("%d ", linha->valor);
			linha = linha->next;
		}
		printf("\n");
		//h= h->down;
	}
}
