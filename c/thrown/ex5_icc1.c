#include<stdio.h>

int main(void)

{
    long int a, b, resultado, paridade = 0;
    printf("Digite os dois números a serem comparados.\n");
    scanf("%ld %ld", &a, &b);

    paridade = a%2 + b%2;
    // 0 ou 2 caso ambos sejam par / ambos sejam impar
    // 1 caso tenham paridade diferente
    if (paridade == 1)
    {
        resultado = a+b;
        printf("O %ldº número é ímpar, o outro é par.\n", (1*(a%2) + 2*(b%2)));
        printf("Nesse caso o resultado da soma é: %ld.\n", resultado);
    } else if (paridade == 0){
        resultado = a*b;
        printf("Ambos os números são pares. Logo o resultado da multiplicação é: %ld.\n", resultado);
        
    } else {
        resultado = a*b;
        printf("Ambos os número são ímpares. Logo o resultado da multiplicação é: %ld.\n", resultado);
    }
}