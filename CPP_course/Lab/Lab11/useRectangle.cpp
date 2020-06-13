//
// Created by Archibald Chain on 2020/5/3.
//

#include "Rectangle.h"
#include <iostream>
using namespace std;
int main(){
    Rectangle rec1(4, 40);
    Rectangle rec2(3.5, 35.9);

    cout << "Rectangle 1" << endl
         << "-----------------------" << endl;
    rec1.display();
    cout << "Rectangle 1" << endl
         << "-----------------------" << endl;
    rec2.display();
}


