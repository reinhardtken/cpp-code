//
// Created by liuqingping on 2022/6/6.
//

#include <iostream>
#include <vector>

template<class T>
class SomeStorage {
public:
    SomeStorage() = default;
    SomeStorage(std::initializer_list<T> l) : data_(l) {};
    operator bool() const { return !data_.empty(); }
private:
    std::vector<T> data_;
};

void test1()
{
    SomeStorage<float> s1{ 1., 2., 3. };
    SomeStorage<int> s2{ 1, 2, 3 };

    std::cout << std::boolalpha;
    std::cout << "s1 == s2 : " << (s1 == s2) << std::endl;
    std::cout << "s1 + s2  : " << (s1 + s2) << std::endl;
}

template<class T>
class SomeStorage2 {
public:
    SomeStorage2() = default;
    SomeStorage2(std::initializer_list<T> l) : data_(l) {};
    explicit operator bool() const { return !data_.empty(); }
private:
    std::vector<T> data_;
};

void test2()
{
    SomeStorage2<float> s1{ 1., 2., 3. };
    SomeStorage2<int> s2{ 1, 2, 3 };

    std::cout << std::boolalpha;
    //error: invalid operands to binary expression ('SomeStorage2<float>' and 'SomeStorage2<int>')
    //    std::cout << "s1 == s2 : " << (s1 == s2) << std::endl;      // 编译失败
    //std::cout << "s1 == s2 : " << (s1 == s2) << std::endl;	// 编译失败
    //error: invalid operands to binary expression ('SomeStorage2<float>' and 'SomeStorage2<int>')
    //    std::cout << "s1 + s2  : " << (s1 + s2) << std::endl;       // 编译失败
//    std::cout << "s1 + s2  : " << (s1 + s2) << std::endl;	// 编译失败
    std::cout << "s1 : " << static_cast<bool>(s1) << std::endl;
    std::cout << "s2 : " << static_cast<bool>(s2) << std::endl;
    if (s1) {
        std::cout << "s1 is not empty" << std::endl;
    }
}

void ModernCppTest341() {
    test1();
    test2();
}