#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	// Leitura dos argumentos *argument count* e *argument value*
	if (argc !=2) 
	{
		printf("Uso correto: ./arquivo nome_do_arquivo.ext\n");
		exit(1);
	}
	FILE * file = fopen(argv[1], "r");

	// Erro ao abrir arquivo
	if (file == NULL) exit(1);

	
	char c;
	while(fscanf(file, "%c", &c) != EOF)
	{
		printf("%c", c);
	}

	// Fecha o arquivo aberto. As alteraçoes feitas até aqui sao armazenadas em um buffer, e so sao aplicadas ao arquivo quando este é fechado. Ou seja, quando se chama fclose(FILE* fp) ou quando o programa se encerra.  
	fclose(file);
}
