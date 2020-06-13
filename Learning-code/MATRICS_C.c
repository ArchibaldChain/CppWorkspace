#ifndef MATRICES
#define MATRICES_H

typedef struct matric
{
    double *cells;
    int rows;
    int cols;
    double *cells;

} MATRIC_T;
MATRIC_T *new_matrix(int row, int cols);
#endif