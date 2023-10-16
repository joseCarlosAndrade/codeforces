#include"../include/item.h"

struct item_ {
	elem valor;
	
};

ITEM* item_criar(int chave) {
	ITEM *it = NULL;
	it = (ITEM*)calloc(1, sizeof(ITEM));
	assert(it!=NULL);

	it->valor = chave;
	return it;
}

bool item_apagar(ITEM **item) {
	assert(*item !=NULL);

	free(*item);
	*item = NULL;
	return 1;
}

void item_imprimir(ITEM *item) {
	assert(item!=NULL);

	printf("[%d]; ", item->valor);

}

int item_get_chave(ITEM* item) {
	assert(item!=NULL);

	return item->valor;
}

bool item_set_chave(ITEM * item, int chave) {
	assert(item!=NULL);

	item->valor = chave;
	return 1;
}
