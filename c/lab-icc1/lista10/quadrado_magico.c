#include<stdio.h>
#include<stdlib.h>

void preencher_matrix(int N, int * matrix);
int not_linha(int N, int * matrix);
int not_coluna(int N, int * matrix);
int not_diagonal(int N, int * matrix);

int main(void)
{
    int N;
    scanf("%d", &N);

    int * matrix = calloc(N*N, sizeof(int));

    preencher_matrix(N, matrix);


    if (not_linha(N, matrix) || not_coluna(N, matrix) || not_diagonal(N, matrix)) printf("NAO\n");
    else printf("SIM\n");
}

void preencher_matrix(int N, int *matrix)
{
    for (int i = 0; i < N*N; i++)
    {
        scanf("%d", (matrix+i));
    }
}

int not_linha(int N, int *matrix)
{

    for (int i = 0; i < N-1; i++)
    {
        int soma_anterior = 0;
        int soma = 0;
        for (int j = 0; j < N; j++)
        {
            soma += *(matrix + N*i +j);
            soma_anterior += *(matrix + N*(i+1) + j);
        }

        if (soma != soma_anterior) return 1; // retorna true -> linhas nao condizem com quadrado magico
    }
    return 0;
}

int not_coluna(int N, int *matrix)
{
    
    for (int i = 0; i < N-1; i++)
    {
        int soma_anterior = 0;
        int soma = 0;
        for (int j = 0; j < N; j++)
        {
            soma += *(matrix + N*j +i);
            soma_anterior += *(matrix + N*(j) + i+1);
        }

        if (soma != soma_anterior) return 1; // retorna true -> colunas nao condizem com quadrado magico
    }
    
    return 0;
}

int not_diagonal(int N, int *matrix)
{
    int soma = 0;
    int soma_diagonal = 0;

    // obter a soma necessaria. Se o programa chegou ate aqui, eh pq as colunas e as linhas condizem
    for (int i = 0; i < N; i++) soma += *(matrix+i); 

    for (int i = 0; i < N; i++)
    {
        soma_diagonal += *(matrix + N*i + i) ;
    }

    if (soma_diagonal != soma) return 1;

    
    return 0;

}