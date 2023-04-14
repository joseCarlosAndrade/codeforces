#include<stdio.h>

int main(void)
{
    long int a, b, c, x;
    unsigned long int y;
    scanf("%ld %ld %ld %ld", &a, &b, &c, &x);
    y = (a * x * x);

    y = y + (b * x) + c;

    printf("%ld", y);
}