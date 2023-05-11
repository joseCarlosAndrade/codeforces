#include<stdio.h>

int main(void)
{
    int palavras = 1, caracteres = 0, linhas = 1;
    
    fflush(stdin);
    char a;
    char last_char;

    while (1){
        last_char = a;
        a = getchar();
        // char a ;
        // scanf("%c", &a);    
        
        if (a == 10 || a == 13 || a=='\r\n') {linhas++; if (last_char != 10 && last_char != 13) palavras++; continue;}
        else if (a == ' ') {palavras++; continue;}
        else if (feof(stdin)) break;
            caracteres++;
    
    }

    printf("Caracteres: %d\nPalavras: %d\nLinhas: %d\n", caracteres, palavras, linhas);


}