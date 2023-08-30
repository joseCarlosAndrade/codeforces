#include"ponto.h"


PONTO *ponto_criar(float x, float y) {
	PONTO* p = NULL;
	p = calloc(1, sizeof(PONTO));
	
	assert( p != NULL); // caso nao seja satisfeito, o programa para
	p->x = x;
	p->y = y;

	return p;
}

void ponto_apagar(PONTO* p) {
	free (p);
}	

bool ponto_set(PONTO *p, float x, float y) {
	assert(p!= NULL);

	p->x=x;
	p->y=y;

	return true;
}
