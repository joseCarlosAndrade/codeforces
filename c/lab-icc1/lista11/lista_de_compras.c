#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LISTA_SIZE 1000 // 1000 compras
#define MAX_STR_SIZE 100 // 100 caracteres por compra
#define DEBUGGING_LVL 0 // level de debugging (0 para sumprimir todos os outputs indesejaveis para run codes)

void alocar_lista_de_compras(char***lista_de_compras);
void preencher_lista(char *** lista_de_compras, int * n_compras);
void gerar_vetor_indices(char *** lista_de_compras, int** ordem_de_amostragem, int n_compras);
void printar_lista_de_compras(char ***lista_de_compras, int ** ordem_de_amostragem, int n_compras);
void trocar_posicao(char ** pos_1, char ** pos_2);
void liberar(char ***lista_de_compras, int n_compras);


int main(void)
{

	char ** lista_de_compras;
	int * ordem_de_amostragem;
	int n_compras;

	alocar_lista_de_compras(&lista_de_compras);
	preencher_lista(&lista_de_compras, &n_compras); // n_compras precisa ser passado por referencia aqui para ser alterado
	gerar_vetor_indices(&lista_de_compras, &ordem_de_amostragem, n_compras);
	printar_lista_de_compras(&lista_de_compras, &ordem_de_amostragem, n_compras);
	
	liberar(&lista_de_compras, n_compras);
}

/* Aloca a lista de compras , como um char** que aponta para elementos char *, tudo por referencia. 
 * Em caso de erro ao alocar memoria, sai do programa. */
void alocar_lista_de_compras(char***lista_de_compras)
{
	*lista_de_compras = (char**)calloc(MAX_LISTA_SIZE, sizeof(char*));
	if (*lista_de_compras == NULL) exit(1);

	for (int i = 0; i < MAX_LISTA_SIZE; i++)
	{
		(*lista_de_compras)[i] = (char*) calloc ( MAX_STR_SIZE+1, sizeof(char));
		if ((*lista_de_compras)[i] == NULL) exit(1);
	}
}

/* Preenche a lista de compras com char* lidos pelo stdin ate o usuario digitar 'sair'. */
void preencher_lista(char *** lista_de_compras, int * n_compras)
{	
	int i =0;
	for (;;)
	{	// preciso: ler string ate \n (espaços ou caracteres especiais nao aparecerao)
		// caso a string lida seja 'sair' -> interromper a execucao do loop e NAO inserir ela na lista de compras
		//fflush(stdin);
		//char c = getchar();
		char string_temporaria[MAX_STR_SIZE+1];
		scanf("%s", string_temporaria);
	
		if (strcmp("sair", string_temporaria) == 0) break; // sair do loop antes de adicionar 'sair' a lista
		
	
		if (i>MAX_LISTA_SIZE) 
		{
			if(DEBUGGING_LVL == 1) printf("\nLimite de preenchimento atingido. Leitura de strings falhou.\n");
			exit(1);
		}
		
		strcpy((*lista_de_compras)[i++], string_temporaria);
		if (DEBUGGING_LVL == 1) printf("\nString armazenada: %s\n", (*lista_de_compras)[i-1]);
		}

	*n_compras = i;
}

/* Aloca o vetor ordem de amostragem de acordo com a ordem alfabetica das compras e preenche-o */
void gerar_vetor_indices(char *** lista_de_compras, int** ordem_de_amostragem, int n_compras)
{
	*ordem_de_amostragem = (int *) calloc(n_compras, sizeof(int));

	/* Bubble sort para strings - strcmp(str[i], str[i+1]) 
	 * 0 -> leave
	 * < 0 -> leave
	 * > 0 -> trocar posicao
	 * */
	for (int i = n_compras ; i > 1 ; i--)
	{
		for (int j = 0; j < i-1; j++)
		{
			if (strcmp( (*lista_de_compras)[j], (*lista_de_compras)[j+1]  )> 0) trocar_posicao(&((*lista_de_compras)[j]), &((*lista_de_compras)[j+1]));
		}
	}
	
	// first test 0 1 2 3 .. n_compras-1
	//for (int i = 0; i < n_compras ; i++)
	//{
	//	(*ordem_de_amostragem)[i] = i;
	//}
}

void trocar_posicao(char ** pos_1, char ** pos_2)
{
	char * temp = *pos_1;
	*pos_1 = *pos_2;
	*pos_2 = temp;

	if (DEBUGGING_LVL == 1) printf("\nSwap monitoramento: pos_1: %s pos_2 %s temp %s.\n", *pos_1, *pos_2, temp);
}

void printar_lista_de_compras(char ***lista_de_compras, int ** ordem_de_amostragem, int n_compras)
{
	if (DEBUGGING_LVL == 1) printf("\nPrintando lista de compras:\n");
	for (int i = 0; i < n_compras ; i++)
	{
		//printf("%d) %s\n",i+1, (*lista_de_compras)[(*ordem_de_amostragem)[i]]  );
		printf("%d) %s\n",i+1, (*lista_de_compras)[i]  );
	}
}

void liberar(char ***lista_de_compras, int n_compras)
{
	if (DEBUGGING_LVL == 1) printf("\nLiberando memoria alocada.\n");
	for (int i = 0; i < n_compras ; i++)
	{
		free((*lista_de_compras)[i]);
	}

	free(*lista_de_compras);
}

/** Planejamento do codigo:
 * Alocar uma lista de compra dinamicamente com tamanho inicial MAX_LISTA_SIZE
 * cada alemento dessa lista é um char* de MAX_STR_SIZE
 *
 * Preencher elementos, a cada \n recebido adicionar esse elemento a lista_de_compras[i]
 * Quando o usuario digitar sair -> strcmp("sair", texto) == 0 -> interromper a execucao do preenchimento
 *
 * Realocar string caso necessario (evitar isso com MAX_STR_SIZE bem grande)
 *
 *
 * Organizar um vetor int* de indices para gerar a ordem de saida da lista (ordem alfabetica)
 * printar a lista conforme os elementos desse vetor
 */
