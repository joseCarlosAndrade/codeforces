#include<stdio.h>
#include<stdlib.h>

typedef struct dado {
	char * data;
	int comprimento;
} Dado;


void preencher_string(Dado * dado);
int mystrlen(char *);

int main(void)
{
	Dado dado_1;
	dado_1.data = (char*)calloc(20,sizeof(char));

	preencher_string(&dado_1);
	dado_1.comprimento = mystrlen(dado_1.data);

	printf("\nTexto lido: '%s', de tamanho: %d.\n", dado_1.data, dado_1.comprimento);
}

void preencher_string(Dado *dado)
{
	int i =0;

	char c;
	for (;;)
	{
		scanf("%c", &c);
		if (c == '\n' || c == '\r') break;
		(dado->data)[i++] = c;
	}
}

int mystrlen(char * texto)
{
	for (int i = 0 ; i < 100 ; i++) // limitei a 100 mesmo o maximo de char possivel para o texto ser 20
	{
		if (texto[i] == 0) return i;
	}
	return -1;
}
