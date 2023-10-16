#include<../include/item.h>


struct _item {
	elem valor;
};

item_t * item_criar(elem v) {
	item_t * t = NULL;
	t= (item_t*)calloc(1, sizeof(item_t));
	assert(t!=NULL);

	return t;
}

void item_set_valor(item_t * item, elem valor) {
	assert(item_t != NULL);

	item->valor = valor;
} 

elem item_set_valor(item_t * item) {
	assert(item!=NULL);
	return item->valor;
}
void item_apagar(item_t * item) {
	assert(item !=NULL);

	free(item);
	item = NULL;
}


