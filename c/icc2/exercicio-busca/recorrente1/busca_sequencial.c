/*
 * Exercicio 1 - Analise de busca sequencial.
 *
 * O codigo realiza MAX_MEAN iterações para gerar a media de tempo de execução dos 3 métodos solicitados de busca sequencial:
 * - Metodo convencional
 * - Metodo de transposição
 * - Metodo de mover para frente.
 *
 * Foi constatado que o metodo de mover para frente foi o que apresentou uma menor media de tempo de execução dentre os 3, sendo o metodo da transposição 
 * o segundo mais rápido e, como método mais demorado, o método convencional. 
 * Segue uma saída de uma das execuções do código como exemplo:
 * 

-- Media dos resultados --

Metodo convencional: 0.980786 (s)
Metodo transposição: 0.971014 (s)
Metodo mover para frente: 0.930302 (s) 

Contudo pode-se notar que, devido ao baixo numero de buscas de cada um dos 50 numeros (1000 vezes) o metodo de transposição, em media, se aproxima muito
do método convencional para este caso. 
*/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>


#define MAX_SIZE 10000
#define MAX_NUMBER 100000
#define MAX_MEAN 5
	
int busca_sequencial(int elem, int vetor[], int N) ; // realiza busca sequencial
int busca_recorrente_t(int elem, int vetor[], int N) ; // realiza busca com recuperacao recorrente de registros usando metodo da transposicao
int busca_recorrente_m(int elem, int vetor[], int N) ; // realiza busca com recuperacao recorrente de registros usando metodo mover para frente
void print_vetor(int vetor[], int N);
void print_vetor_tempo(float vetor[], int N);

int main() {
	int N = MAX_SIZE;
	int v[MAX_SIZE];

	// randomizacao, setando semente
        long ltime = time(NULL);
        int stime = (unsigned) ltime/2;
        srand(stime);
	
	float c_media = 0;
	float t_media = 0;
	float m_media = 0;
		
	for (int it = 0; it < MAX_MEAN; it++) { 
		printf("-- Iteração %d --\n", it);
		// preenchendo vetor aleatoriamente
		for (int i = 0; i < MAX_SIZE; i ++) {
			
			v[i] = rand() % MAX_NUMBER;
		}
	
		// metodo sequencial convencional
		float t_inicial = clock();
		for (int i = 1; i < 52 ; i++) {
			for ( int j = 0; j < 1000; j ++) {
				busca_sequencial(i, v, N);
			}	
		}	
		float t_final = clock();
		float t_convencional = (t_final-t_inicial)/CLOCKS_PER_SEC;
		printf("Tempo levado para o método convencional: %f segundos.\n\n", t_convencional);
		c_media += t_convencional;

		// metodo transposicao
		t_inicial = clock();
		for (int i = 1; i < 52 ; i++) {
			for ( int j = 0; j < 1000; j ++) {
				busca_recorrente_t(i, v, N);
			}	
		}	
		t_final = clock();
		
		float t_transposicao = (t_final-t_inicial)/CLOCKS_PER_SEC;
		printf("Tempo levado para o método transposição: %f segundos.\n\n", t_transposicao);
		t_media += t_transposicao;

		// metodo mover para frente
		t_inicial = clock();
		for (int i = 1; i < 52 ; i++) {
			for ( int j = 0; j < 1000; j ++) {
				busca_recorrente_m(i, v, N);
			}	
		}	
		t_final = clock();
	
		float t_mover = (t_final-t_inicial)/CLOCKS_PER_SEC;
		printf("Tempo levado para o método mover-para-frente: %f segundos.\n\n", t_mover);
		m_media += t_mover;
	}

	c_media /= MAX_MEAN;
	t_media /= MAX_MEAN;
	m_media /= MAX_MEAN;

	printf("-- Media dos resultados --\n\n");
	printf("Metodo convencional: %f (s)\n", c_media);
	printf("Metodo transposição: %f (s)\n", t_media);
	printf("Metodo mover para frente: %f (s)\n", m_media);
}

void print_vetor(int vetor[], int N) {
	for (int i = 0; i < N; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

int busca_sequencial(int elem, int vetor[], int N) {
	for ( int i =0; i < N; i++) {
		if (elem == vetor[i]) { 
			return 1; // encontrou
		}
	}
	return 0;
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

int busca_recorrente_m(int elem, int vetor[], int N) {
	for ( int i =0; i < N; i++) {
		if (elem == vetor[i]) { 
			int aux = vetor[0];
			vetor[0] = elem;
			vetor[i] = aux;
			return 1; // encontrou
		}
	}
	return 0; // nao encontrou
}
