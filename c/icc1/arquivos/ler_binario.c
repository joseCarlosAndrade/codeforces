#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 3) 
	{
		printf("Uso: ./ler_binario source target\n");
		exit(1);
	}

	FILE * reader = fopen (argv[1], "rb");
	FILE * writer = fopen(argv[2], "wb");

	if (reader == NULL || writer == NULL) exit(1);

	char c;

	while(!feof(reader))
	{
		c = getc(reader);

		if (c != EOF) fprintf(writer, "%c", c);
	}
	
	fclose(reader);
	fclose(writer);
}
