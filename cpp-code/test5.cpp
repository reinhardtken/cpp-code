#include <iostream>

namespace inherit_example {
  //最简单的继承，无virtual
  struct A
  {
    void foo() {}
  };

  struct B : public A  {
    void foo() {}
  };
    
}

void Test5() {
  using namespace inherit_example;
  A a;
  const char* a_name = typeid(a).name();
  std::cout << a_name << std::endl;
  a.foo();
  std::cout << sizeof(a) << std::endl;

  B b;
  A* pa = &b;
  const char* b_name = typeid(b).name();
  std::cout << b_name  <<std::endl;
  std::cout << typeid(*pa).name() << std::endl;
  b.foo();     
  std::cout << sizeof(b) << std::endl;
}