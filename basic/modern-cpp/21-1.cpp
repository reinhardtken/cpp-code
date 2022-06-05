//
// Created by liuqingping on 2022/6/5.
//

#include <iostream>
#include <type_traits>
struct X {
    X() {}
    X(X&&) noexcept {}
    X(const X&) {}
    X operator= (X&&) noexcept { return *this; }
    X operator= (const X&) { return *this; }
};

struct X1 {
    X1() {}
    X1(X1&&) {}
    X1(const X1&) {}
    X1 operator= (X1&&) { return *this; }
    X1 operator= (const X1&) { return *this; }
};

template<typename T>
void swap_impl(T& a, T& b, std::integral_constant<bool, true>) noexcept
{
    std::cout<<"swap_impl run std::integral_constant<bool, true>"<<std::endl;
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
void swap_impl(T& a, T& b, std::integral_constant<bool, false>)
{
    std::cout<<"swap_impl run std::integral_constant<bool, false>"<<std::endl;
    T tmp(a);
    a = b;
    b = tmp;
}

template<typename T>
void swap(T& a, T& b)
noexcept(noexcept(swap_impl(a, b,
                            std::integral_constant<bool, noexcept(T(std::move(a)))
                                                         && noexcept(a.operator=(std::move(b)))>())))
{
    swap_impl(a, b, std::integral_constant<bool, noexcept(T(std::move(a)))
                                                 && noexcept(a.operator=(std::move(b)))>());
}

void ModernCppTest211() {
    X x1, x2;
    swap(x1, x2);

    X1 x3, x4;
    swap(x3, x4);
}
