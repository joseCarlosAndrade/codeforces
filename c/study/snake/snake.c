#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>

#define DEBUGGING 1

typedef enum Direction {UP, DOWN, LEFT, RIGHT} Direction;


typedef struct snake SnakeElement;

struct snake
{
	enum Direction element_direction;
	SnakeElement * nxt_element;
		
};


void append_element(SnakeElement **element, Direction direction, int * n_elements);
void print_all_elements(SnakeElement ** head, int n_elements);
char * return_direction(int d);

int main(void)
{
	//initscr();
	//timeout(-1);

	enum Direction current_direction = RIGHT;
	SnakeElement* head = (SnakeElement*)malloc(sizeof(SnakeElement));
	SnakeElement* tail = (SnakeElement*)malloc(sizeof(SnakeElement));

	// head{RIGHT, *tail} -> tail{RIGHT, NULL}
	head->element_direction = RIGHT;
	head->nxt_element = tail;

	tail->element_direction = RIGHT;
	tail->nxt_element = NULL;

	int n_elements = 2;

	
	char c;
	while (c != EOF)
	{
		fflush(stdin);
		
		sleep(1);
		//c = getchar();
		c = getch();
		switch (c)
		{
			case '\n':
				break;
			case 'w':
				current_direction = UP;
				break;

			case 's':
				current_direction = DOWN;
				break;

			case 'a':
				current_direction = LEFT;
				break;

			case 'd':
				current_direction = RIGHT;
				break;

			default:
				break;
		}

		append_element(&head, current_direction, &n_elements);
		
		/* TODO printar board, a cada direcao coloca @ na posicao. cabeça eh sempre &*/

		if (DEBUGGING) print_all_elements(&head, n_elements);
	}
}

/* Insere um novo elemento (head) na lista linkada que representa o cprpo da cobra */
void append_element(SnakeElement **element, Direction direction, int * n_elements)
{
	SnakeElement * new_element = (SnakeElement*) malloc(sizeof(SnakeElement));
	
	// data do novo elemento
	new_element->element_direction = direction;
	(*n_elements)++;

	// novo elemento aponta para o elemento antigo
	new_element->nxt_element = (*element);
	
	(*element) = new_element;
}

/* Debugging -> printa todos os elementos ativos*/
void print_all_elements(SnakeElement ** head, int n_elements)
{
	if ((*head)->nxt_element == NULL) 
	{
		if (DEBUGGING) printf("\n");
		return;
	}
	else
	{
		printf("| n: %d, d: %s |", --n_elements, return_direction((*head)->element_direction));
		print_all_elements(&(*head)->nxt_element, n_elements);
	}
}
	
char * return_direction(int d)
{
	switch (d)
	{
		case 0:
			return "UP";
			break;

		case 1:
			return "DOWN";
			break;

		case 2:
			return "LEFT";
			break;

		case 3:
			return "RIGHT";
			break;
		default:
			return "NULL";
	}
	
}	
/** Estrategia:
 *  criar cada celula (começar com 2)
 *  linked list: last_tail - tail - tail - tail - head
 *  
 *  parametros -> quantidade de elementos
 *
 *  operacoes: 
 *  	atualizar movimento (direcao, tocou_comida): adicionar um elemento em DIRECAO em relacao ao head + if (tocou_comida) pop em last_tail
 * 	
 */
