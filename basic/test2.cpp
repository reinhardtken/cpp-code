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

int Test2() {
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
}