#include"../include/item.h"

int main(void) {
	ITEM* item = item_criar(10);

	item_imprimir(item);

	item_set_chave(item, 11);

	item_imprimir(item);
	item_apagar(&item);
}
