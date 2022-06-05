//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

void ModernCppTest92() {
    Point a {.y = 3};
    std::cout<<a.x<<std::endl;
    std::cout<<a.y<<std::endl;
}