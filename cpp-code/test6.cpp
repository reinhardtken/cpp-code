#include <iostream>

namespace inherit_example2 {
  //最简单的继承，有virtual
  struct A
  {
    virtual void foo() {
      std::cout << "A foo" << std::endl;
    }
  };

  struct B : public A {
    void foo() override {
      std::cout << "B foo" << std::endl;
    }
  };

}

void Test6() {
  using namespace inherit_example2;
  A a;
  const char* a_name = typeid(a).name();
  std::cout << a_name << std::endl;
  a.foo();
  std::cout << sizeof(a) << std::endl;

  B b;
  A* pa = &b;
  const char* b_name = typeid(b).name();
  std::cout << b_name << std::endl;
  
  std::cout << typeid(decltype(*pa)).name()<< std::endl;
  std::cout << typeid(*pa).name() << std::endl;
  b.foo();
  std::cout << sizeof(b) << std::endl;
}