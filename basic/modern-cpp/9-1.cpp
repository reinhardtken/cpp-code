//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>
#include <vector>


void ModernCppTest91() {
    std::vector<int> a(5, 2);
    std::vector<int> b{5, 2};
    for (auto one : a) {
        std::cout<<one;
    }
    std::cout<<std::endl;
    for (auto one : b) {
        std::cout<<one;
    }
}