#include<stdio.h>
#include<stdlib.h>

/*
Autor: José Carlos Andrade do Nascimento

Maneira alternativa mais eficiente para a alocação de memoria dinamica para criar matrizes
Metodo:
Aloca uma matriz das linhas


double ** linhas -> double * | double * | double * | double * | (N vezes)

double * matrix -> double | double | double | ... | double | (N x M vezes)

cada elemento de linhas armazena um ponteiro para elementos especificos da matriz maior:

d*|   | d*|   | d*|   | d*|
d | d | d | d | d | d | d | d |
0   1   2   3   4   5   6   7

retorno de **linhas -> acessando com matrix[i][j]
*/

double ** criar_matriz(int N, int M);
void preencher_matriz(double ** matrix, int N, int M);
void printar_matriz(double ** matrix, int N, int M);
void liberar_matriz(double ** matrix, int N, int M);

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	double ** matrix = criar_matriz(N, M);

	preencher_matriz(matrix, N, M);
	
	printf("\n");
	printar_matriz(matrix, N, M);
	

}

double ** criar_matriz(int N, int M)
{
	double ** linhas = (double **) calloc(N, sizeof(double*));
	
	double * matrix = (double *) calloc(N*M, sizeof(double));

	for (int i = 0; i < N; i++)
	{
		*(linhas+i) = &matrix[i*M];	
	}
	return linhas;
}


void preencher_matriz(double ** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j ++)
		{
			//scanf("%lf", *(matrix + M*i +j));
			scanf("%lf", &matrix[i][j]);
		}
	}
}

void printar_matriz(double ** matrix, int N, int M)
{
	for ( int i = 0; i < N ; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%lf ", matrix[i][j]);	
		}
		printf("\n");
	}
}

void liberar_matriz(double ** matrix, int N, int M)
{
	for (int i = 0 ; i < N; i++)
	{
		free(matrix[i]);
	}
	
	free(matrix);
}


/*
 * 	Ilustração da alocaçao 

	x x x
	x x x
	x x x
	x x x
 
	x x x

	0 1 2   3 4 5   6 7 8   9 10 11
	l l l | l l l | l l l | l l l

 * */
