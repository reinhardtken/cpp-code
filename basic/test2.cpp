//
// Created by liuqingping on 2022/6/1.
//
#include <iostream>

class A {
    char c;
    int  i;
    short s;
};

class B {
    int   i;
    char  c;
    short s;
};

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

void Test2() {
    {
        std::cout << "A:" << sizeof(A) << std::endl;
        std::cout << "B:" << sizeof(B) << std::endl;
    }

    {
        char str[] = "world"; std::cout << sizeof(str) << ": ";
        char *p    = str;     std::cout << sizeof(p) << ": ";
        char i     = 10;      std::cout << sizeof(i) << ": ";
        void *pp   = malloc(10);  std::cout << sizeof(pp) << std::endl;
    }

    {
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
}