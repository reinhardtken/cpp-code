//
// Created by liuqingping on 2022/6/3.
//

#include <iostream>

namespace Parent {
namespace V1 {
    void foo() { std::cout << "foo v1.0" << std::endl; }
}

inline namespace V2 {
    void foo() { std::cout << "foo v2.0" << std::endl; }
}
}

void ModernCppTest24() {
    //新版本总是使用inline，而想用老版本的人也很容易批量替换
    Parent::foo();
//    Parent::V1::foo();
}
