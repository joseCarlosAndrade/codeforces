#ifndef ITEM_H
#define ITEM_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int data; // coordenadas sao indexes de matrizes, logo inteiros
typedef struct _maze_position maze_t;
typedef enum direction{UP, DOWN, LEFT, RIGHT} maze_direction;

// cria um item de posicao de labirinto
maze_t* create_item(int x, int y, maze_direction direction);

// modifica o valor da coordenada x
void set_x_value(maze_t*maze, data x);

// modifica o valor da coordenada y
void set_y_value(maze_t*maze, data y);

// modifica o valor da direcao do labirinto
void set_direction_value(maze_t*maze, maze_direction direction);

// retorna o valor da coordenada x
data get_x_value(maze_t*maze);

// retorna o valor da coordenada y
data get_y_value(maze_t*maze);  

// retorna o valor da direcao
data get_direction_value(maze_t*maze);

// apaga item para liberar memoria
void delete_item(maze_t**maze);

#endif