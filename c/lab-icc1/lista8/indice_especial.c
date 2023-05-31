#include <stdio.h>

int somar_elementos(int vetor[], int N);
int index_especial(int vetor[], int N, int soma_total);
void preencher_vetor(int vetor[], int N);

int main(void)
{
    int N, soma_total;

    scanf("%d", &N);

    int vetor[N];
    preencher_vetor(vetor, N);
    soma_total = somar_elementos(vetor, N);

    printf("%d\n", index_especial(vetor, N, soma_total));


}

int somar_elementos(int vetor[], int N)
{
    int soma_total = 0;

    for (int i = 0; i <N; i++)
    {
        soma_total += vetor[i];
    }

    return soma_total;
}

void preencher_vetor(int vetor[], int N)
{
    for (int i = 0; i <N; i++)
    {
        scanf("%d", &vetor[i]); 
    }
}

int index_especial(int vetor[], int N, int soma_total)
{
    // int valor_especial;

    for (int i = 0; i < N ; i ++)
    {
        int soma_atual = 0;
        for (int j = 0; j < i; j++)
        {
            soma_atual += vetor[j];
        }

        if (soma_atual*2 == soma_total-vetor[i])
        {
            return i;
        }
    }

    return -1;
}


/*
0 0 0 0 0

(soma_total - vetor[i])/2 = soma atual
*/