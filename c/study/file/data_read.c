#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dados { 
        int x;
        int y;
        char  nome[30];
};

int main(int argc, char ** argv)
{
	struct dados ponto1, ponto2;
	if (argc != 2) exit(1);

	FILE *fp;
	if (!(fp = fopen(argv[1], "r"))) exit(1);

	fread(&ponto1, sizeof(struct dados), 1, fp);
	fread(&ponto2, sizeof(struct dados), 1, fp);

	printf("%d %d %s\n", ponto1.x, ponto1.y, ponto1.nome);
	printf("%d %d %s\n", ponto2.x, ponto2.y, ponto2.nome);
}
