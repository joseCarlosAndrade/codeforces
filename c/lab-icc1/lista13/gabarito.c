#include<stdio.h>
#include<stdlib.h>

int calcular_nota(FILE * aluno, FILE * gabarito);

int main(int argc, char**argv)
{
	char aluno_s[20];
	char gabarito_s[20];

	scanf("%s %s", aluno_s, gabarito_s);

	FILE *aluno = fopen(aluno_s, "r"); 
	FILE *gabarito = fopen(gabarito_s, "r");

	if (aluno == NULL || gabarito == NULL) exit(1);

	int nota = calcular_nota(aluno, gabarito);
	
	printf("%d ", nota);
	if (nota < 3) printf("REPROVADO\n");
	else if (nota <5) printf("RECUPERACAO\n");
	else printf("APROVADO\n");
}

/* Calcular nota a partir das respostas do aluno e do gabarito. */
int calcular_nota(FILE * aluno, FILE * gabarito)
{
	int nota = 0;

	for (int i = 0 ; i < 10 ; i ++ )
	{
		if (getc(aluno) == getc(gabarito)) nota++;
	}

	return nota;
}
