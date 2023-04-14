#include<stdio.h>

int main(void)
{
    int binario, resto, base = 1;
    int decimal = 0;

    scanf("%d", &binario);

    while (binario > 0)
    {
        resto = binario % 10;  
        decimal = decimal + resto * base;
        base = base *2;
        binario = binario / 10;     
    }

    printf("%d", decimal);
}