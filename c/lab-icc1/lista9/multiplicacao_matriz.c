#include<stdio.h>

void preencher_matriz(int n, int  m, int matrix[][m]);
void multiplicar_matriz(int n1, int m1, int n2, int m2, int matrix1[][m1], int matrix2[][m2], int matrix_multiplicada[n1][m2]);
void printar_matriz(int n, int m, int matriz[][m]);

int main(void){
    int m1, m2, n1, n2;
    scanf("%d %d %d %d", &n1, &m1, &n2, &m2);

    int matrix1[n1][m1], matrix2[n2][m2], multiplicada[n1][m2];

    preencher_matriz(n1, m1, matrix1);
    preencher_matriz(n2, m2, matrix2);

    if (n1 != m2 && n2 != m1) printf("Impossível multiplicar matrizes com essas dimensões.\n");
    else {
        multiplicar_matriz(n1, m1, n2, m2, matrix1, matrix2, multiplicada);

        printar_matriz(n1, m2, multiplicada);
    }
}

void preencher_matriz(int n, int m, int matrix[][m])
{
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplicar_matriz(int n1, int m1, int n2, int m2, int matrix1[][m1], int matrix2[][m2], int matrix_multiplicada[n1][m2])
{
    int soma_atual;

    for (int linha1 = 0; linha1 < n1; linha1++)
    {   
        
        for (int i = 0; i < m2; i++){
            soma_atual = 0;
            for(int coluna1 = 0; coluna1 < m1; coluna1++)
            {
                soma_atual += matrix1[linha1][coluna1]*matrix2[coluna1][i];
            }
            matrix_multiplicada[linha1][i] = soma_atual;
        }
    }
}

void printar_matriz(int n, int m, int matriz[][m])
{
    for (int i = 0; i < n; i ++)
    {
        for (int j =0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}