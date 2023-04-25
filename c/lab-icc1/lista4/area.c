#include<stdio.h>

int main(void)
{
    char forma;
    float a, b;
    scanf("%c", &forma);


    switch (forma)
    {
    case 'q':
        scanf("%f", &a);
        printf("%.2f\n", a*a);
        break;
    case 'r':
        scanf("%f %f", &a, &b);
        printf("%.2f\n", a*b);
        break;
    case 't':
        scanf("%f %f", &a, &b);
        printf("%.2f\n", a*b/2);
        break;
    case 'c':
        scanf("%f", &a);
        printf("%.2f\n", 3.14*a*a);
        break;

    
    default:
        break;
    }
}