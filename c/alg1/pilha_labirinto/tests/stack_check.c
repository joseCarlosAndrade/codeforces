#include"../include/stack.h"

int main(void) {
    stack_maze * stack =create_stack();

    push(stack, create_item(0, 0,  UP));
    push(stack, create_item(3, 9, DOWN));
    push(stack, create_item(3, 9, LEFT));
    push(stack, create_item(3, 10, RIGHT));
    
    maze_t * item;
    pop(stack, &item);
    int x = get_x_value(item);
    int y = get_y_value(item);

    printf("pop: %d %d\n", x, y);

    while(!is_empty(stack)) {
        maze_t*it;
        pop(stack, &it);
        int x = get_x_value(it);
        int y = get_y_value(it);
        printf("pop: %d %d\n", x, y);
    }
}