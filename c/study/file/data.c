#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definindo struct globalmente, pois nao ocupa espaço, nao aloca memoria
struct dados {
	int x;
	int y;
	char  nome[30];
};


int main(int argc , char ** argv)
{
	// Declarando variaveis do tipo struct dados. Aloca memoria
	struct dados ponto1, ponto2;

	ponto1.x = 10;
	ponto1.y = 15;
	strcpy(ponto1.nome, "jose");

	ponto2.x = 100;
	ponto2.y = 150;
	strcpy(ponto2.nome, "jose carlos andrade");

	if (argc != 2) exit(1);

	FILE * fp;

	if (!(fp = fopen(argv[1], "w"))) exit(1);

	fwrite(&ponto1, sizeof(struct dados), 1,fp);
	fwrite(&ponto2, sizeof(struct dados), 1,fp);


}
