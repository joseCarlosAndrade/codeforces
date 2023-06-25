#include<stdio.h>
#include<stdlib.h>

#define MAX_STR_SIZE 100
#define	DEBUGGING 0

void preenche_string(char **frase);
void printa_reverso(char** frase);

int main(void)
{

	char * frase;
	preenche_string(&frase);
	printa_reverso(&frase);
	free(frase);
}

void preenche_string(char **frase)
{
	// aloca 100 chars
	*frase = (char* )calloc (MAX_STR_SIZE+1, sizeof(char));
	if (*frase == NULL)  exit(1);

	// preenche string
	char c;
	int i = 0;
	for (;;)
	{
		if (i>=MAX_STR_SIZE) 
		{
			*frase = (char*)realloc(*frase, (i+1)*sizeof(char));
			if (*frase == NULL)  exit(1);
		}

		
		if (scanf("%c", &c) == EOF) break;
	
		(*frase)[i++] = c;
	}

	if (DEBUGGING) printf("\n%s\n", (*frase));
}

void printa_reverso(char** frase)
{
	int i = 0;
	for (;;)
	{	
		if ((*frase)[i++] != 0) continue;

		// quando encontra o elemento '\0', começa a printar de i-2 a 0. i-2 pois: i ja foi incrementado uma vez na linha anterior.
		// nao pode printar '\0'
		for (int j= i-2; j >= 0 ; j--)
		{
			putchar((*frase)[j]);

		}
		break;
	}
}
