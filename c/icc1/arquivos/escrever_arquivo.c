#include<stdio.h> // Para ediçao de arquivos eh necessario o stdio.h
#include<stdlib.h>

int main(int argc, char ** argv)
{
	FILE *f_copy = fopen("arquivo.txt", "r");
	FILE *f_write = fopen(argv[1], "w");
	if (f_copy == NULL || f_write == NULL) exit(1);

	fprintf(stdout, "Copiando 'arquivo.txt' para '%s'. Conteudo:\n", argv[1]);

	char c;
	while (fscanf(f_copy, "%c", &c) != EOF)
	{
		fprintf(f_write, "%c", c);
		fprintf(stdout, "%c", c);
	}


	fclose(f_copy);
	fclose(f_write);
}

