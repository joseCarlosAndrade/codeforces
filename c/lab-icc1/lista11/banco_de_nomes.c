#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NOME_SIZE 20

int preenche_nome(char ** ptr_nome);
void adicionar_nome(char ** nome, int pos, int tamanho, char*** banco_de_nomes);
void consulta_nome(char ** nome, int tamanho, int * n_nomes, char *** banco_de_nomes);
void printar_banco_nomes(char *** banco, int n_nomes);
void liberar(char *** banco, int n_nomes);

int main(void)
{
	int n_nomes, n_consultas;
	int *ptr_n_nomes = &n_nomes;

	scanf("%d", &n_nomes);
	// cria um vetor de ponteiros, o qual cada elemento apontara para um nome
	char ** banco_de_nomes = (char **)calloc(n_nomes, sizeof(char*));
	
	for (int i = 0; i < n_nomes; i++)
	{
		char * nome;
		int tamanho_texto = preenche_nome(&nome);
		//printf("nome: %s\n", nome);
		adicionar_nome(&nome, i, tamanho_texto, &banco_de_nomes);
	}
	
	scanf("%d", &n_consultas);

	for (int i = 0; i < n_consultas ; i++)
	{
		char * consulta;
		int tamanho_consulta = preenche_nome(&consulta);

		consulta_nome(&consulta, tamanho_consulta, ptr_n_nomes, &banco_de_nomes);

		printf("\nNome a  ser consultado:\n");
		int j = 0;
		for(;;)
		{
			char c = consulta[j++];
			if (c == 0) break;
			putchar(c);
		}
	}


	printf("\nConsultas finalizadas. \n");
	printar_banco_nomes(&banco_de_nomes, n_nomes);

	liberar(&banco_de_nomes, n_nomes);		
}

void printar_banco_nomes(char *** banco, int n_nomes)
{
	int contador;
	char c;

	printf("\nPrintando banco de nomes. Numero de nomes: %d\n", n_nomes);
	for (int i = 0; i < n_nomes; i++)
	{
		//printf("%s\n", banco[i]);
		contador = 0;
		for (;;) 
		{
			c = *banco[i][contador];
			//printf("%c" , c);
			if( c == 0 ) break;
			putchar(c);
			contador++;
		}
		putchar('\n');
	}
}

void consulta_nome(char ** nome, int tamanho, int * n_nomes, char *** banco_de_nomes)
{
	// loop de 0 a n_nomes -> se nome esta contido, entao retorna 
	for (int i = 0 ; i < *n_nomes ; i++)
	{
		if (!strcmp(*nome, *banco_de_nomes[i]) ) return;
	}

	// caso nome nao estao contido, aumentar banco de dados e incluir nome 
	printf("\nAdicionando novo nome. Nome: \n");
	int i = 0;
	for(;;)
	{
		char c = *nome[i++];
		if (c == 0) break;
		putchar(c);
	}

	(*n_nomes)++;
	*banco_de_nomes = (char**)realloc(*banco_de_nomes, *n_nomes*sizeof(char));
	
	adicionar_nome(nome, (*n_nomes)-1, tamanho, banco_de_nomes);
	// realloc em banco de dados para n_nomes
	// adicoinar nome em banco_de_dados na posiaçao n_nomes
}

int preenche_nome(char ** ptr_nome)
{
	*ptr_nome = (char*) calloc(MAX_NOME_SIZE+1, sizeof(char));
	
	// erro ao alocar memoria
	if (*ptr_nome == NULL) exit(1); 

	int contador = 0;
	
	for(;;)
	{
		char c;
		scanf(" %c", &c);
		if (c == '#') break;
		
		if (contador > 20) 
		{
			*ptr_nome = (char*) realloc(*ptr_nome, (contador+1)*sizeof(char));
			if (*ptr_nome == NULL ) exit(1);
			
		}
		printf("\nAccessing index %d \n", contador);
		*ptr_nome[contador] = c;
		printf("\nchar apos ser preenchido: %c ", *ptr_nome[contador]);
		contador++;
	}

	return contador; // retorna tamanho do texto digitado
}


void adicionar_nome(char ** nome, int pos, int tamanho, char*** banco_de_nomes)
{
	// alocar char * de N caracteres na posicao pos em banco de nomes
	*banco_de_nomes[pos] = (char*) calloc(tamanho+1, sizeof(char));
	if (*banco_de_nomes[pos] == NULL ) exit(1);
	
	int i = 0;
	for (;;)
	{
		char c = *nome[i];
		if (c == 0) break; // nome chegou ao fim
		putchar(c);
		*banco_de_nomes[pos][i++] = c;

	}
	
	//banco_de_nomes[pos] = nome; // nao sei se essa linha vai funcionar
	//for (size_t i = 0; i < strlen(nome); i++)
	//{
	//	printf("\nprintando: %c ", nome[i]);
	//}
	// PROBLEMA TA AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
	//printf("\ntestando nome : %c \n", *(nome+1));
	//printf("testando linha %d : %s\n", pos, banco_de_nomes[pos]);
}

void liberar(char *** banco, int n_nomes)
{
	for (int i = 0; i < n_nomes; i++)
	{
		free(*banco[i]);
	}
	free(*banco);
}
