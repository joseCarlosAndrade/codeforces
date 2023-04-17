#include<stdio.h>

int main(void)
{
    int numero = -1; 
    int maior_numero = 0;

    while (numero != 0) {
        if (numero > maior_numero) maior_numero = numero;

        scanf("%d", &numero);
    } 
    
    printf("Maior numero: %d\n", maior_numero);
    
}