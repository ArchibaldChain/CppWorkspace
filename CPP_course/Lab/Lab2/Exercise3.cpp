//
// Created by Archibald Chain on 2020/2/27.
//
#include <iostream>
int main(){
    using namespace std;
    cout<<"Please Enter a Character:";
    char c;
    cin >> c;
    cout << "Please Enter an Intager Value:";
    int n;
    cin >> n;
    cout << "Please Enter Float Value:";
    float f;
    cin >> f;
    printf("The variables you entered were:\n\
           The Char Value that you Entered is: %c\n\
           The Integer Value that you Entered is: %d\n\
           The Float Value that you Entered is: %.3f\n\
           ",c, n,f);

}

