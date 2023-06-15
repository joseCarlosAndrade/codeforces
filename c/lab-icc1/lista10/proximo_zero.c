#include<stdio.h>
#include<stdlib.h>

void preencher_vetor(int N, int * vetor);
void printar_vetor(int N, int * vetor);
int proximo_de_zero(int N, int * vetor);
void printar_posicoes(int N, int numero, int * vetor);

int main(void)
{
    int N;
    scanf("%d", &N);

    int * vetor = (int*)calloc(N , sizeof(int));

    preencher_vetor(N, vetor);
    // printar_vetor(N, vetor);
    int numero = proximo_de_zero(N, vetor);
    printar_posicoes(N, numero, vetor);

}

void preencher_vetor(int N, int * vetor)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d", (vetor+i));
    }
}

void printar_vetor(int N, int * vetor)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(vetor+i));
    }
    printf("\n");
}

int proximo_de_zero(int N, int * vetor)
{
    int proximo = *vetor;

    for (int i = 1 ; i < N; i++ )
    {
        if ( abs(*(vetor+i)) > abs(proximo) ) continue;
        proximo = *(vetor+i);
    }

    return proximo;
}

void printar_posicoes(int N, int numero, int * vetor)
{

    printf("%d\n", numero);

    for (int i = 0; i < N; i ++)
    {
        if( *(vetor+i) - numero) continue;

        printf("%d ", i);
    }
    printf("\n");
}
