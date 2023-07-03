#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PALAVRA_SIZE 20
#define INITIAL_TXT_SIZE 100
#define DEBUGGING 1

void ler_palavra(char** palavra);
void ler_texto(char ** texto, char ** original);
void filtrar_palavra_invasora(char ** texto, char ** original, char **palavra, int *);
void printar_texto(char **texto);


int main(void)
{
	char *palavra_invasora;
	char *texto, *original;
	int free_text = 1;

	ler_palavra(&palavra_invasora);
	ler_texto(&texto, &original);
	filtrar_palavra_invasora(&texto, &original, &palavra_invasora, &free_text);
	printar_texto(&texto);

	free(palavra_invasora);
	if (free_text) {
		free(texto);
		free(original);
	}
}

void ler_palavra(char** palavra)
{
	if ((*palavra = (char*)calloc(MAX_PALAVRA_SIZE+1, sizeof(char))) == NULL) exit(1);

	char c;
	int i = 0;
	int offset = 'a'-'A';
	for (;;)
	{
		scanf("%c", &c);
		if (c == '\n' || c == '\r') break;
		
		// padronizar para lowercas
		if (c <= 'Z' && c >= 'A') c += offset;
		(*palavra)[i++] = c;
	}

	if (DEBUGGING) printf("\nPalavra invasora lida: %s\n", *palavra);
}

void ler_texto(char ** texto, char**original)
{
	if ((*texto = (char*)calloc(INITIAL_TXT_SIZE+1, sizeof(char))) == NULL) exit(1);
	if ((*original = (char*)calloc(INITIAL_TXT_SIZE+1, sizeof(char))) == NULL) exit(1);
	
	char c;
	int i = 0;
	int offset = 'a'-'A';
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n' || c == '\r') continue;
		if (i == INITIAL_TXT_SIZE) // precisa realocar
		{
			*texto = (char*)realloc(*texto, (i+3)*sizeof(char));
			*original = (char*)realloc(*original, (i+3)*sizeof(char));
			(*original)[i+1] = 0;
			(*texto)[i+1] = 0;
		}
		
		// padroniza para lowercase
		(*original)[i] = c;
		if (c <= 'Z' && c >= 'A') c += offset;
		(*texto)[i++] = c;
	}

	if (DEBUGGING) printf("\nTexto lido: %s\n", *texto);
}

/* Cicla palavra por palavra, comparando com palavra invasora. */
void filtrar_palavra_invasora(char ** texto, char ** original, char **palavra, int * free_text)
{
	int contador_de_palavras =0;
	int i = 0;
	int tamanho_palavra = strlen(*palavra);
	char c;
	int j = 0;
		
	if (DEBUGGING) printf("\nProcurando por '%s' de tamanho %d.\n", *palavra, tamanho_palavra);

	for (;;)
	{
	
		if ((c = (*texto)[i]) == 0) break;
		
		char d;
		int equal = 0;
		j = i;
		if (((*texto)[i+tamanho_palavra] == 0 || (*texto)[i+tamanho_palavra] == ' '))
		{
			if (DEBUGGING) printf("\ncondicao 0 ou espaco em indice %d\n", i);
			int eee = 0;
			if (i == 0) eee = 1;
			else if ((*texto)[i-1] == ' ') eee = 1;
			if (eee){
		equal = 1;
		if (DEBUGGING) printf("\nPotencial palavra encontrada no index: %d\n", i);
		for (j = i; j < i+tamanho_palavra; j++)
			{
					
				d = (*texto)[j];
				char current = (*palavra)[j-i];
				
				if (d != current) equal = 0;

				if ( d == ' ' || d == 0) 
				{
					i++;
					break;
				}
					
			}
		}}
		else {
			i++;
		}
		if(DEBUGGING) printf("\ni: %d, j: %d\n", i, j);
		if (equal)
		{
			if (DEBUGGING) printf("\nPalavra invasora encontrada em: i = %d\n", i);
			contador_de_palavras++;
			int o = i;		
			if (o ==0) *free_text = 0;
			for (;;)
			{
				char f = (*texto)[o+tamanho_palavra];
				char ori = (*original)[o+tamanho_palavra];

				(*original)[o-1] = ori;
				(*texto)[(o++)-1] = f;
				if (DEBUGGING && (f==0)) printf("\nFim adicionado: %d\n", f);

				if (f == 0) break;
			}
			if (DEBUGGING) printf("\nTexto atual: %s\n", *texto);
		
		}
		else {i = j+1;}

		
	}
	printf("[Palavras invasoras: %d]\n", contador_de_palavras);
	
}
/* Tamanho de palavra_invasora = 4 (exemplo)
 * x x x x ' ' c c c ' ' c c  0
 * 0 1 2 3  4  5 6 7  8  9 10 11
 * i = 0 -> j =0 ate j = 3;
 * i = j+1
 * */

void printar_texto(char **texto)
{
	if (DEBUGGING) printf("\nPrintando texto final:\n\n");
	int i = 0;
	for (;;)
	{
		if ((*texto)[i] == 0) break;
		if (DEBUGGING) printf("\nC: %d : ",(*texto)[i]);
		printf("%c", (*texto)[i++]);
	}
	printf("\n");
}
/** Ler palavra invasora: padronizar para lowercase
 *  Ler texto de tamanho variavel: padronizar para lowercase (INCLUIR ESPAÇOS)
 *  Ciclar pelo texto lido palavra por palavra -> char until ' ' or '\0'
 *  strcmp == 0 -> palavra presente, incrementar contador_de_palavras ++
 *  	duas alternativas:
 *  		sobrescrevre texto apagando a palavra
 *
 *  		substituir palavra por um caractere que nao ser usado no texto , e ignorá-lo ao printar o texto
 *
 * OBS: realocar TEXTO caso o numero de caracteres exceda INITIAL_TXT_SIZE
 */
