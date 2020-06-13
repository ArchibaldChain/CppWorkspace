//
// Created by Archibald Chain on 2020/5/17.
//

#include <iostream>
#ifndef NEWPORJECT_CSTEREOSHAPE_H
#define NEWPORJECT_CSTEREOSHAPE_H


class CStereoShape {
    static int numberOfObject;
public:
    //constructor
    CStereoShape();
    virtual double getArea();
    virtual double getVolume();
    virtual void show();
    int GetNumberOfObject();
};


#endif //NEWPORJECT_CSTEREOSHAPE_H
