//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>
#include <string>

void test() {
    int x = 1;
    int y = 2;
    //error: cannot assign to a variable captured by copy in a non-mutable lambda
    //        x += 1;
//    auto foo = [x, &y] {
//        x += 1;
//        y += 1;
//        std::cout << "in lambda x addr: " <<&x << std::endl;
//        std::cout << "in lambda y addr: " <<&y << std::endl;
//        return x+y;
//    };
    //可以通过编译，lambda里面的x和外面的x不是一个变量
    auto foo = [x, &y]() mutable {
        x += 1;
        y += 2;
        std::cout << "in lambda x addr: " <<&x << std::endl;
        std::cout << "in lambda y addr: " <<&y << std::endl;
        std::cout << "in lambda x value: " <<x << std::endl;
        std::cout << "in lambda y value: " <<y << std::endl;
        return x+y;
    };
    std::cout << "x addr: " <<&x << std::endl;
    std::cout << "y addr: " <<&y << std::endl;
    x += 1;
    y += 2;
    foo();
    std::cout << "x value: " << x << std::endl;
    std::cout << "y value: " << y << std::endl;
    x += 2;
    y += 2;
    foo();
}

void ModernCppTest71() {
    test();
}