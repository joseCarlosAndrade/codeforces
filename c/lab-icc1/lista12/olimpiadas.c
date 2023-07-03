#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pais {
	char sigla[3+1];
	int ouro;
	int prata;
	int bronze;

	char *medalhas_ascii;
} Pais;

void swap(Pais** pais1, Pais** pais2);
void alocar_paises(int n, Pais *** paises);
void preencher_paises(int n, Pais *** paises);
void ordenar_paises(int n, Pais *** paises);
void mostrar_paises(int n, Pais *** paises);
void liberar_memoria(int n, Pais *** paises);

int main(void)
{
	Pais ** paises;
	int n;
	scanf("%d", &n);
	alocar_paises(n, &paises);
	preencher_paises(n, &paises);
	ordenar_paises(n, &paises);
	mostrar_paises(n, &paises);
	liberar_memoria(n, &paises);

}

/* Trocar posicao dos paises pais1 e pais2. */
void swap(Pais** pais1, Pais** pais2)
{
	Pais *aux = *pais1;
	*pais1 = *pais2;
	*pais2 = aux;

}

/* Preencher banco de paises com informaçoes do usuario. */
void preencher_paises(int n, Pais *** paises)
{
	for (int i = 0; i < n ; i ++)
	{
		char sigla[3+1];
		int ouro, prata, bronze;
		scanf(" %s %d %d %d", sigla, &ouro, &prata, &bronze);

		(*paises)[i]->ouro = ouro;
		(*paises)[i]->prata = prata;
		(*paises)[i]->bronze = bronze;
		strcpy((*paises)[i]->sigla, sigla);
		
		// inserindo medalhas em ascii
		// eh necessario adicionar 1 a todos para que nao tenha ocorrencia do caractere '\0' (0)
		(*paises)[i]->medalhas_ascii = (char*)calloc(4,sizeof(char));
		((*paises)[i]->medalhas_ascii)[0] = 1+ouro;
		((*paises)[i]->medalhas_ascii)[1] = 1+prata;
		((*paises)[i]->medalhas_ascii)[2] = 1+bronze;
	}
}	

/* Alocar vetor de Pais. */
void alocar_paises(int n, Pais *** paises)
{
	*paises = (Pais**) calloc(n, sizeof(Pais*));
	if (*paises == NULL) exit(1);

	for (int i =0 ; i < n; i++)
	{
		(*paises)[i] = (Pais*)calloc(1, sizeof(Pais));
		if ((*paises)[i] == NULL) exit(1);
	}
}

/* Ordena paises por ordem das medalhas. 
 *
 * 0 1 2 3
 *  
 * */
void ordenar_paises(int n, Pais *** paises)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = n-2; j>=0 ; j--)
		{
			if ( strcmp( (*paises)[j]->medalhas_ascii , (*paises)[j+1]->medalhas_ascii) < 0 ) 
				swap(&((*paises)[j]), &((*paises)[j+1])); // TODO
			
		}
	}
}

/* Mostra os paises formatados. */
void mostrar_paises(int n, Pais *** paises)
{	
	for (int i = 0; i < n ; i ++)
	{
		printf("%s %d %d %d\n", 
				(*paises)[i]->sigla,
				(*paises)[i]->ouro,
				(*paises)[i]->prata,
				(*paises)[i]->bronze);
	}
}

void liberar_memoria(int n, Pais *** paises)
{
	for (int i = 0; i < n ; i ++)
	{
		free((*paises)[i]);
	}
	free(*paises);
}

/* pais | ouro - prata - bronze -> base a A: 64
 *      | 1 A+1 | 2 A+2| 5 A+5 | BCF        
 *      |       |      |       |
 *      |       |      |       |
 *      |       |      |       |
 *      |       |      |       |
 *      |       |      |       |
 *
 *
 * RESULTADOS DE STRCMP
 * bcf bcg : -1
 *
 * printf("%d %d %d %d %d\n",
 * 		strcmp("BCF", "BCG"), 
 *		strcmp("BCF", "ACF"), 
 *		strcmp("CCF", "BCF"), 
 *		strcmp("BDF", "BCF"),
 *		strcmp("CAA", "BZZ"));
 *
 *  Output: -1 1 1 1
 * >0 primeiro elemento na frente
 * <0 segundo elemento na frente
 * */
