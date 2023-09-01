#include"matrix_operations.h"


Matrix2Df * create_matrix(unsigned int i, unsigned int j) {

    Matrix2Df * m = NULL;
    m = (Matrix2Df *) calloc (1, sizeof(Matrix2Df));
    assert(m != NULL);

    m->row = i;
    m->col = j;

    m->_base_ptr = (float**) calloc(i, sizeof(float*));
    assert (m->_base_ptr != NULL);

    for (int o = 0 ; o < i; o++) {
        (m->_base_ptr)[o] = (float*) calloc(j, sizeof(float));
        assert((m->_base_ptr[o]) != 0);
    }

    return m;
}

void close_matrix(Matrix2Df*m) {
    assert(m!=NULL);

    for (int o = 0 ; o < m->row; o++) {
        free(m->_base_ptr[o]);
    }

    free(m->_base_ptr);
    free(m);

}

int fill_matrix(Matrix2Df *m, float * vec) {
    assert(m!=NULL);
    int vec_size = m->row * m->col;
    int assert_size =0;

    for (int i = 0; i < m->row; i ++) {
        for (int j = 0; j < m->col; j++) {
            m->_base_ptr[i][j] = vec[i*m->col+j];
            assert_size ++;
        }
    }
    if (assert_size != vec_size) return -1;

    return 1;
}

int fill_matrix_from_file(Matrix2Df*m, char*f_name, int n) {
    assert(m != NULL && f_name != NULL);

    FILE *fp = NULL;
    
    fp = fopen(f_name, "r");
    assert(fp!=NULL);

    float * vec =NULL;
    vec = (float*) calloc(n, sizeof(float));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%f ", &vec[i]);
    }

    int r = fill_matrix(m,vec);
    free(vec);

    return r;
}

void print_matrix(Matrix2Df*m) {
    if (m == NULL) return;
 
    for (int i = 0; i < m->row; i++) {
        printf("\n");

        for (int j= 0; j < m->col; j++) {
            // printf("%f ", *(*(m->_base_ptr + i)+j));
            printf("%f ", m->_base_ptr[i][j]);
        }
    }
}

