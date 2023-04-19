#include<stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);


    printf("A and B: %d\n", a & b);
    printf("A or B: %d\n", a | b);
    printf("A xor B: %d\n", a ^ b);
    printf("not A: %d\n", ~a);
    printf("A right shift 2: %d\n", a>>2);
    printf("B left shift 1: %d\n", b<<1);
}