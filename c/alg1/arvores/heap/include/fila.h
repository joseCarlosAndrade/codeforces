#ifndef FILA_H
#define FILA_H

#define MAX 100 // numero maximo de elementos da heap

typedef int elem;
typedef struct no no_t;
typedef struct fila fila_t;


fila_t * criar();
int inserir(fila_t *f, elem chave, int prior);
int remover(fila_t *f, elem *chave);
int isEmpty(fila_t *f);
int isFull(fila_t *f);
void finalizar( fila_t *f);


#endif