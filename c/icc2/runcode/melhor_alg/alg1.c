#include<stdio.h>
#include<stdlib.h>

#define MAX_T 100000 // numero maximo de consultas
#define MAX_X 1000000 // numero maximo de dinheiro por consulta

void print_max(int x, int max[3]);

int main(void) {
	int T;
	scanf("%d", &T);

	int max[3] = {-1, -1, -1}; // maximo em ordem decrescente

	for(int i = 0; i < T; i ++) {
		int Xi;
		scanf("%d", &Xi);
		print_max(Xi, max);		
		
		if (i!=T-1) // para igualar o output do runcodes (?) nao tem um \n final
		printf("\r\n");
	}
}

void print_max(int x, int max[3]) {
	for(int i = 0; i < 3; i++) {
		/* Desloca elementos para a direita
		 * -1 -1 -1 
		 *  3 -1 -1 -1(apagado);
		 * */
		if ( x > max[i] ) {
			
			for( int j = 2; j > i; j --) {
				max[j] = max[j-1];
					
			}
			max[i] = x;
			break;
		}
	}

	if ( max[2] == -1) {
		printf("-1");
		return;
	}
	printf("%d %d %d", max[0], max[1], max[2]);
}
