#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printar_string(char * texto)
{
	printf("%s\n", texto);
}

void preencher_string(char * ptr, char * texto)
{
//	printar_string(texto);
	//ptr = texto; // illegal
	
	int i = 0;
	for (;;)
	{
		char c = texto[i];
		if (c == 0) break;
		putchar(c);
		ptr[i++] = c;
	}
}

int main(void)

{
	char * nome = (char *) calloc (20, sizeof(int));

	nome = "jose carlos\n";
	printf("%s", nome);

	printar_string(nome);

	char * texto = (char *) calloc(20, sizeof(int));
	preencher_string(texto, "Jose\n");
	
	printf("preenchido!\n");
	printar_string(texto);
}
