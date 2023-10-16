#include"../include/lista_generalizada.h"

int main() {

	no_t * l = concat(sublista(concat(atomo(2), atomo(3))), atomo(2));
	imprimir(l);

	imprimir(cabeca(l));
	imprimir(cauda(l));

	return 0;
}
