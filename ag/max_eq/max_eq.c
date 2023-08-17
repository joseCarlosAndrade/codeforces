#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

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

condicao de parada:
armazenar o ultimo melhor individuo
armazenar a variavel de carga.
carga aumenta conforma a mudança entre geracoes diminui

eq:

carga = 1/x, em que x = abs(ultimo_melhor_individuo - melhor_individuo)

se carga > MAX_CARGA: break

*/

#define MAX_POPULATION 10
#define MAX_CARGA 1000000 // define o quao preciso os resultados serao (em troca da velocidade de convergencia)

typedef float populacao[MAX_POPULATION];

float funcao(float x);
float aleatorizar(float min, float max);
float avaliar_fitness(populacao popul_atual); 
void fazer_crossover(float melhor_individuo, populacao * populacao_atual);
void fazer_mutacao(populacao * populacao_atual);

int main(void)
{
	// randomizacao
	long ltime = time(NULL);
	int stime = (unsigned) ltime/2;
	srand(stime);

	float ultimo_melhor_individuo = -100;
	double carga = 0;
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
		
		double input_funcao_carga = fabs(melhor_individuo-ultimo_melhor_individuo);
		if (input_funcao_carga < 0.1)
		{
			
			carga += (double)1/input_funcao_carga;
			printf("\n\nCarga atualizada: %lf %lf %lf \n", carga, input_funcao_carga,fabs(melhor_individuo-ultimo_melhor_individuo));
			if (carga > MAX_CARGA) 
			{
				printf("\n\nAlgoritmo alcancou seu final com melhor individuo: %f\n", melhor_individuo);
				break;
			}
		}


		// condicao de parada (para nao rodar infinitamente) - caso nao haja mudanca significativa
		//if ((melhor_individuo-ultimo_melhor_individuo)*(melhor_individuo-ultimo_melhor_individuo) < 0.00001) break;
		//if (((melhor_individuo-10)*(melhor_individuo-10)) < 0.01) break;
		ultimo_melhor_individuo = melhor_individuo;

		// crossover (gerar novos individuos baseados a partir do melhor)
		fazer_crossover(melhor_individuo, &popul);

		// mutacao (mutar certa parte dos individuos de acordo com certa probabilidade)
		fazer_mutacao(&popul);
		
		printf("\n\nPopulaçao atual (iteracao %d): \n", ++iteracao);
		for (int i = 0; i <MAX_POPULATION; i++) printf("%f ", popul[i]);
		
		printf("\n");
		
		//if (iteracao > 100) break;
	}
	
}

/* Funcao */
float funcao(float x)
{
	if (x < 10) return x;

	return 20-x;
}

/* Retornar um numero aleatorio entre min e max (extremos nao inclusos) */
float aleatorizar(float min, float max)
{
	//srand(time(NULL));
	//srand(17);
	return (float)((rand() % (int) (max-min) ) + min);
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
	float fator_mutacao = 0.5;

	for (int i = 0; i < MAX_POPULATION; i++)
	{
		(*populacao_atual)[i] = (*populacao_atual)[i] + (fator_mutacao * ( (float)aleatorizar(0,200) -100 )/100.0);
	}
}
