#include<stdio.h>

int main(void){
    int idade;
    float altura;
    double peso;
    char nome[50];
    char preferencia_musical;

    printf("Digite seu nome: ");
    scanf("%s", nome);
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura em metros: ");
    scanf("%f", &altura);

    printf("Digite seu peso em kg: ");
    scanf("%lf", &peso);

    printf("Qual é sua preferência musical? (R para Rock, P para Pop, J para Jazz, etc.) ");
    scanf(" %c", &preferencia_musical);

    int idade_dias = idade * 365;

    printf("\n%s, você tem %d anos, %.2f metros de altura, %.21f kg ", nome, idade, altura, peso);
    printf("e prefere música %c.\n", preferencia_musical);
    printf("Isso significa que você já viveu aproximadamente %d dias.\n", idade_dias);
}