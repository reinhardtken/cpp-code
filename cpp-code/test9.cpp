#include <iostream>

namespace inherit_example9 {
  //菱形继承，无virtual继承，无virtual方法
  struct A
  {
    void foo() {
      std::cout << "A foo" << std::endl;
    }
    int x{ 1 };
  };
  struct B : public A  {
    void foo() {
      std::cout << "B foo" << std::endl;
    }
    int b{ 2 };
  };

  struct C : public A {
    void foo() {
      std::cout << "C foo" << std::endl;
    }
    int c{ 3 };
  };

  struct D : public B, public C {
    void foo() {
      std::cout << "D foo" << std::endl;
    }
    int d{ 4 };
  };
}

void Test9() {
  using namespace inherit_example9;
  D d;

  std::cout << &d << std::endl;
  std::cout << &d.B::x << std::endl;
  std::cout << d.B::x << std::endl;
  std::cout << &d.C::x << std::endl;
  std::cout << d.C::x << std::endl;
  std::cout << sizeof(A) << std::endl;
  std::cout << sizeof(B) << std::endl;
  std::cout << sizeof(C) << std::endl;
  std::cout << sizeof(d) << std::endl;
}