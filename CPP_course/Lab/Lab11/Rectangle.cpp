//
// Created by Archibald Chain on 2020/5/3.
//

#include "Rectangle.h"
#include <iostream>
using namespace std;
Rectangle::Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
}

double Rectangle::getArea() {
    return width * height;
}

double Rectangle::getPerimeter() {
    return 2*(width + height);
}

void Rectangle::display() {
    cout << "width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
}


