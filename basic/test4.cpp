//
// Created by liuqingping on 2022/6/7.
//

#include <iostream>

void Test4() {
    {
        int x = 1;
        const int cx = x;
        const int& rx = x;
        auto y = x;
        auto* y2 = &x;
        auto const y3 = cx;
        auto & y4 = rx;

        std::cout<<typeid(decltype(x)).name()<<std::endl;
        std::cout<<typeid(decltype(cx)).name()<<std::endl;
        std::cout<<typeid(decltype(rx)).name()<<std::endl;

        std::cout<<typeid(decltype(y)).name()<<std::endl;
        std::cout<<typeid(decltype(y2)).name()<<std::endl;
        std::cout<<typeid(decltype(y3)).name()<<std::endl;
        std::cout<<typeid(decltype(y4)).name()<<std::endl;
    }

    {
        const char x [] = "Hello World";
        auto a = x;
        auto& b = x;
        std::cout<<typeid(decltype(a)).name()<<std::endl;
        std::cout<<typeid(decltype(b)).name()<<std::endl;
    }

}
