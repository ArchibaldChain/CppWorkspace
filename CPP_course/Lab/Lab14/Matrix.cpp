//
// Matrix.cpp
// Created by Archibald Chain on 2020/5/23.
//
#include "Matrix.h"
#include <iostream>

template<class T>
void Matrix<T>::setMatrix(T array[][MAXCOLS]){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] == array[i][j];
        }
    }
}

template<class T>
void Matrix<T>::printMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j]<< " ";
        }
        std::cout << std::endl;
    }
}



template <class T>
void Matrix<T>::addMatrix(T otherArray[][MAXCOLS])
{
    for (int i=0; i< rows; i++)
    {
        for(int j=0; j< cols; j++)
        {
            matrix[i][j] += otherArray[i][j];
        }
    }
}

template <class T>
void Matrix<T>::addMatrix(Matrix<T> & otherArray)
{
    for (int i=0; i< rows; i++)
    {
        for(int j=0; j< cols; j++)
        {
            matrix[i][j] += otherArray.matrix[i][j];
        }
    }
}