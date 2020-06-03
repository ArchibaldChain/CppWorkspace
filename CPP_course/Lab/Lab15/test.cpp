//
// test.cpp
// Created by Archibald Chain on 2020/5/31.
//
#include <iostream>
#include <exception>
using namespace std;
struct MyException : public exception {
    const char * what () const noexcept override {
        return "C++ Exception";
        }
};
int main() {
    try {
        throw MyException();
        } catch(MyException& e) {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
        } catch(std::exception& e) {
        //Other errors
        }
}
