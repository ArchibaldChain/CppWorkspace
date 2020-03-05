//
// Created by Archibald Chain on 2020/2/27.
//
# include<iostream>

int main(){
    using namespace std;
    int x,y;
    cin >> x;
    cin >> y;
    cout << "x value y value Expressions \t Result"<< endl;
    cout << x << " |\t"<< y << " |\tx=y+3\t\t |x="<< y+3<<endl;
    cout << x << " |\t"<< y << " |\tx=y-3\t\t |x="<< y-2<<endl;
    cout << x << " |\t"<< y << " |\tx=y*5\t\t |x="<< y*5<<endl;
    cout << x << " |\t"<< y << " |\tx=x/y\t\t |x="<< x/y<<endl;
    cout << x << " |\t"<< y << " |\tx=x%y\t\t |x="<< x%y<<endl;

}

