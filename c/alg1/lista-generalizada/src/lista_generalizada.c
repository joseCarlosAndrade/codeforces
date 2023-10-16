#include"../include/lista_generalizada.h"

struct bloco {
	// union: ou eh um atomo ou eh uma sublista (ponteiro)
	union {
		elem atomo;
		no_t * sublista;
	} info;

	int tipo; // define se eh um atomo (0) ou sublista (1) para leitura
	no_t * prox; // proximo no
};


void libera(no_t *p) {
	assert( p!=NULL);
	
	//TODO rotina de liberacao
		
	free(p);
}


no_t *atomo( elem x) {
	no_t* atomo = NULL;
	atomo = (no_t *)calloc(1, sizeof(no_t));
	assert(atomo!=NULL);

	atomo->info.atomo = x;
	atomo->tipo = 0; 
	atomo->prox = NULL;

	return atomo;
}

no_t *sublista( no_t*sublista) {
	no_t *sub = NULL;
	sub = (no_t*)calloc(1,sizeof(no_t));
	assert(sub!=NULL && sublista!=NULL);

	sub->info.sublista = sublista;
	sub->tipo = 1;
	sub->prox = NULL;

	return sub;
}

no_t *copiar(no_t *target, no_t *source) {
	assert ( target!= NULL && source!=NULL );

	target->tipo = source->tipo;
	target->prox = source->prox;

	if ( source->tipo) target->info.sublista = source->info.sublista; // se lista
	else target->info.atomo = source->info.atomo; // se atomo

	return target;
}


no_t *concat(no_t * p, no_t * q) {
/* alpha way
 
	assert(p!=NULL && q!=NULL);
	
	no_t * new_no1 = NULL;
	new_no1 = (no_t *) calloc(1,sizeof(no_t));
	
	no_t * new_no2 = NULL;
	new_no2 = (no_t *) calloc(1,sizeof(no_t));
	
	assert(new_no1!=NULL && new_no2!=NULL);
		
	copiar(new_no1, p);
	copiar(new_no2, q);

	new_no1->prox = new_no2;

	return new_no1;
*/

	assert(p!=NULL && q!=NULL);
	p->prox = q;
	return p;
}


no_t *cabeca(no_t *p) {
	assert (p!=NULL);

	no_t * new_no = NULL;
	new_no = (no_t*)calloc(1,sizeof(no_t));

	copiar(new_no, p);

	new_no->prox=NULL;

	return new_no;
}

no_t *cauda(no_t *p) {
	assert(p!=NULL);

	if( p->prox == NULL) return p;

	return cauda(p->prox);
	
}


void _imprimir_lista(no_t*sublista) {
	if ( sublista->tipo == 0) {
		printf(" %d ", sublista->info.atomo);
	}
	if ( sublista->tipo == 1) {
		printf("[");
		_imprimir_lista(sublista->info.sublista);
		printf("]");
	}
	if (sublista->prox == NULL) return;

	_imprimir_lista(sublista->prox);
}

void imprimir(no_t *p) {
	// ciclar pelo caminho padrao
	//
	// ciclar pelas sublistas
	assert(p!=NULL);
	printf("[");

	_imprimir_lista(p);

	printf("]\n");
}
