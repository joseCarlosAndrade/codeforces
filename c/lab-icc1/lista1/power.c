#include<stdio.h>
#include<math.h>

int main() {
    int numero;
    scanf("%d", &numero);

    double power = pow(numero, 10);
    float square = sqrt(numero);

    // printf("Numero: %d\n\t %.2e\n\t %.2f\n", numero, power, square);
    printf("Numero: %d\n"
           "\t%.2e\n"
           "\t%.2f\n", numero, power, square);
}