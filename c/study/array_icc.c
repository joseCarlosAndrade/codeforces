// recebe um valr inteiro e transofmra esse valor em seu respectivo valor binario
// 

#include<stdio.h>

int main(void)
{
    int decimal;
    int binario[10];

    scanf("%d", &decimal);
    int i = 0;
    // int div;
    while (1)
    {
        binario[i] = decimal % 2;
        // div = decimal / 2;
        // if (div == 0) break;

        
        if (decimal == 0) break;
        decimal = decimal / 2;
        i++;
    }
    // printf(" i: %d \n", i);
    for (int o= 0; o < i; o++)
    {
        printf("%d", binario[i-o-1]);
    }
}