#include<stdio.h>
#include<stdlib.h>

typedef int elem;

typedef struct _item item_t;

/* Cria um item com o valor v e retorna um ponteiro para este novo item */
item_t * item_criar(elem v);

/* Altera o valor desse item */
void item_set_valor(item_t * item, elem valor);

/* Retorna o valor do item */
elem item_get_valor(item_t *item);

/* Apaga este item */
void item_apagar(item_t * item);
