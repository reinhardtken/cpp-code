#include <iostream>

namespace test5 {
    class A {
    public:
        A() {}

        ~A() {
            std::cout<<"~A"<<std::endl;
            throw 42;
        }
    };
}


void TestOut5() {
    using namespace test5;
    try {
        A a;
        throw 32;
    }
    catch (int a) {
        std::cout << a;
    }
}