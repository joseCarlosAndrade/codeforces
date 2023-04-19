#include<stdio.h>

int main(void)
{
    int numero;
    scanf("%d", &numero);

    char a = numero & 255;
    numero = numero >> 8;

    char b = numero & 255;
    numero = numero >> 8;

    char c = numero & 255;
    numero = numero >> 8;

    char d = numero & 255;
    // numero >> 8;
    printf("%c%c%c%c\n", d, c, b, a);
}