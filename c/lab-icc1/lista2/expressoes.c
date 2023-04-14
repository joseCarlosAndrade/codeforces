#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("A > B: %d\n", a>b);
    printf("A eh par: %d\n", a%2==0);
    printf("B NAO eh multiplo de 3: %d\n", b%3!=0);
    printf("A > B e A eh par: %d\n", a>b && a%2==0);
    printf("A > B ou A eh par: %d\n", a>b || a%2==0);

}