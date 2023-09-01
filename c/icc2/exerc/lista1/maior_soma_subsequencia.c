#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int * ler_vetor(int n);
int * encontrar_maior_subsequencia(int * vetor, int* subsequencia, int n, int *ultima_soma, int*tam);
void swap(int ** v, int ** p);
void printar_vetor(int *vetor, int n);

int main(int argc, char ** argv) {

	int n;
	scanf("%d", &n);

	int *vetor = ler_vetor(n);
	
	int * subsequencia = (int*)calloc(n, sizeof(n));
	assert(subsequencia != NULL);
	int maior_soma = -99999;
	int tamanho_sub;
	subsequencia = encontrar_maior_subsequencia(vetor, subsequencia, n, &maior_soma, &tamanho_sub);

	printf("%d\nmaior sub: ", maior_soma);
	printar_vetor(subsequencia, tamanho_sub+1);

	return 0;
}

/* funcao padrao que le um vetor de tamanho n e o retorna */
int * ler_vetor(int n) {
	int * v = (int *)calloc(n, sizeof(int));
	assert(v!=NULL);
	
	for (int i = 0; i < n; i ++) {
		scanf(" %d", &v[i]);
	}

	return v;
}

/* funcao recursiva que retorna a subsequencia de um vetor que tenha a maior soma, modificando o valor *ultima_soma que armazena
 * a maior soma encontrada, e o valor *tam que representa o tamanho da subsequencia retornada */
int* encontrar_maior_subsequencia(int * vetor, int * subsequencia, int n, int *ultima_soma, int*tam) {
	if (n == 1) {
		if (vetor[0] > *ultima_soma) {
			*ultima_soma = vetor[0];
			swap(&subsequencia, &vetor);
			*tam=0;
		}

		return subsequencia;
	}
	
	int * temp = (int*)calloc(n,sizeof(int)); // vetor temporario que armazena os maiores elementos
	assert(temp!=NULL);

	for(int i = n-1; i >= 0; i--) {
		int soma_temp = 0;
		for (int j = 0; j <= i; j++) {

			soma_temp += vetor[j];	
			temp[j] = vetor[j]; // copiando elementos para vetor temporario;
		}
		if (soma_temp > *ultima_soma) {
			*ultima_soma = soma_temp;

			//swap vetores
			swap(&subsequencia, &temp);
			*tam = i;
		}

		temp = (int*)calloc(n, sizeof(int));
		assert(temp!=NULL);
	}
	free(temp);
	return encontrar_maior_subsequencia(++vetor, subsequencia, n-1, ultima_soma, tam);
}

/* swap para trocar as variaveis recebidas de posicao */
void swap(int ** v, int ** p) {
	int *temp = *v;
	*v = *p;
	*p = temp;
}

/* funcao padrao para pritnar vetores de tamanho n */
void printar_vetor(int *vetor, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	}

		printf("\n");
	
}
