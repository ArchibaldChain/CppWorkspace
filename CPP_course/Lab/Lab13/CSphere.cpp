//
// Created by Archibald Chain on 2020/5/17.
//

#include <iostream>
#include "CSphere.h"

void CSphere::show(){
    std::cout << "Sphere: ";
    std::cout << "\tradius: " << radius;
    std::cout << "\tarea: " << getArea();
    std::cout << "\tvolume: " << getVolume() << std::endl;
}

CSphere::CSphere(double r): radius(r){
}
