#ifndef STACK_H
#define STACK_H

#include"item.h"

typedef struct _stack_maze stack_maze;

stack_maze * create_stack();

int is_empty(stack_maze* stack);

int is_full(stack_maze* stack);

int push(stack_maze* stack, maze_t* pos);

int pop(stack_maze* stack, maze_t** pos);

int top(stack_maze* stack, maze_t** pos);

void clean(stack_maze * stack);

void destroy(stack_maze ** stack);

#endif