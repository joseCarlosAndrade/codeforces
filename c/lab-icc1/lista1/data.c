#include<stdio.h>

int main() {
    unsigned int yy;
    char dd, mm;

    scanf("%*[a-z]%3x%2hhd%2hho", &yy,&mm,&dd);
    printf("Data: %.2d/%.2d/%.4d\n", dd, mm, yy);
}