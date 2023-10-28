#include"include/skiplist.h"

int main() {
	skiplist_t * sl= sl_criar();
//	sl_inserir(sl, item_criar(10));
//	sl_inserir(sl, item_criar(30));
//	sl_inserir(sl, item_criar(15));
//	sl_inserir(sl, item_criar(3));
//	sl_inserir(sl, item_criar(22));
//	sl_inserir(sl, item_criar(21));
//	sl_inserir(sl, item_criar(1));
//	sl_inserir(sl, item_criar(50));
//	sl_inserir(sl, item_criar(55));

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sl_inserir(sl, item_criar(a));
		sl_imprimir(sl);
	}
	//sl_imprimir(sl);
}
