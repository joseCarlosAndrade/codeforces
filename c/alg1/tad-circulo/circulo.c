#include<math.h>
#include"ponto.h"

#include"circulo.h"

struct circulo_
{
	PONTO* centro;
	float raio;
};



CIRCULO *circulo_criar(PONTO *p, float raio) {
	CIRCULO * c = NULL;
	c = calloc(1, sizeof(CIRCULO));
	assert(c!= NULL);

	c->centro = p;
	c->raio = raio;
	return c;
}

void circulo_apagar(CIRCULO *circ) {
	free(circ);
}

float circulo_area(CIRCULO *circ) {
	float pi = 3.1415;

	assert(circ != NULL);
	return pi * circ->raio * circ->raio;
	
}

// implementaco da distancia aqui pois circulo.c inclui as definicoes de ponto.h 
float distancia(PONTO* ponto, CIRCULO * circulo) {
	assert(ponto != NULL);
	assert(circulo != NULL);

	float x = ponto->x;
	float y = ponto->y;
	return  sqrt( pow( x - circulo->centro->x ,2) + pow(y - circulo->centro->y,2) );
}

void verificar_interioridade(PONTO * ponto, CIRCULO * circulo) {

	float dist = distancia(ponto, circulo);
	if (dist < circulo->raio)  printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
	else if (dist == circulo->raio) printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist); 
	else printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist); 
}
