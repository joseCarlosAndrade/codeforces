#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

#define DEBUGGING 0
#define MAX_WRDS 1000000
#define MAX_PALAVRA_SIZE 100

void ler_palavra(char ** palavra);
int ler_texto(char *** texto);
void printar_texto(char *** texto, int n);
int filtrar_texto(char *** texto, char ** palavra_invasora, int qnt_palavras);
void realocar_texto(char *** texto, int qnt_palavras, int i);
void desalocar(char ** palavra, char *** texto, int n);

int main(void)
{
	char * palavra_invasora, **texto;

	ler_palavra(&palavra_invasora);
	int qnt_palavras = ler_texto(&texto);

	qnt_palavras = filtrar_texto(&texto, &palavra_invasora, qnt_palavras);
		
	printar_texto(&texto, qnt_palavras);
	desalocar(&palavra_invasora, &texto, qnt_palavras);
}

/* Le a palavra invasora. Padroniza todas as letras para minusculo. */
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
        
}

/* Aloca cada palavra separadamente num char** para cada string. */
int ler_texto(char *** texto)
{
	// Alocando strings
	*texto = (char**)calloc(MAX_WRDS, sizeof(char*));
	if ((*texto) == NULL) exit(1);


	for (int i = 0; i < MAX_WRDS ; i++)
	{
		(*texto)[i] = (char*) calloc(100, sizeof(char));
		if ((*texto)[i] == NULL) exit(1);

	}

	
	int i = 0;
	//int break_flag =0 ;
	for (;;)
	{
		char *c = (char*)calloc(100, sizeof(char));
			
	//	for (;;)
	//	{
	//		char f = getch()
	//	}

		if (scanf("%s\n", c) == EOF) break;
	//	if (break_flag) break;
		//(*texto)[i++] = c;
		if (i >= MAX_WRDS-1) 
		{
			(*texto) = (char**)realloc(*texto, (i+4)*sizeof(char*));
			if (*texto == NULL) exit(1);
		}
		strcpy((*texto)[i++], c);
		if (DEBUGGING) printf("\nTexto: %s\n", (*texto)[i-1]);
		
	}

	if (DEBUGGING) printf("\nn: %d\n", i);
        return i;
}

/* Filtra as palavras invasoras do texto e retorna a quantidade nova de palavras. */
int filtrar_texto(char *** texto, char ** palavra_invasora, int qnt_palavras)
{
	int n_invasoras = 0;
	
	// usando strcasecmp
	for ( int i = 0 ; i < qnt_palavras ; i++)
	{
		// caso diferente, retorna true (!=0)
		if(DEBUGGING) printf("\nComparando index %d. r: %d\n", i, strcasecmp(*palavra_invasora, (*texto)[i]));
		if ( strcasecmp(*palavra_invasora, (*texto)[i]) ) continue;
		else 
		{
			// caso sejam iguais: i->palavra invasora
			if (DEBUGGING) printf("\n palavra invasora encontrada em %d\n", i);
			realocar_texto(texto, qnt_palavras, i);
			n_invasoras++;
			i--;
		}
	}

	if (DEBUGGING) printf("\nn invasoras: %d\n", n_invasoras);
	printf("[Palavras invasoras: %d]\n\n", n_invasoras);
	return qnt_palavras - n_invasoras;
}

/* Realoca texto, removendo palavra da posicao i. 
 * texto, 7, 2
 * 2 <= 7-1(6) = 2 3 4 5
 * 0 1 2 3 4 5 6
 *     i:2	
 * 0 1 3 4 5 6
 * */
void realocar_texto(char *** texto, int qnt_palavras, int i)
{
	for (int j = i; j < qnt_palavras-1; j++)
	{
		//(*texto)[j] = (char*)calloc(100, sizeof(char));
		strcpy((*texto)[j], (*texto)[j+1]);
	}
	if (DEBUGGING) printf("\ndone\n");	
	//(*texto)[qnt_palavras-1] = (char*)calloc(100, sizeof(char));
}

/* Printa o texto na saida padrao */
void printar_texto(char *** texto, int n)
{
	for (int i = 0 ; i < n ; i ++)
	{
		printf("%s", (*texto)[i]);

		if (i == n-1) printf("\n");
		else printf(" ");
	}
}

/* Desaloca os ponteiros alocados dinamicamente. */
void desalocar(char ** palavra, char *** texto, int n)
{
	free(*palavra);
	if (DEBUGGING) printf("\nPalavra liberada.\n");	
	if ( n < MAX_WRDS) n = MAX_WRDS;

	for (int i = 0 ; i < n; i++)
	{
		free((*texto)[i]);
	}
}
