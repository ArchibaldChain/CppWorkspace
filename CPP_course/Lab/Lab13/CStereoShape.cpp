//
// Created by Archibald Chain on 2020/5/17.
//

#include "CStereoShape.h"
#include <iostream>

int CStereoShape::numberOfObject = 0;

CStereoShape::CStereoShape(){
    std::cout << "CStereoShape::constructor\n";
    numberOfObject ++;
}
double CStereoShape::getArea(){
    std::cout << "CStereoShape::GetArea()\n";
    return 0.0;
}

double CStereoShape::getVolume(){
    std::cout << "CStereoShape::GetVolume()\n";
    return 0.0;
}

void CStereoShape::show(){
    std::cout << "CStereoShape::show()\n";
}

int CStereoShape::GetNumberOfObject(){
    return numberOfObject;
}
