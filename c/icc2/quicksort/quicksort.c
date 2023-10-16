#include<stdio.h>
#include<stdlib.h>

void my_quicksort(int vetor[], int n);
void my_sort(int vetor[], int inicio, int fim);

int main(void) {
	
	int vetor[10] = {14, 15, 46, 56,13 ,76 ,12 ,45, 98,1};
	my_quicksort(vetor, 10);

	for (int i = 0; i  < 10; i ++) {
		printf("%d ", vetor[i]);	
	}
	printf("\n");
}

void my_quicksort(int vetor[], int n) {
	
	my_sort(vetor, 0, n-1);
	
}

void my_sort(int vetor[], int inicio, int fim) {
	printf("\n sotr: inicio: %d  fim: %d\n", inicio, fim);
	if(fim-inicio <= 1) return; // caso base

	int pivo_index = (inicio+fim)/2;
	int pivo = vetor[pivo_index];
	int i, j;

	while(1){
		i = 0;
		j = fim;
		//int i_element , j_element;
		
		for ( i = inicio; i <= pivo_index;i++){
			if ( vetor[i] >= pivo) {
		//		i_element = i;
			
				break;
			}
		}
		for ( j = fim; j >= pivo_index; j--) {
			if ( vetor[j] <= pivo) {
		//		j_element = j;
				break;
			}
		} 

		
		if (i == j) break; // se i = j = pivo, fim da operacao
		// trocar elementos de i e j
		int aux = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = aux;

		if ( i == pivo_index) pivo_index=j;
		if ( j == pivo_index) pivo_index=i;

		printf("pivo_i: %d i: %d j: %d\n",pivo_index, i, j);	
		for (int o = 0; o < 10; o++) {
		printf("%d ", vetor[o]);
		}
		printf("\n");

	}
	
	my_sort(vetor,  inicio,  pivo_index-1);
	my_sort(vetor, pivo_index+1, fim); 
}



