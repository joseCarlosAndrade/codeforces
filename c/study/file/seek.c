#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
	if (argc != 2){
		printf("Uso correto: ./seek nome_arquivo");
		exit(1);
	}

	FILE *fp;

	if (!(fp = fopen(argv[1], "rb"))) exit(1);

	int pos;
	scanf("%d", &pos);

	if(fseek(fp, pos, SEEK_SET)) exit(1);
	

	printf("%p\n%c\n%p\n", fp, getc(fp), fp);
	printf("%d\n", *fp);

	fclose(fp);


	char * texto = "este eh um texto";
	for( ; *texto; texto++) putchar(*texto);
}


