#include <stdio.h>
#include <stdlib.h>


/*implementar funcao que recebe a e b, 
 * e coloca o valor de a em b e de b em a*/
void trocar(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;

}

/*
 *Implemente uma funcao que recebe a e b, se forem iguais retorna 0,
 *se a for menor retorna um numero negativo, se nao um numero positivo
 */
int retorna_comparacao(int a, int b)
{
    if (a==b){
        return 0;
    }
    if (a > b) return 1;
    return -1;
}

int ordena(int n, int v[])
{
    int trocas = 0;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (retorna_comparacao(v[j], v[j+1]) > 0)
            {
                trocar(&v[j], &v[j+1]);
                trocas++;
            }
        }

    }
    return trocas;
}
/*
 *implementar funcao que recebe o vetor v,
 *Compare o primeiro elemento com o próximo elemento adjacente.
 *Se o primeiro elemento for maior que o próximo, troque suas posições.
 *Continue comparando e trocando os elementos adjacentes ao longo da lista.
 *Ao final da primeira iteração, o maior elemento estará na última posição da lista.
 *Repita os passos, percorrendo a lista novamente, mas ignorando a última posição.
 *Continue repetindo esse processo até que não ocorram mais trocas durante uma iteração completa.
 *Retorne o número de trocas feitas 
 */

int main(int argc, char** argv) {
    int n;
    scanf(" %d", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }

    int trocas = ordena(n, v);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Foram feitas %d trocas\n", trocas);

    return (EXIT_SUCCESS);
}
