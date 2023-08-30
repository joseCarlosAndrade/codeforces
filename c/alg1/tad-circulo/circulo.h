#ifndef CIRCULO_H
    #define CIRCULO_H

    #include "ponto.h"
	
    #include<stdlib.h>
    #include<stdio.h>

    typedef struct circulo_ CIRCULO;
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ);

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
    // implementaco da distancia aqui pois circulo.c inclui as definicoes de ponto.h
    float distancia(PONTO * ponto, CIRCULO * circulo);
#endif
    void verificar_interioridade(PONTO * ponto, CIRCULO * circulo);

