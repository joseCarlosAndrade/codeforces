#include<stdio.h>
#include<stdlib.h>


void preencher_matrix(int N, int M, int * matrix);
void calcular_transposta(int N, int M, int * matrix, int * transposta);
void printar_matrix(int N, int M, int * matrix);

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    // float matrix[N][M], transposta[M][N];
    int * matrix = (int *)calloc(N*M, sizeof(int));
    int * transposta = (int *)calloc(N*M, sizeof(int));

    preencher_matrix(N, M, matrix);
    calcular_transposta(N, M, matrix, transposta);

    // printf("\nMatriz original:\n");
    // printar_matrix(N, M, matrix);
    // printf("\nMatrix transposta:\n");
    printar_matrix(M, N, transposta);
}

void preencher_matrix(int N, int M, int *matrix)
{
    for (int i = 0; i < N*M; i++)
    {
        scanf("%d", (matrix+i));
        // printf("%d\n", *(matrix+i));
    }
}

void calcular_transposta(int N, int M, int * matrix, int * transposta)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j ++)
        {
            // transposta[j][i] = matrix[i][j];
            *(transposta +j*N + i) = *(matrix + i*M + j);
        }
    }
}

void printar_matrix(int N, int M, int * matrix)
{
    for (int i = 0; i < N*M ; i ++)
    {
        if ( i%M == 0 && i != 0) printf("\n");

        printf("%2d ", *(matrix + i));

    }
    printf("\n");
}
