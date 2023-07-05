#include<stdio.h>
#include<stdlib.h>

void contar_caracteres(FILE * file);

int main(int argc, char ** argv)
{
	char nome_arquivo[100];
	scanf("%s", nome_arquivo);
	FILE * arquivo = fopen(nome_arquivo, "r");
	
	if (arquivo == NULL) exit(1);

	contar_caracteres(arquivo);
}

/* Le caractere por caractere ate encontrar EOF*/
void contar_caracteres(FILE * file)
{
	int contador = 0;
	while (!feof(file))
	{
		contador++;
		getc(file);
	}
	printf("%d\n", contador-1); // excluindo eof
}
