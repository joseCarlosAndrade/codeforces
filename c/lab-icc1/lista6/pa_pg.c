#include<stdio.h>

int main(void)
{
    int n;
    float a1,r, resultado;
    scanf("%d", &n);
    scanf("%f %f", &a1, &r);
    resultado = a1;
    printf("PA: ");

    for (int i = 0; i<n; i++)
    {
        printf("%.3f ", a1 + r*i);
    }

    printf("\nPG: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.3f ", resultado);
        resultado *= r;  
    }
    printf("\n");

}