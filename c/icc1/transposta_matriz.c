#include <stdio.h>

void preencher_matrix(int N, int M, float matrix[][M] );
void calcular_transposta(int N, int M, float matrix[][M], float transposta[][M]);
void printar_matrix(int N, int M, float matrix[][M]);

int main()
{
    int N, M;
    printf("Digite as dimensões N M da matriz (linha e coluna):\n");
    scanf("%d %d", &N, &M);

    float matrix[N][M], transposta[M][N];

    printf("\nPreencha a matriz, elemento a elemento:\n");
    preencher_matrix(N, M, matrix);
    calcular_transposta(N, M, matrix, transposta);

    printf("\nMatriz original:\n");
    printar_matrix(N, M, matrix);
    printf("\nMatrix transposta:\n");
    printar_matrix(M, N, transposta);
}

void preencher_matrix(int N, int M, float matrix[][M] )
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            float numero;
            scanf("%f", &numero);

            matrix[i][j] = numero;
        }
    }
}

void calcular_transposta(int N, int M, float matrix[][M], float transposta[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j ++)
        {
            transposta[j][i] = matrix[i][j];
        }
    }
}

void printar_matrix(int N, int M, float matrix[][M])
{
    for (int i = 0; i < N ; i ++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}
