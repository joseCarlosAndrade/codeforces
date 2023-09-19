#include"../include/item.h"

// definindo o tipo de dado usado para localizacao no labirinto 2d
struct _maze_position {
    data x, y;
    maze_direction last_direction;
};


maze_t* create_item(int x, int y, maze_direction direction) {
    maze_t* maze = NULL;
    maze = (maze_t*) calloc(1, sizeof(maze_t));
    assert(maze !=NULL);
    maze->x = x;
    maze->y =  y;
    maze->last_direction = direction;
    return maze;
}

void set_x_value(maze_t*maze, data x) {
    assert(maze != NULL);
    maze->x = x;
}

void set_y_value(maze_t*maze, data y) {
    assert(maze != NULL);
    maze->y = y;
}

void set_direction_value(maze_t*maze, maze_direction direction) {
    assert(maze!=NULL);
    maze->last_direction = direction;
}

// retorna o valor da coordenada x
data get_x_value(maze_t*maze) {
    assert(maze != NULL);
    return maze->x;
}

// retorna o valor da coordenada y
data get_y_value(maze_t*maze){
    assert(maze != NULL);
    return maze->y;
}

data get_direction_value(maze_t*maze) {
    assert(maze!=NULL) ;
    return maze->last_direction;
}

// apaga item par liberar memoria
void delete_item(maze_t**maze) {
    assert (*maze != NULL);
    free(*maze);
    *maze = NULL;
}