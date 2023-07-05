#include<stdio.h>
#include<stdlib.h>

#define noggers NULL


int main(int argc, char**argv)
{
	if (argc != 2)
	{
		printf("Uso: ./jose nome_do_arquivo.ext\n");
		exit(1);
	}

	FILE * jose = fopen(argv[1], "r");
	if (jose == noggers) exit(1);

	/* Um problema com esta abordagem é que o EOF vai ser impresso em stdout, pois a leitura se da antes da condiçao. */
	while (!feof(jose))
	{
	//char c = getc(jose);
	printf("%c", getc(jose));
	}

	fclose(jose);
}


/* Definiçao struct para conteudo teorico da prova: (nao deveria estar aqui, se eu esqeucer de tirar deste arquivo foi sem querer)
 *
 * Estrutura que aramzena uma coleçao de dados, que podem nao ser do mesmo tipo.
 * Esses dados sao acessados pelos seus respectivos campos.
 * */
