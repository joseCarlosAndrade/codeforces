#include<stdio.h>

int main(void)
{
    int numero = 0; 
    int maior_numero = 0;

    do {
        if (numero > maior_numero) maior_numero = numero;

        scanf("%d", &numero);
    } while (numero != 0);
    
    printf("Maior numero: %d\n", maior_numero);
    
}