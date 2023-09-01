#ifndef _OPERATION_H
#define _OPERATION_H

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Basic math operations structures */

struct _float_2d_matrix {
    float ** _base_ptr;
    unsigned int row, col;
};

/* 

_base_ptr** ->
    base0* -> a00 a01 a02 .. a0{column}
    base1* -> ..
    ...
    base{row}* -> ..

*/

typedef struct _float_2d_matrix Matrix2Df;

Matrix2Df * create_matrix(unsigned int i, unsigned int j);

void close_matrix(Matrix2Df*m);

int fill_matrix(Matrix2Df *m, float * vec);

int fill_matrix_from_file(Matrix2Df*m, char*f_name, int n);

void print_matrix(Matrix2Df*m);

#endif