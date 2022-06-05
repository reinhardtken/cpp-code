//
// Created by liuqingping on 2022/6/4.
//

#include <iostream>
#include <string>

class MyString : public std::string {};

void ModernCppTest151()
{
    std::cout << "std::is_aggregate_v<std::string> = "
              << std::is_aggregate_v<std::string> << std::endl;
    std::cout << "std::is_aggregate_v<MyString> = "
              << std::is_aggregate_v<MyString> << std::endl;
}