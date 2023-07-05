#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

void ler_arquivo(FILE*arquivo, char ***palavras_distintas, int * n_palavras);
void printar_palavras(char ** palavras_distintas, int n_palavras);
int comparar_palavra(char * , char **palavras_distintas, int n_palavras);
void adicionar_palavra(char * palavra, char ***palavras_distintas, int* n_palavras);
void liberar_memoria(char *** palavras_distintas,  int n_palavras);

int main(int argc, char ** argv)
{
	char nome_arquivo[10];
	char **palavras_distintas = (char**)calloc(0, sizeof(char*));
	int n_palavras = 0;
	scanf("%s", nome_arquivo);

	FILE * arquivo = fopen(nome_arquivo, "r");

	if (arquivo == NULL ) exit(1);

	ler_arquivo(arquivo, &palavras_distintas, &n_palavras);
	printar_palavras(palavras_distintas, n_palavras);
}

/* Le arquivo e compara palavras para adiciona-las a palavras_distintas. */
void ler_arquivo(FILE*arquivo, char ***palavras_distintas, int * n_palavras)
{	
	while (!feof(arquivo))
	{
		char buffer[30];
		fscanf(arquivo, "%s", buffer);
		if (comparar_palavra(buffer, *palavras_distintas, *n_palavras)) 
		{
			// Palavra nova
			adicionar_palavra(buffer, palavras_distintas, n_palavras);
		}
	}
}

/* Compara palavra com todas as ja armazenadas no banco de palavras. Caso seja distinta, retorna 1. */
int comparar_palavra(char * palavra, char **palavras_distintas, int n_palavras)
{
	// Eh necessario armazenar o endereco de palavra em algum outro ponteiro, permitindo o loop a seguir
	char *palavra_temp = palavra;

	// Cicla pelo array palavra atraves do seu endereco ate *palavra == 0 (Caractere nulo)	
	for(; *palavra ; palavra++)
	{
		// Lowercase
		if (*palavra  <= 'Z' && *palavra >= 'A') *palavra += 'a'-'A';
		// filtra ultimos caracteres para eliminar possiveis '; , . etc'
		else if ((*palavra < 'a' || *palavra > 'z') && *palavra!= '-') *palavra = 0;
	}

	// filtra ultimos caracteres para eliminar possiveis '; , . etc'
	//char ultimo_char = *(--palavra);
	
	for ( int i = 0; i < n_palavras; i++)
	{
		// caso encontre alguma palavra igual, retorna false
		if (strcasecmp(palavra_temp, palavras_distintas[i]) == 0) return 0;
	}

	// retorna true por padrao
	
	return 1;
}

/* Adiciona palavra nova para */
void adicionar_palavra(char * palavra, char ***palavras_distintas, int* n_palavras)
{
	*palavras_distintas = (char**)realloc(*palavras_distintas, ((*n_palavras)+1)*sizeof(char*));
	(*palavras_distintas)[*n_palavras] = (char*)calloc(strlen(palavra)+1, sizeof(char));
	if (*palavras_distintas == NULL || (*palavras_distintas)[*n_palavras] == NULL ) exit(1);
	

	strcpy((*palavras_distintas)[*n_palavras], palavra);

	(*n_palavras)++;
}

/* Printa as palavras passadas em palavras_distintas. */
void printar_palavras(char ** palavras_distintas, int n_palavras)
{
	printf("O texto possui %d palavras distintas\n", n_palavras);

	for (int i = 0 ; i < n_palavras; i++)
	{
		printf("%s\n", palavras_distintas[i]);
	}
}

void liberar_memoria(char *** palavras_distintas,  int n_palavras)
{
	for (int i = 0 ; i < n_palavras; i++)
	{
		free((*palavras_distintas)[i]);
	}
	free(*palavras_distintas);
}
