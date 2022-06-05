//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>
namespace N122 {
    class X {
    public:
        X(){
            std::cout<<"construct X"<<std::endl;
            throw 1;
        }

        ~X() { std::cout << "~X()" << std::endl; }
    };
}


int ModernCppTest122() {
    using namespace N122;
    try {
        X x;
    }
    catch (...) {
    }
}
