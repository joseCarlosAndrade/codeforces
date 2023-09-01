#include"matrix_operations.h"


/* Main for tests*/
int main(void) {
    Matrix2Df *matrix = create_matrix(2, 3);
    // float buffer[6] = {1,2,3,4,5,6};
    // fill_matrix(matrix, buffer);
    fill_matrix_from_file(matrix, "input.txt", 6);
    print_matrix(matrix);

    close_matrix(matrix);
}