#ifndef PONTO_H
    #define PONTO_H
	#include <stdbool.h>
	
	/* Alteracao realizada: inclusao de assert.h e stdlib.h para que 
	 * ponto.c e circulo.c possam ter acesso. */
	#include<assert.h>
	#include<stdlib.h>

// definicao do ponto neste header, pois assim fica acessivel para ponto.c e circulo.c, sem ser necessario implementar duas vezes
    struct ponto_
{
        float x, y;
};


    typedef struct ponto_ PONTO;
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y);

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif





