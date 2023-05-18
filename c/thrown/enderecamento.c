#include<stdio.h>
#define N 10

int main(void)
{
    int A[N], *p;

    for (int i = 0; i< N; i++)
    {
        A[i] = i;
    }

    printf("Enderecamento: \n");
    printf("&A: %p\n", &A);
    printf("A: %p\n", A);
    printf("&A[1]: %p\n", &A[1]);
    printf("A+1: %p\n", A+1);

    printf("\nConteudo: \n");
    printf("A[0]: %d\n", A[0]);
    printf("*A: %d\n", *A);
    printf("*(A+1): %d\n", *(A+1));

    // p=A;
    // percorrer por uma array 
    for (p = A; p < &A[N]; p++)
    {
        printf("%d ", *p);
    }
}