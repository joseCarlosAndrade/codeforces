#include <stdio.h>
void preencher_vetor(int vetor[], int N);
void printar_posicao(int vetor[], int N);

int main(void)
{
    int N, vetor_pontuacao[10];
    scanf("%d", &N);
    preencher_vetor(vetor_pontuacao, N);

    // ordenar_vetor(vetor_pontuacao, vetor_atletas, N);
    printar_posicao(vetor_pontuacao, N);
}

void printar_posicao(int vetor[], int N)
{   
    int posicao;
    for (int i = 0; i < N ; i++)
    {
        posicao = N;
        for (int j = 0; j < N; j++)
        {
            if (vetor[i] > vetor[j]) posicao--;
        }
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i+1, vetor[i], posicao);
    }
}

void preencher_vetor(int vetor[], int N)
{
    for (int i = 0; i< N; i++)
    {
        scanf("%d", &vetor[i]);
    }
}
