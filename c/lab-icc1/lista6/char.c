#include<stdio.h>

int main(void)
{
    char a;
    while (1)
    {   
        if (a<0) break;;
        a = getchar();

        if ((a >= 65 && a <= 90 ) || (a >= 97 && a <= 122)) continue;
        printf("\nchar: %c int: %d", a, a);
    }
}