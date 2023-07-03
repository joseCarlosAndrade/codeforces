#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<strings.h>

int main(void)
{
	char * a = "texto";
	char * b = "teXtO";


	printf("%d %d", strcmp(a,b), strcasecmp(a, b));
	//printf("\nó: %i, o: %d, size: %d\n", 'ó', 'o', sizeof('ó'));

	//char a[10];
	//scanf("%s", a);
	//printf("%s - size: %ld\n", a, sizeof(a));
	
}


/* Comparar string mesmo que estejam caixa alta ou baixa */
int cmp_string(char *a, char *b)
{
	int i= 0;
	int offset = 'a' - 'A';
	char ca, cb;

	for (;;)
	{
		// if ur 
		break;
	}
	return i;
}
