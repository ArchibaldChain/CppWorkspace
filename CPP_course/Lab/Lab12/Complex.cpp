//
// Created by Archibald Chain on 2020/5/8.
// Complex0.cpp -- implementing Complex methods
//

#include "Complex.h"
#include <iostream>

using namespace  std;
Complex::Complex():real(0),image(0){}

Complex::Complex(double re,double im):real(re),image(im){
}

Complex::~Complex(){
    cout << "Complex number: " << *this << " is deleted" << endl;
}

Complex Complex::operator~() const {
    return Complex(real, -image);
}

//plus
Complex operator+(const Complex & data1, const Complex& data2){
    return Complex(data1.real + data2.real, data1.image + data2.image);
}

//minus
Complex operator-(const Complex & data1, const Complex& data2){
    return Complex(data1.real - data2.real, data1.image - data2.image);
}

Complex operator*(const Complex & data1, const Complex& data2){
    double a = data1.real;
    double b = data1.image;
    double c = data2.real;
    double d = data2.image;
    return Complex(a*c-b*d, a*d+b*c);
}

bool operator==(const Complex & data1, const Complex& data2){
    return (data1.real == data2.real && data1.image == data2.image);
}

bool operator!=(const Complex & data1, const Complex& data2){
    return !(data1 == data2);
}


ostream & operator<<(ostream & os, const Complex & data){
    if(data.image < 0)
        os << data.real <<data.image<<"i";
    else if (data.image == 0)
        os << data.real;
    else
        os << data.real << "+" <<data.image<<"i";
    return os;
}

istream & operator>>(istream & ins, Complex & data) {
    ins.clear();
    cout << "real: " ;
    ins >> data.real;
    cout << "imaginary: ";
    ins >> data.image;
}

