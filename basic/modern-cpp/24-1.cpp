//
// Created by liuqingping on 2022/6/5.
//

#include <compare>
#include <iostream>

struct B
{
    int a;
    long b;
    auto operator <=> (const B&) const = default;
};

struct D : B
{
    short c;
    auto operator <=> (const D&) const = default;
};

void ModernCppTest241()
{
    D x1, x2;
    std::cout << typeid(decltype(x1 <=> x2)).name()<<std::endl;
    std::cout << typeid(decltype(7.7 <=> 1.1)).name()<<std::endl;
}