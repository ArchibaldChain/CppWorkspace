//
// Created by Archibald Chain on 2020/5/17.
//

#include <iostream>
#include "CCube.h"
#include "CSphere.h"
#include "CStereoShape.h"

int main(){
    CCube a_cube(4, 5, 6);
    CSphere c_sphere(7.9);
    CStereoShape * p = &a_cube;
    p->show();
    p = &c_sphere;
    p->show();
    std::cout << p->GetNumberOfObject();
}
