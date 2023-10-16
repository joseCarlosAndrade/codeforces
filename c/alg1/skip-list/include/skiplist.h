#include<item.h>


typedef struct _no _no_t;
typedef struct _skiplist skiplist_t;

/* Cria uma skip list */
skiplist_t * sl_criar();

/* Insere um elemento na skip list */
void sl_inserir(skiplist_t *sl, item_t*it);

/* Cria um no */
no_t * _no_criar(int valor, int level, _no_t * next, _no_t * down);
