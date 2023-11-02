#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DESCR 51

typedef struct tempo {
	int hh;
	int mm;
	int ss;
	int total_segundos;
} horario;

// estrutura de um proceso
typedef struct _processo {
	char nome[MAX_DESCR];
	horario tempo;
	int prioridade;
} celula;

void inserir_prioridade(celula * lista_prioridade, int prioridade, char tempo[9], char descricao[MAX_DESCR], int prioridade_index);
void inserir_tempo(celula * lista_tempo,  int prioridade, char tempo[9], char descricao[MAX_DESCR], int tempo_index);
void remover_tempo (celula * ordenacao_tempo, int prioridade, int index);
void remover_prioridade(celula * ordenacao_prioridade, int tempo, int index);

int main(void) {
	celula ordenacao_tempo[101];
	celula ordenacao_prioridade[101];
	int tempo_index = -1;
	int prioridade_index = -1;

	for (;;) {
		char command[7];
		scanf(" %s", command);

		if( !strcmp(command,"add")) {
			
			int prioridade;
			char tempo[9], descricao[MAX_DESCR];
			
			scanf("%d %s %s", &prioridade, tempo, descricao);
			inserir_tempo(ordenacao_tempo, prioridade, tempo, descricao, tempo_index);
			tempo_index++;

			inserir_prioridade(ordenacao_prioridade, prioridade, tempo, descricao, prioridade_index);
			prioridade_index++;
					
		}
		else if (!strcmp(command, "exec")) {
			char op[3];
			scanf(" %s", op);
			
			if (!strcmp(op, "-p")) {
				remover_tempo(ordenacao_tempo, ordenacao_prioridade[prioridade_index].prioridade, tempo_index);
				prioridade_index--;
				tempo_index--;

			}
			else if (!strcmp(op, "-t")) {
				remover_prioridade(ordenacao_prioridade, ordenacao_tempo[tempo_index].tempo.total_segundos, prioridade_index);
				tempo_index --;
				prioridade_index--;
			}
		}
		else if (!strcmp(command, "next")) {
		}
		else if (!strcmp(command, "change")) {
		}
		else if (!strcmp(command, "print")) {
			printf("a");
			for(int i = 0; i <= tempo_index; i ++) {
				
				printf("nome: %s, prioridade: %d, tempo: %.2d:%.2d:%.2d:\n",ordenacao_tempo[i].nome, ordenacao_tempo[i].prioridade,
						ordenacao_tempo[i].tempo.hh,
						ordenacao_tempo[i].tempo.mm,
						ordenacao_tempo[i].tempo.ss); 
			} 
		}
		else if (!strcmp(command, "quit")) {
			break;
		}
		
	}
}


void inserir_prioridade(celula * lista_prioridade, int prioridade, char tempo[9], char descricao[MAX_DESCR], int prioridade_index) {
	// busca para saber index do novo elemento
	int inicio = 0;
	int fim = prioridade_index;
	
	while(inicio < fim) {
		int mid = (fim + inicio)/2;
		if (lista_prioridade[mid].prioridade > prioridade ) {
			 fim = mid-1;
		}
		else if(lista_prioridade[mid].prioridade < prioridade) {
			inicio = mid+1;
		}
		
	}


	if (fim < 0 ) fim = 0;
	else if (lista_prioridade[fim].prioridade < prioridade ) {
		fim++;
	}

	// reajuste da lista + insercao no index fim
	
	for (int i = prioridade_index; i >= fim; i--) {
		lista_prioridade[i+1] = lista_prioridade[i];
	}

	lista_prioridade[fim].prioridade = prioridade;
	
	int h = (tempo[0]-'0')*10 + (tempo[1]-'0');
	int m = (tempo[3]-'0')*10 + (tempo[4]-'0');
	int s = (tempo[6]-'0')*10 + (tempo[7]-'0');
	horario new_tempo = {h, m, s, 3600*h + 60*m + s};

	lista_prioridade[fim].tempo = new_tempo; 
	strcpy(lista_prioridade[fim].nome, descricao);

}

void inserir_tempo(celula * lista_tempo,  int prioridade, char tempo[9], char descricao[MAX_DESCR], int tempo_index) {
	// busca para saber index do novo elemento
	int inicio = 0;
	int fim = tempo_index;
	
	int h = (tempo[0]-'0')*10 + (tempo[1]-'0');
	int m = (tempo[3]-'0')*10 + (tempo[4]-'0');
	int s = (tempo[6]-'0')*10 + (tempo[7]-'0');
	int tempo_total = 3600*h+60*m+s;
	
	while(inicio < fim) {
		int mid = (fim + inicio)/2;
		if (lista_tempo[mid].tempo.total_segundos < tempo_total ) {
			 fim = mid-1;
		}
		else if(lista_tempo[mid].tempo.total_segundos > tempo_total) {
			inicio = mid+1;
		}
		
	}


	if (fim < 0 ) fim = 0;
	else if (lista_tempo[fim].tempo.total_segundos > tempo_total) {
		fim++;
	}

	// reajuste da lista + insercao no index fim
	
	for (int i = tempo_index; i >= fim; i--) {
		lista_tempo[i+1] = lista_tempo[i];
	}

	lista_tempo[fim].prioridade = prioridade;
	
	//int h = (tempo[0]-'0')*10 + (tempo[1]-'0');
	//int m = (tempo[3]-'0')*10 + (tempo[4]-'0');
	//int s = (tempo[6]-'0')*10 + (tempo[7]-'0');
	horario new_tempo = {h, m, s, 3600*h + 60*m + s};

	lista_tempo[fim].tempo = new_tempo; 
	strcpy(lista_tempo[fim].nome, descricao);

}

void remover_tempo (celula * ordenacao_tempo, int prioridade, int index) {
	int i = 0;
	for(; i < index; i ++) {
		if(ordenacao_tempo[i].prioridade == prioridade) break;
	}

	for ( int j = i; j < index; j++) {
		ordenacao_tempo[j] = ordenacao_tempo[j+1];
	}
}

void remover_prioridade(celula * ordenacao_prioridade, int tempo, int index) {

	int i = 0;
	for(; i < index; i ++) {
		if(ordenacao_prioridade[i].tempo.total_segundos == tempo) break;
	}

	for ( int j = i; j < index; j++) {
		ordenacao_prioridade[j] = ordenacao_prioridade[j+1];
	}
}

/*
 *
 * addadd 2 
 * exec
 * next
 * change
 * print 
 * quit*/
