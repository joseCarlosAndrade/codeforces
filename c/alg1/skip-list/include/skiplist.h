#include"item.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

typedef struct _no no_t;
typedef struct _skiplist skiplist_t;

/* Cria uma skip list */
skiplist_t * sl_criar();

/* Busca um elemento dentro da skiplist */
int sl_buscar(skiplist_t* sl, item_t *it);

/* Insere um elemento na skip list */
void sl_inserir(skiplist_t *sl, item_t*it);

/* Imprime a skiplist */
void sl_imprimir(skiplist_t *sl);

/* Cria um no */
no_t * no_criar(int valor, no_t * next, no_t * down, int level);

