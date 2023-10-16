#include"../include/stack.h"


void read_maze(int r, int c, int maze[r][c]);
void print_maze(int r, int c, int maze[r][c]);
int make_movement(int i, maze_direction last_direction, int ic, int jc, int r, int c, int maze[r][c], stack_maze * maze_stack);


int main(void) {
    int maze_rows, maze_columns;

    scanf("%d %d", &maze_rows, &maze_columns);

    int maze[maze_rows][maze_columns];

    read_maze(maze_rows, maze_columns,maze );

    stack_maze * maze_stack = create_stack();

    make_movement(0, DOWN, 0, 0, maze_rows, maze_columns, maze, maze_stack);
}

void read_maze(int r, int c, int maze[r][c]) {
    for (int i = 0 ; i < r; i++) {
        for (int j = 0 ; j < c; j++) { 
            scanf("%d", &maze[i][j]);
        }
    }
}

void print_maze(int r, int c, int maze[r][c]) {
    for (int i = 0 ; i < r; i++) {
        for (int j = 0 ; j < c; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// ordem: baixo, esquerda, cima, direita
int make_movement(int i, maze_direction last_direction, int ic, int jc, int r, int c, int maze[r][c],stack_maze * maze_stack) {
   
    printf("(%d, %d)\n", ic, jc);
    int ni, nj;
    if(maze[ic][jc] == 2) return 1;
    maze[ic][jc] = 0; // marcar celula como ja visitada	


    // baixo
    if ( ic+1 < r && last_direction != UP) {
        if ( maze[ic+1][jc] != 0) {
                push(maze_stack, create_item(ic+1, jc, DOWN));
            }
    }

    // esquerda 
    if ( jc-1 >= 0  && last_direction != RIGHT) {
        if ( maze[ic][jc-1] != 0) {
            push(maze_stack, create_item(ic, jc-1, LEFT));
        }
    }

    // cima 
    if ( ic-1 >= 0  && last_direction != DOWN ) {
        if ( maze[ic-1][jc] != 0) {
            push(maze_stack, create_item(ic-1, jc, UP));
        }
    }

    // direita
    if ( jc+1 < c  && last_direction != LEFT) {
        if ( maze[ic][jc+1] != 0) {
            push(maze_stack, create_item(ic, jc+1, RIGHT));
        }
    }
    
    if((i >= r*c -1 ) || (is_empty(maze_stack) && i > 0)) {
        printf("Saída não encontrada.\n"); return 0;
        }
    i++;

    maze_t * coord;
    pop(maze_stack, &coord);
    ni = get_x_value(coord);
    nj = get_y_value(coord);
    if (ni == ic && nj == jc) {
        printf("Saída não encontrada.\n"); return 0;
    }
    maze_direction new_direction = get_direction_value(coord);

    
    
    return make_movement(i, new_direction, ni, nj, r, c, maze,maze_stack);
}
