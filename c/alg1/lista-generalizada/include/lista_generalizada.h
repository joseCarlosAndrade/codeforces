#ifndef LISTA_GEN_H
#define LISTA_GEN_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// definindo tipo de elemento
typedef elem;

typedef struct bloco no_t;


void libera(no_t *p);

/* Retorna um atomo com valor elem x */
no_t *atomo( elem x);

/* Retorna uma sublista da lista passada por argumento */
no_t *sublista( no_t *sublista);

/* Copia as informacoes do segundo no para o primeiro */
no_t *copiar(no_t * target, no_t * source);

/* Retorna um no resultado da concatenaçao de dois nos */
no_t *concat(no_t * p, no_t*q);

/* Retorna a cabeca da lista p */
no_t *cabeca(no_t* p);

/* Retorna a cauda da lista p */
no_t *cauda(no_t *p);

/* Imprime a lista p */
void imprimir(no_t *p);

#endif
