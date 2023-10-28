#include"../include/item.h"


struct _item {
	elem valor;
};

item_t * item_criar(elem v) {
	item_t * t = NULL;
	t= (item_t*)calloc(1, sizeof(item_t));
	if(!t) exit(EXIT_FAILURE);
	t->valor = v;
	return t;
}

void item_set_valor(item_t * item, elem valor) {
	if(!item ) exit(EXIT_FAILURE);

	item->valor = valor;
} 

elem item_get_valor(item_t * item) {
	if(!item ) exit(EXIT_FAILURE);
	return item->valor;
}
void item_apagar(item_t * item) {
	if(!item ) exit(EXIT_FAILURE);

	free(item);
	item = NULL;
}


