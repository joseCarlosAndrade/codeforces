#include"circulo.h"
#include"ponto.h"

int main(int argc, char ** argv) {
	float x, y, raio;

	scanf("%f %f", &x, &y);
	
	PONTO *p = ponto_criar(x, y);
	
	scanf("%f %f %f", &x, &y, &raio);
	PONTO *centro = ponto_criar(x,y);
	CIRCULO *c = circulo_criar(centro, raio);

	verificar_interioridade(p, c);
}

