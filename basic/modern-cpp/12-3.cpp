//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>
namespace N123 {
    class X
    {
    public:
        X() try : X(0) {
            std::cout<< " X default" <<std::endl;
        }
        catch (int e)
        {
            std::cout << "catch: " << e << std::endl;
            throw 3;
        }
        X(int a) try : X(a, 0.) {
            std::cout<< " X one param" <<std::endl;
        }
        catch (int e)
        {
            std::cout << "catch: " << e << std::endl;
            throw 2;
        }
        X(double b) : X(0, b) {
            std::cout<< " X one param2" <<std::endl;
        }
        X(int a, double b) : a_(a), b_(b) { throw 1; }
    private:
        int a_;
        double b_;
    };
}


void ModernCppTest123() {
    using namespace N123;
    try {
        X x;
    }
    catch (int e) {
        std::cout << "catch: " << e << std::endl;
    }
}
