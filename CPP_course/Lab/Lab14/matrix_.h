//
// Created by 相雨言 on 23/5/2020.
//
#ifndef LAB14_MATRIX_H
#define LAB14_MATRIX_H
#define MAXCOLS 3
#define MAXROWS 2
using namespace std;
template <class T>
class Matrix
{
private:
    T matrix[MAXROWS][MAXCOLS];
    int rows;
    int cols;
public:
    Matrix();
    void printMatrix();
    void setMatrix(T [][MAXCOLS]);
    void addMatrix(T [][MAXCOLS]);
    void addMatrix(Matrix otherMatrix);
};
template <class T>
Matrix<T>::Matrix()
{
    rows = MAXROWS;
    cols = MAXCOLS;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = '\0';
        }
    }
}
template <class T>
void Matrix<T>::addMatrix(Matrix otherMatrix)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            matrix[i][j]+=otherMatrix[i][j];
        }
    }
}
template <class T>
void Matrix<T>::printMatrix()
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j];
            if(j != cols-1){
                cout << ", ";
            }
        }
        cout << "\n";
    }
}
template <class T>
void Matrix<T>::setMatrix(T mat[][MAXCOLS])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
}
template <class T>
void Matrix<T>::addMatrix(T mat[][MAXCOLS])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0;j < cols; j++)
        {
            matrix[i][j] += mat[i][j];
        }
    }
}
#endif //LAB14_MATRIX_H
