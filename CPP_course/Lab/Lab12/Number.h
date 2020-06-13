//
// Created by Archibald Chain on 2020/5/9.
//

#include <iostream>
#ifndef NEWPORJECT_NUMBER_H
#define NEWPORJECT_NUMBER_H


class Number {
    int num;
public:
    Number();
    Number(int);
    Number operator ++();//prefix
    Number operator ++(int); //postfix
    Number operator --(); //prefix
    Number operator --(int); //postfix
    friend std::ostream & operator<<(std::ostream &os, Number const & n);
    explicit operator int() const;

};


#endif //NEWPORJECT_NUMBER_H
