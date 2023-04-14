#include <stdio.h>

int main(void)
{
    int valor, cem, cinquenta, vinte, dez, cinco, dois, um, resto;
    scanf("%d", &valor);

    cem = valor / 100;
    resto = valor%100;

    cinquenta = resto / 50;
    resto = resto%50;
    
    vinte = resto / 20;
    resto = resto%20;
    
    dez = resto / 10;
    resto = resto%10;

    cinco = resto / 5;
    resto = resto%5;

    dois = resto / 2;
    um = resto%2;

    printf("%d nota(s) de R$ %d\n", cem, 100);
    printf("%d nota(s) de R$ %d\n", cinquenta, 50);
    printf("%d nota(s) de R$ %d\n", vinte, 20);
    printf("%d nota(s) de R$ %d\n", dez, 10);
    printf("%d nota(s) de R$ %d\n", cinco, 5);
    printf("%d nota(s) de R$ %d\n", dois, 2);
    printf("%d moeda(s) de R$ %d\n", um, 1);

}