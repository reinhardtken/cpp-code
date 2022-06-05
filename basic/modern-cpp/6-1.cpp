//
// Created by liuqingping on 2022/6/3.
//

#include <iostream>

void ModernCppTest61() {
    int x = 1;
    //error: cannot take the address of an rvalue of type 'int'
    //x++，编译器先要产生一个临时变量，存储x的当前值，然后对x+1，然后返回临时变量，所以此处为右值，右值没地址，无法通过编译
//    int *p = &x++;
    int *q = &++x;

}