//
// useMatrixTemplate.cpp
// Created by Archibald Chain on 2020/5/23.
//
#include "Matrix.h"
#include <iostream>

using namespace std;
template <typename T1>
void useMatrixTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);
int main()
{
    string str1[MAXROWS][MAXCOLS] =
    {
        {"Congra", "y", "ar"},
        {"alm", "don", "La"}
    };
    string str2[MAXROWS][MAXCOLS] =
    {
       {"tulations", "ou", "e"},
       {"ost", "e  the", "b!"}
       };
    int num1[MAXROWS][MAXCOLS] =
    {
        {1,2,3},
        {4,5,6}
    };
    int num2[MAXROWS][MAXCOLS] =
    {
        {6,5,4},
        {3,2,1}
    };
    float float1[MAXROWS][MAXCOLS] =
    {
        {1.6,2.5,3.4},
        {4.3,5.2,6.1}
    };

    float float2[MAXROWS][MAXCOLS] =
    {
        {6.1,5.2,4.3},
        {3.4,2.5,1.6}
    };
    Matrix<string> stringMatrix;
    Matrix<int> intMatrix;
    Matrix<float> floatMatrix;
    cout << "\nDemonstrating with string matrix:" << endl;
    useMatrixTemplate(stringMatrix, str1, str2);
    cout << "\nDemonstrating with int matrix:" << endl;
    useMatrixTemplate(intMatrix, num1, num2);
    cout << "\n" << endl;
    useMatrixTemplate(floatMatrix, float1, float2);
    return 0;
}
template <typename T1>
void useMatrixTemplate(Matrix<T1>& M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS])
{
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();
    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}