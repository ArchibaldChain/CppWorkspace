//
// Created by Archibald Chain on 2020/5/9.
//

#include <iostream>
#include "Number.h"

Number::Number() {}

Number::Number(int n): num(n) {}

//prefix
Number Number::operator++() {
    return Number(++num);
}

//postfix
Number Number::operator++(int) {
    return Number(num++);
}

//prefix
Number Number::operator--() {
    return Number(--num);
}

//postfix
Number Number::operator--(int) {
    return Number(num--);
}

Number::operator int() const{
    return num;
}

std::ostream & operator<<(std::ostream &os, const Number & n){
    os << "x = " << n.num;
    return os;
}
