#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_SIZE 20

// debugging macro 
#define DEBUGGING 0


void aloca_banco(char *** banco, int n);
void adicionar_nome(int mode, char **nome, int tamanho, int pos, char ***banco);
void consultar_nome(char **nome, char ***banco, int * n_nomes);
int preencher_nome(char **nome);
void printar_banco(char *** banco, int n_nomes);
void liberar(char ***banco, int n);

int main(void)
{
	int n_nomes, n_consultas;
	scanf("%d", &n_nomes);

	char **banco_de_nomes;
	aloca_banco(&banco_de_nomes, n_nomes);
	
	// inserçao de nomes
	for (int i = 0; i < n_nomes; i++)
	{
		char *nome;
		//int tamanho_texto = preencher_nome(&nome);
		adicionar_nome(0, &nome, 0, i, &banco_de_nomes);
	}

	if (DEBUGGING) printf("\nIniciando consulta.\n");
	
	scanf("%d", &n_consultas);
	
	// consulta	
	for (int i = 0; i < n_consultas; i++)
	{
		char *consulta;

		preencher_nome(&consulta); // problema aqui.
		if (DEBUGGING) printf("\nPreenchimento de consulta '%s' feito\n", consulta);
		consultar_nome(&consulta, &banco_de_nomes, &n_nomes);
	}

	printar_banco(&banco_de_nomes, n_nomes);

	liberar(&banco_de_nomes, n_nomes);
}



/* Aloca o banco de nomes por referencia a variavel na funcao main
 */
void aloca_banco(char *** banco, int n)
{
	if (DEBUGGING) printf("\nAlocando banco de %d nomes: \n", n);
	*banco = (char**) calloc ( n, sizeof(char*));

	if (*banco == NULL) exit(1);

	for ( int i = 0; i < n; i++)
	{
		*((*banco)+i) = (char*) calloc (MAX_STR_SIZE+1, sizeof(char));
		if (*((*banco)+i) == NULL) exit(1); // erro ao alocar chars
	}

	if (DEBUGGING) printf("\n%d Nomes alocados para banco de nomes.\n", n);
}

/* Preenche o nome alocando dinamicamente um ponteiro char*
 * */
int preencher_nome(char **nome)
{
	if (DEBUGGING) printf("\nDigite o nome a ser inserido:\n");

	*nome = (char*) calloc(MAX_STR_SIZE+1, sizeof(char));
	if (DEBUGGING) printf("\nNome antes do preenchimento: %s\n", *nome);

	int i = 0;

	for (;;)
	{	
		fflush(stdin);
		char c = getchar();
		//scanf(" %c", &c);
		fflush(stdin);
		if (c =='#') break;
		if (c == '\n' || c == '\r') continue;
		
		//if ((c >= 65 && c <=90) || ( c >= 97 && c <= 122) || (c == 32))
		{
			if (i >=MAX_STR_SIZE ) // string maior que 20, necessario realocar
			{
				(*nome) = (char*)realloc (*nome, (i+2)*sizeof(char));
			}
			(*nome)[i++] = c;
			if (DEBUGGING) printf("\nCaractere adicionado: %c\n", c);
		}
	}
	(*nome)[i] = 0;

	if (DEBUGGING) printf("\nPalavra adicionada! %s\n", (*nome));
	return i;
}

/* Adiciona o nome *nome na posicao int pos no banco de nomes **banco
 */
void adicionar_nome(int mode, char **nome, int tamanho, int pos, char ***banco)
{

	if (mode) // mode 1 -> nome eh passado por parametro
	{
		(*banco)[pos] = *nome;
		if (DEBUGGING) printf("\nParametro: %s\n", *nome);
	}
	else // mode 0 -> nome eh lido neste escopo
	{
		int i = 0;

		for (;;)
		{	
			fflush(stdin);
			char c = getchar();
			fflush(stdin);
			//scanf(" %c", &c);
			if (c =='#') break;
			if (c == '\n' || c == '\r') continue;
			//if ((c >= 65 && c <=90) || ( c >= 97 && c <= 122) || (c == 32))
			{
				if (i >=MAX_STR_SIZE ) // string maior que 20, necessario realocar
				{
					(*banco)[pos] = (char*)realloc ((*banco)[pos], (i+2)*sizeof(char));
				}
				(*banco)[pos][i++] = c;
			}
			}
	
		(*banco)[pos][i] = 0;
	}

	//int i = 0;

	if (DEBUGGING)
	{
		printf("\nNome adicionado: %s\n", (*banco)[pos]);
	}

}

/* Consulta a existencia de *nome em **banco_de_nomes. Caso encontre, apenas retorna, nao fazendo nada. 
 * Caso nao encontre, realoca **banco para armazenar mais um char* e insere *nome la.
 * */
void consultar_nome(char **nome, char ***banco, int * n_nomes )
{
	if (DEBUGGING) printf("\n Consultando nome '%s'.\n", *nome);
	for (int i = 0; i < *n_nomes; i++)
	{	
		if (strcmp(*nome, (*banco)[i]) == 0) 
		{
			if (DEBUGGING) printf("\nNome encontrado.");
			return;
		}
	}
	if (DEBUGGING) printf("\nNome '%s' nao encontrado. Adicionando no banco de nomes.\n", *nome);

	// Caso nao encontre o nome no banco, adiciona-o
	// realoca banco de nomes
	*banco = (char **)realloc( *banco, sizeof(char*) * ++(*n_nomes));
	
	if (*banco == NULL) exit(1);
	
	// adiciona nome
	adicionar_nome(1, nome , strlen(*nome),(*n_nomes)-1, banco);
}

/* Libera toda a memoria alocada para o banco de nomes 
 * */
void liberar(char ***banco, int n)
{
	for (int i = 0; i < n; i++)
	{
		
		free((*banco)[i]);
		if (DEBUGGING) printf("\nLinha %d do banco de nomes liberada.\n", i);
	}
	free(*banco);
}

/* Printa o banco de nomes linha a linha
 * */
void printar_banco(char *** banco, int n_nomes)
{
	if (DEBUGGING) printf("\nBanco de Nomes: \n");
	for (int i = 0; i < n_nomes; i++)
	{
		printf("%s\n", (*banco)[i]);
	}
}

/* char ** banco_de_nomes :
 * 	| char * nome_1 |
 * 	| char * nome_2 |
 * 	| char * nome_3 |
 * 	| char * nome_4 |
 * 	| char * nome_5 |
 *
 * */
