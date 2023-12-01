#include<stdlib.h>
#include<stdio.h>
#include<time.h>


#define MAX_SIZE 10000
#define MAX_NUMBER 100000

int busca_recorrente_t(int elem, int vetor[], int N) ; // realiza busca com recuperacao recorrente de registros usando metodo da transposicao
void print_vetor(int vetor[], int N);
void print_vetor_tempo(float vetor[], int N);

int main() {
	int N = MAX_SIZE;
	int v[MAX_SIZE];

	// randomizacao, setando semente
        long ltime = time(NULL);
        int stime = (unsigned) ltime/2;
        srand(stime);

	// preenchendo vetor aleatoriamente
	for (int i = 0; i < MAX_SIZE; i ++) {
		
		v[i] = rand() % MAX_NUMBER;
	}

	// realizando 50 buscas
	int search_vector[50];
	int number = 1;
	int i = 0;

	float time_vector[50*3];
	int tindex = 0;

	for (i = 0; i < 50; ) {
		int found = 0;	
		for (int j = 0; j < 1000; j++) {
			float tempo_inicial = clock();
			found =busca_recorrente_t(number, v, N); 
			if (!found) { // se nao encontra o numero no vetor, quebra  looping e tenta procurar pelo proximo
				number++;
				break;
			} else {
				float tempo_final = clock();	
				if (j == 0)  {
					time_vector[tindex++] = (float)number;
					time_vector[tindex++] = ((tempo_final-tempo_inicial)/CLOCKS_PER_SEC)*1000;
				}
				else if (j == 1000-1) {
					time_vector[tindex++] = ((tempo_final-tempo_inicial)/CLOCKS_PER_SEC)*1000;
				}
			}
		}
		if (found)  { 
			search_vector[i] = number;
			i++;
			number++;
		}
	}
	
	print_vetor_tempo(time_vector, 50*3);
	//print_vetor(v,  N);
	//int elem_buscado = 10;
	//if (busca_recorrente_t(elem_buscado, v, N)) {
	//	printf("Encontrou elemento %d, printando vetor: \n", elem_buscado);
	//	print_vetor(v, N);
//	}
}

void print_vetor(int vetor[], int N) {
	for (int i = 0; i < N; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

int busca_recorrente_t(int elem, int vetor[], int N) {
	int index_troca = -1; // index a ser utilizado na troca (transposicao)
	for ( int i =0; i < N; i++) {
		if (elem == vetor[i]) { 
			index_troca = i;
			break;
		}
	}

	if (index_troca == -1) return 0; // nao encontrou
	
	if (index_troca == 0) return 1; // encontrou e nao altera pois ja eh o primeiro elemento

	// troca de elementos
	int temp = vetor[index_troca-1];
	vetor[index_troca-1] = elem;
	vetor[index_troca] = temp;
	return 1;
}

void print_vetor_tempo(float vetor[], int N) {
	for (int i = 0; i < N; i += 3) {
		printf("number searched: %.0f, initial time took (ms): %f, final time took (ms): %f\n", vetor[i], vetor[i+1],vetor[i+2]);
	}
}
