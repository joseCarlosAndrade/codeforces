#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void consultar_salarios(FILE * banco, long salario);

int main(int argc, char ** argv)
{
	char nome_banco[100];
	long salario;
	scanf("%s", nome_banco);
	scanf("%li", &salario);

	FILE * banco_de_dados = fopen(nome_banco, "r");
	//if (banco_de_dados == NULL) exit(1);
	if (!banco_de_dados) 
	{
		printf("Este banco de dados nao existe.\n");
		exit(1);
	}

	consultar_salarios(banco_de_dados, salario);

	fclose(banco_de_dados);
}

/* Printa em stdout as informaçoes dos funcionarios que recebem mais que long salario */
void consultar_salarios(FILE * banco, long salario)
{
	int qnt_funcionario = getc(banco)-'0'; // Transformando char em inteiro por char - '0' (por conta da tabela ascii)
	getc(banco); // le proximo \n

	for (int i = 0; i < qnt_funcionario ; i++)
	{
		char * info_funcionario = (char*)calloc(200, sizeof(char));
		for ( int j = 0; j < 4; j ++)
		{
			char *buffer = (char*)calloc(200, sizeof(char));
			fscanf(banco, "%s", buffer);
			strcat(info_funcionario, buffer);
			strcat(info_funcionario, "\n");

			if ( j == 3) // Leitura do salario
			{
				if (atol(buffer) > salario)
				fprintf(stdout, "%s", info_funcionario);
				
				free(buffer);
			}
			
		}
		free (info_funcionario);
	}
}
