//
// Created by Archibald Chain on 2020/5/17.
//

#define PI 3.141592653
#include "CStereoShape.h"
#ifndef NEWPORJECT_CSPHERE_H
#define NEWPORJECT_CSPHERE_H


class CSphere:public CStereoShape {
    double radius;
public:
    CSphere(){radius = 0;};
    CSphere(double r);
    double getArea(){
        return 4*PI*radius*radius;
    }
    double getVolume(){
        return 4/3 * PI *radius*radius*radius;
    }
    void show();
};




#endif //NEWPORJECT_CSPHERE_H
