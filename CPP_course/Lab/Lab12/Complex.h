//
// Created by Archibald Chain on 2020/5/8.
//

#include <iostream>
#ifndef LAB12_COMPLEX_H
#define LAB12_COMPLEX_H

using namespace std;
class Complex {
private:
    double image;
    double real;
public:
    Complex();
    Complex(double re, double im = 0);
    ~Complex();
    Complex operator~() const;
    friend Complex operator+(const Complex & data1, const Complex & data2);
    friend Complex operator-(const Complex & data1, const Complex & data2);
    friend bool operator==(const Complex & data1, const Complex & data2);
    friend bool operator!=(const Complex & data1, const Complex & data2);
    friend Complex operator*(const Complex & data1, const Complex & data2);
    friend ostream & operator<<(ostream & os, const Complex & data);
    friend istream & operator>>(istream & ins, Complex & data);
};
#endif //LAB12_COMPLEX_H
