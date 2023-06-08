#include<stdio.h>

void preencher_matriz(int N, int matriz[][N]);
int calcular_determinante(int N, int matriz[][N]);

int main(void)
{
    int N;
    scanf("%d", &N);

    int matriz[N][N];
    preencher_matriz(N, matriz);

    int determinante = calcular_determinante(N, matriz);
    printf("%d\n", determinante);
}

void preencher_matriz(int N, int matriz[][N]){
    for (int i = 0; i < N; i++)
    {
        for( int j = 0; j < N; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int calcular_determinante(int N, int matriz[][N])
{
    int determinante = 0;

    if (N == 1) return matriz[0][0];
    
    else if (N == 2)
    {
        for (int i = 0; i < 2; i ++)
        {
            determinante += matriz[0][i]*matriz[1][1-i];
            determinante *= -1;
            // printf(" d %d; ", determinante);
        }
    }

    else if ( N == 3) {
        
            int det = 0;
            for (int i = 0; i < 2; i++)
            {
                det += matriz[1][i+1] * matriz[2][2-i];
                det *= -1;
            }
            determinante += matriz[0][0]*det;

            det = 0;
            for (int i = 0; i < 2; i++)
            {
                det += matriz[1][2*i] * matriz[2][2-2*i];
                det *= -1;

            }
            determinante -= matriz[0][1]*det;

            det = 0;
            for (int i = 0; i < 2; i++)
            {
                det += matriz[1][i] * matriz[2][1-i];
                det *= -1;
            }
            determinante += matriz[0][2]*det;

            // if (v == 1) det *= -1;
            // determinante += matriz[0][0]*det;
        }
    return determinante;
    
}
