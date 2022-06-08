//
// Created by liuqingping on 2022/6/5.
//

#include <iostream>

namespace N302 {
    union alignas(256) X
    {
        char a1;
        int a2;
        double a3;
    };
}

void ModernCppTest302() {
    using namespace N302;
    X *x = new X();
    std::cout << "x = " << x << std::endl;
}