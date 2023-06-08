#include<stdio.h>

void preencher_matrix(int N, int M, char matrix[N][M]);
int encontrar_assentos(int N, int M, char assentos[N][M], char disponiveis[N][M]);
void printar_matrix(int N, int M, char matrix[N][M]);
int assento_disponivel(int N, int M, char assentos[N][M], int i, int j);

int main(void)
{
    int N, M;

    scanf("%d %d", &N, &M);
    char assentos[N][M];
    char disponiveis[N][M];

    preencher_matrix(N, M, assentos);
    int encontrou = encontrar_assentos(N, M, assentos, disponiveis);

    if (encontrou > 0)    printar_matrix(N, M, disponiveis);
    else printf("Eh um dia triste para os mono Yasuo\n");
    
}

void preencher_matrix(int N, int M, char matrix[N][M] )
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char numero;
            scanf(" %c", &numero);
            // printf(" char: %c; ", numero);
            matrix[i][j] = numero;
        }
    }
}

int encontrar_assentos(int N, int M, char assentos[N][M], char disponiveis[N][M])
{
    int quantidade = 0;
    for (int i = 0; i < N; i ++)
    {
        for (int j = 0 ; j < M; j ++)
        {
            if (assentos[i][j] == 'v')
            {
                if (assento_disponivel(N, M, assentos, i, j)) {disponiveis[i][j] = 'o';quantidade++;}
                else disponiveis[i][j] = 'x';
            }
            else disponiveis[i][j] = 'x';
        }
    }
    return quantidade;
}

int assento_disponivel(int N, int M, char assentos[N][M], int i, int j)
{
    for (int lin = 0; lin < N; lin++)
    {
        if (assentos[lin][j] == 'c') 
        {
            // printf("%c ", assentos[lin][j]);
            return 0;
        }
    }
    // printf("\n");
    for (int col = 0; col < M; col++)
    {
        if (assentos[i][col] == 'c') 
        {
            // printf("%c ", assentos[i][col]);
            return 0;
        }
    }

    return 1;
}

void printar_matrix(int N, int M, char matrix[N][M])
{
    for (int i = 0; i < N ; i ++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
