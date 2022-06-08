//
// Created by liuqingping on 2022/6/5.
//

#include <iostream>

consteval int sqr(int n) {
    return n*n;
}

void ModernCppTest272() {
    constexpr int a = sqr(100);
    int x = 100;
    int a2 = sqr(x);
    std::cout<<a2<<std::endl;
}