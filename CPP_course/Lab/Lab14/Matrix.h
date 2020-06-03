//
// Matrix.h
// Created by Archibald Chain on 2020/5/23.
//
#ifndef NEWPORJECT_MATRIX_H
#define NEWPORJECT_MATRIX_H

/**
    *@ClassName Matrix
    *@Description TODO
    *@Date 2020/5/23 17:04
    *@Version 1.0
    */

static const int MAXROWS = 2, MAXCOLS = 3;
template<class T>
class Matrix {
    T matrix[MAXROWS][MAXCOLS];
    int rows;
    int cols;
public :
//Constructor
    Matrix(){
        rows = MAXROWS; cols = MAXCOLS;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = '\0';
            }
        }
    }; //Set rows to MAXROWS and cols to MAXCOLS
    //Initialize all the values of matrix to zero
    //print Functions
    void printMatrix();
    //Setter Functions
    void setMatrix(T [][MAXCOLS]); //set the Array to what is sent
    void addMatrix(T [][MAXCOLS]); //add an array to matrix
    void addMatrix(Matrix<T> &);
    //No destructor needed
};


#endif //NEWPORJECT_MATRIX_H
