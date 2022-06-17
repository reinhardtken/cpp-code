#include <iostream>

namespace inherit_example {
  //¶à¼Ì³Ð£¬ÎÞvirtual
  struct A
  {
    void foo() {
      std::cout << "A foo" << std::endl;
    }
    int x{1};
  };
  struct B
  {
    void foo() {
      std::cout << "B foo" << std::endl;
    }
    int x{2};
  };

  struct C : public A, public B {
    void foo() {
      std::cout << "C foo" << std::endl;
    }
  };

}

void Test7() {
  using namespace inherit_example;
  C c;
  A* pa = &c;
  std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(*pa).name() << std::endl;
  c.A::foo();
  c.B::foo();
  c.foo();
  std::cout << c.A::x << std::endl;
  std::cout << c.B::x << std::endl;
  std::cout << sizeof(c) << std::endl;
}