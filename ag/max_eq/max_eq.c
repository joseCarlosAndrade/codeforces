#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
 * AG para achar o amximo da funcao abaixo:
x,	x < 10

20-x	x>=10

1) Iniciar populacao inicial

2) Avaliar fitness da populacao

3) Selecionar baseado na avaliacao da populaçao

4) Crossover

5) Mutação

Definicao de populacao:
vetor populacao float [MAX_POPULATION]

*/

#define MAX_POPULATION 10

typedef float populacao[MAX_POPULATION];

float funcao(float x);
float aleatorizar(int min, int max);
float avaliar_fitness(populacao popul_atual); 
void fazer_crossover(float melhor_individuo, populacao * populacao_atual);
void fazer_mutacao(populacao * populacao_atual);

int main(void)
{
	// randomizacao
	long ltime = time(NULL);
	int stime = (unsigned) ltime/2;
	srand(stime);

	float ultimo_melhor_individuo = -10000;
	// gerar populacao inicial
	
	populacao popul;
	int iteracao = 0;

	for (int i = 0; i< MAX_POPULATION; i ++)
	{
		popul[i] = aleatorizar(0, 200)-100; // cada individuo vale -100 a 100 (aleatorio)
		//printf("VALOR %d : %f\n", i, popul[i]);
	}

	printf("Populaçao inicial: \n");
	for (int i = 0; i <MAX_POPULATION; i++) printf("%f ", popul[i]);
	printf("\n");

	while(1)
	{
		// avaliacao do fitness
		float melhor_individuo = avaliar_fitness(popul);
	
		// condicao de parada (para nao rodar infinitamente) - caso nao haja mudanca significativa
		if ((melhor_individuo-ultimo_melhor_individuo)*(melhor_individuo-ultimo_melhor_individuo) < 0.00001) break;
		//if (((melhor_individuo-10)*(melhor_individuo-10)) < 0.01) break;
		ultimo_melhor_individuo = melhor_individuo;

		// crossover (gerar novos individuos baseados a partir do melhor)
		fazer_crossover(melhor_individuo, &popul);

		// mutacao (mutar certa parte dos individuos de acordo com certa probabilidade)
		fazer_mutacao(&popul);
		
		printf("\n\nPopulaçao atual (iteracao %d): \n", ++iteracao);
		for (int i = 0; i <MAX_POPULATION; i++) printf("%f ", popul[i]);
		
		printf("\n");
		
		if (iteracao > 100) break;
	}
	
}

/* Funcao */
float funcao(float x)
{
	if (x < 10) return x;

	return 20-x;
}

/* Retornar um numero aleatorio entre min e max (extremos nao inclusos) */
float aleatorizar(int min, int max)
{
	//srand(time(NULL));
	//srand(17);
	return ((rand() % (max-min) ) + min);
}

/* Avalia o fitness da populacao para retornar o melhor individuo */
float avaliar_fitness(populacao populacao_atual)
{
	float melhor_individuo = funcao(populacao_atual[0]);

	for (int i = 1 ; i < MAX_POPULATION; i ++)
	{
		if ( funcao(populacao_atual[i]) > funcao(melhor_individuo) ) melhor_individuo = populacao_atual[i];	
	}

	printf("melhor individuo: %f funcao: %f", melhor_individuo, funcao(melhor_individuo));
	return melhor_individuo;
}

/* Cruza o melhor individuo com toda a populacao, gerando filhos para a nova populacao */
void fazer_crossover(float melhor_individuo, populacao * populacao_atual)
{
	for (int i = 0; i < MAX_POPULATION; i++)
	{
		(*populacao_atual)[i] = (melhor_individuo + (*populacao_atual)[i])/2 ; 
	}
}

/* Faz mutacao em todos os individuos*/
void fazer_mutacao(populacao * populacao_atual)
{
	float fator_mutacao = 0.8;

	for (int i = 0; i < MAX_POPULATION; i++)
	{
		(*populacao_atual)[i] = (*populacao_atual)[i] + (fator_mutacao * (aleatorizar(0,2) -1 ));
	}
}
