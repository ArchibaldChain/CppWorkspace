//
// Created by Archibald Chain on 2020/5/3.
//

#ifndef NEWPORJECT_RECTANGLE_H
#define NEWPORJECT_RECTANGLE_H


class Rectangle {
    double width;
    double height;
public:
    Rectangle();
    Rectangle(double width, double height);
    ~Rectangle(){};
    double getArea();
    double getPerimeter();
    void display();
};



#endif //NEWPORJECT_RECTANGLE_H
