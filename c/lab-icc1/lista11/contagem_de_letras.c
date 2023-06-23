#include<stdio.h>
#include<stdlib.h>

#define MAX_STR_SIZE 4096
#define DEBUGGING_LVL 0

void le_string(char ** texto);
void analisa_frequencia(char **texto);

int main(void)
{
	char * texto;
	le_string(&texto);
	analisa_frequencia(&texto);

	free(texto); // libera a memoria alocada
}

/* Aloca o vetor de char dinamicamente, com tamanho de 4096 + 1 (para '\0')
 * Exemplo de entrada: "Hello World!"
 * String final: "helloworld"
 * */
void le_string(char ** texto)
{
	if ((*texto = (char*)calloc(MAX_STR_SIZE+1, sizeof(char))) == NULL) exit(1);
	char c;
	int i = 0; // leitura da string com filtro -> recebe somente letras e transforma todas em minuscula
	while (scanf(" %c", &c) != EOF)
	{	
		if ((c >= 'A' && c <= 'Z') || ( c >= 'a' && c<= 'z') ) // somente letras
		{
			if (c <= 'Z') c += 32; // lowercase 
			(*texto)[i++] = c;

		}
	}
	if (DEBUGGING_LVL == 1) printf("\nString lida: %s\n", *texto);
}

/* Analisa a frequencia de cada caractere na string passada alocanda dinamicamente
 * */
void analisa_frequencia(char **texto)
{
	int * frequencia = (int*) calloc(26, sizeof(int)); // inicializa array frequencia com todos os elementos sendo 0
	int i = 0;
	for (;;)
	{
		char c = (*texto)[i++];
		if (c == 0) break; // fim da string
		frequencia[c-'a']++; // abbce -> [ 1 2 1 0 1 ];

	}
	
	for ( i = 0; i < 26; i++)
	{
		int f = frequencia[i];
		if (f)
		{
			printf("%c: %d\n", i+'a', f); // saida -> a: 1 \n b: 2 \n c: 1 \n e: 1 \n
		}
	}
}
