//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>
#include <string>

template<class T>
void show_type(T t)
{
    std::cout << typeid(t).name() << std::endl;
}

template<class T>
void normal_forwarding(T t)
{
    show_type(t);
}

template<class T>
void normal_forwarding2(T& t)
{
    show_type(t);
}

template<class T>
void normal_forwarding3(T& t)
{
    show_type(t);
}

template<class T>
void perfect_forwarding(T &&t)
{
    show_type(std::forward<T>(t));
}

void ModernCppTest66() {
    std::string s = "hello world";
    normal_forwarding(s);
}