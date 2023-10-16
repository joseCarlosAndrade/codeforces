#include"../include/item.h"
#include"../include/stack.h"

#define STACK_SIZE 1000

struct _stack_maze {
    int top;
    maze_t* stack[STACK_SIZE];
};

stack_maze * create_stack() {
    stack_maze * stack = NULL;
    stack = (stack_maze*)calloc(1,sizeof(stack_maze));
    assert(stack != NULL);
    stack->top = -1;

    return stack;
}

int is_empty(stack_maze* stack) {
    assert(stack!=NULL);

    return (stack->top == -1 );
}

int is_full(stack_maze* stack) {
    assert(stack != NULL);

    return(stack->top == STACK_SIZE-1);
}

int push(stack_maze* stack, maze_t* pos) {
    assert(stack!= NULL);
    if (is_full(stack)) return 0; // stack sem espaço disponivel

    int new_index = (stack->top++ +1);
    stack->stack[new_index] = pos;

    // printf("last pushed stack: %d %d \n", get_x_value(pos), get_y_value(pos));
    return 1;
}

int pop(stack_maze* stack, maze_t** pos) {
    assert(stack != NULL && !is_empty(stack));
    if (is_empty(stack)) return 0;

    *pos = stack->stack[stack->top--];
    return 1;
}

int top(stack_maze* stack, maze_t** pos) {
    assert(stack != NULL);
    if (is_empty(stack)) return 0;

    *pos = stack->stack[stack->top];
    return 1;
}

void clean(stack_maze * stack) {
    assert ( stack != NULL) ;

    while(!is_empty(stack)) {
        delete_item(&(stack->stack[stack->top--]));
    }

}

void destroy(stack_maze ** stack) {
    assert(stack != NULL);

    clean(*stack);
    free(*stack);
    *stack=NULL;
}