//
// Created by Archibald Chain on 2020/5/17.
//

#ifndef NEWPORJECT_CCUBE_H
#define NEWPORJECT_CCUBE_H


#include "CStereoShape.h"

class CCube: public CStereoShape {
    double length, width, height;
public:
    CCube();
    CCube(double length, double width, double height);
    double getArea();
    double getVolume();
    void show();

};

#endif //NEWPORJECT_CCUBE_H
