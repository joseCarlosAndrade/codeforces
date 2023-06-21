#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE_STR 20

void printa(char *ptr);
char ** aloca_banco_de_nomes(int n); 
char ** adicionar_nome(int posicao);
int main(void)
{
	int n_nomes;
	scanf("%d", &n_nomes);

	char ** banco_de_nomes = aloca_banco_de_nomes(n);
}

char ** aloca_banco_de_nomes(int n)
{
	char ** banco =  (char**)calloc(n, sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		banco[i] = (char*) calloc(MAX_SIZE_STR, sizeof(char));
	}
}

char ** adicionar_nome(int posicao)
{

}
