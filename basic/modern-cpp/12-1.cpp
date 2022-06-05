//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>

class X
{
public:
    X() : X(0, 0.) { throw 1; }
    X(int a) : X(a, 0.) {}
    X(double b) : X(0, b) {}
    X(int a, double b) : a_(a), b_(b) { }
    ~X() { std::cout << "~X()" << std::endl; }
private:
    int a_;
    double b_;
};

int ModernCppTest121()
{
    try {
        X x;
    }
    catch (...) {
    }
}
