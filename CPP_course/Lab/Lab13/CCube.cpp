//
// Created by Archibald Chain on 2020/5/17.
//

#include "CCube.h"
#include <iostream>

CCube::CCube():length(0), width(0), height(0){}

CCube::CCube(double length, double width, double height ) {
   this->length = length;
   this->width = width;
   this->height = height;
}
double CCube::getArea(){
    return 2*(length*width + length*height + width*height);
}
double CCube::getVolume(){
    return length * width *height;
}
void CCube::show(){
    std::cout << "Cube:";
    std::cout << "\tlength: " << length;
    std::cout << "\twidth: " << width;
    std::cout << "\theight: " << height;
    std::cout << "\tarea: " << getArea();
    std::cout << "\tvolume: " << getVolume() << std::endl;
}
