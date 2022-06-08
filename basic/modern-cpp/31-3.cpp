//
// Created by liuqingping on 2022/6/5.
//

#include <iostream>

namespace N313 {

    struct Empty {};
    struct Empty2 {};

    struct X {
        int i;
        Empty e;
        Empty2 e2;
        int c;
    };

    struct X2 {
        int i;
        [[no_unique_address]] Empty e;
        [[no_unique_address]] Empty2 e2;
        int c;
    };
}

void ModernCppTest313() {
    using namespace N313;
    std::cout << "sizeof(Empty) = " << sizeof(Empty) << std::endl;
    Empty a[10];
    std::cout << "sizeof(a) = " << sizeof(a) << std::endl;

    std::cout << "sizeof(X) = " << sizeof(X) << std::endl
              << "X::i address = " <<  &((X*)0)->i << std::endl
              << "X::e address = " << &((X*)0)->e << std::endl
              << "X::e address = " << &((X*)0)->e2 << std::endl
              << "X::c address = " << &(((X*)0)->c) << std::endl;

    std::cout << "sizeof(X2) = " << sizeof(X2) << std::endl
              << "X2::i address = " <<  &((X2*)0)->i << std::endl
              << "X2::e address = " << &((X2*)0)->e << std::endl
              << "X2::e address = " << &((X2*)0)->e2 << std::endl
              << "X2::c address = " << &(((X2*)0)->c) << std::endl;

}