#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_SIZE 100
#define DEBUGGING 0

typedef struct Evento 
{
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
	int segundo;
	char evento[100];
} Evento;

void alocar_agenda(int n, Evento ***agenda);
void preencher_agendas(int n, Evento ***agenda);
void mostrar_agendas(int n, Evento ***agenda);
void liberar_memoria(int n, Evento ***agenda);

int main(void)
{
	int n;
	Evento ** agenda;
	scanf("%d", &n);
	
	// Aloca n structs Evento
	alocar_agenda(n, &agenda);
	preencher_agendas(n, &agenda);
	mostrar_agendas(n, &agenda);


}

/* Aloca n agendas em um ponteiro Evento** de ponteiros Evento. */
void alocar_agenda(int n, Evento ***agenda)
{

	*agenda = (Evento**)calloc(n, sizeof(Evento*));
	if (agenda == NULL) exit(1);
	
	for (int i = 0; i < n ; i++)
	{
		(*agenda)[i] = (Evento*)calloc(1, sizeof(Evento));
		if ((*agenda)[i] == NULL) exit(1);
	}
	if (DEBUGGING) printf("\nAlocado.");
}

/* Preenche n agendas passadas. */
void preencher_agendas(int n, Evento ***agenda)
{
	for (int i = 0; i < n; i++ )
	{
		int dia, mes, ano, hora, minuto, segundo;
		char evento[100];

		scanf("%d %d %d %d %d %d", &dia, &mes, &ano, &hora, &minuto, &segundo);
		scanf(" %[^\n]s", evento);
		//fflush(stdin);
		//fgets(evento, 100, stdin);

		//if((strlen(evento)>0) &&(evento[strlen(evento)-1] == '\n')) evento[strlen(evento)-1] = '\0';

		(*agenda)[i]->dia = dia;
		(*agenda)[i]->mes = mes;
		(*agenda)[i]->ano = ano;
		(*agenda)[i]->hora = hora;
		(*agenda)[i]->minuto = minuto;
		(*agenda)[i]->segundo = segundo;
		//(*agenda)[i]->evento = evento;
		strcpy((*agenda)[i]->evento, evento);
	}

}

/* Mostra as n agendas. */
void mostrar_agendas(int n, Evento ***agenda)
{
	for (int i = 0; i < n ; i++)
	{
	

		printf("%.2d/%.2d/%.4d - %.2d:%.2d:%.2d\n%s\n", 
		(*agenda)[i]->dia,
		(*agenda)[i]->mes,
		(*agenda)[i]->ano,
		(*agenda)[i]->hora,
		(*agenda)[i]->minuto,
		(*agenda)[i]->segundo,
		(*agenda)[i]->evento );
	}
}

/* Libera memoria alocada. */
void liberar_memoria(int n, Evento ***agenda)
{
	for (int i =0 ; i < n; i++)
	{
		free((*agenda)[i]);
	}
	free(*agenda);
}
