//
// Created by liuqingping on 2022/6/4.
//


#include <iostream>
#include <string>
#include <vector>

union U
{
    U() : x3() {}
    ~U() { x3.~basic_string(); }
    int x1;
    float x2;
    std::string x3;
    std::vector<int> x4;
};

void ModernCppTest111()
{
    U u;
    u.x3 = "hello world";
    std::cout << u.x3;
}