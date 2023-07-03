#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

int main(void)
{
	char palavra[20];
	char *texto_final = (char*) calloc (1, sizeof(char));
	char *palavra_temporaria = (char*) calloc(1, sizeof(char));
	
	int i = 0, contador_palavras = 0;

	fgets(palavra, 30, stdin);
	if((strlen(palavra)>0) &&(palavra[strlen(palavra)-1] == '\n')) palavra[strlen(palavra)-1] = '\0';

	for(;;)
	{
		char c;
		
		//fflush(stdin);
		c = getchar();
		// uma palavra lida
		if (c == '\n' ||  c == '\r' || c == ' ' || c == EOF)
		{
			
			if (strcasecmp(palavra_temporaria, palavra) != 0)
			{
				// nao eh palavra invasora
				// palavra0
				// palavra00
				palavra_temporaria = (char*)realloc(palavra_temporaria, strlen(palavra_temporaria)+2);
				
				if (c != EOF)
					palavra_temporaria[strlen(palavra_temporaria)] = c;
				else
				{
					palavra_temporaria[strlen(palavra_temporaria)] = '\n';
				}
				// exemplo de texto
				// 0123456789012345 16
				int novo_tamanho = strlen(texto_final)+strlen(palavra_temporaria) +1;

				texto_final = (char*)realloc(texto_final, novo_tamanho);
				strcat(texto_final, palavra_temporaria);
				
				free(palavra_temporaria);
				
				palavra_temporaria = (char*) calloc(1, sizeof(char));
				
				i = 0;
			}
			else 
			{	

				free(palavra_temporaria);
				
				palavra_temporaria = (char*) calloc(1, sizeof(char));
				contador_palavras++;
				i=0;
				
			}
			if (c == EOF) break;
			continue;
		}
		
		// fim do texto
		else if( c == EOF) break;
		
		palavra_temporaria[i++] = c;
		palavra_temporaria = (char*)realloc(palavra_temporaria,(i+1)*sizeof(char));
		

	}
	printf("[Palavras invasoras: %d]\n\n%s", contador_palavras,texto_final);
	
	free(texto_final);
	free(palavra_temporaria);
}
