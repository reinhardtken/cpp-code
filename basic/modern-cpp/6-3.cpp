//
// Created by liuqingping on 2022/6/3.
//

#include <iostream>


namespace N63 {
    class X {
    public:
        X() { std::cout << "X ctor：" << this << std::endl; }
        X(const X&x) { std::cout << "X copy ctor: " << this << std::endl; }
        ~X() { std::cout << "X dtor: " << this << std::endl; }
        void show() { std::cout << "show X: " << this << std::endl; }
    };

    X make_x() {
        X x1;
        return x1;
    }
}

//需要关闭返回值优化
//SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
void ModernCppTest63() {
    using namespace N63;
    {
//        X x2 = N63::make_x();
//        x2.show();
    }
    {
        X &&x2 = N63::make_x();
        x2.show();
    }
}