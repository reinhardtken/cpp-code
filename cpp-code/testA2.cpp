#include <iostream>
#include <stdio.h>

namespace inherit__example2 {
  //菱形继承，有virtual继承，无virtual方法
  struct A
  {
    void foo() {
      char a[20]{ "A foo" };
      std::cout << "A foo" << std::endl;
    }
    void fooA() {
      char a[20]{ "A fooA" };
      std::cout << "A fooA" << std::endl;
    }
    int x{ 1 };
  };

  struct B : virtual public A {
    void foo() {
      char a[20]{ "B foo" };
      std::cout << "B foo" << std::endl;
    }
    void fooB() {
      char a[20]{ "B fooB" };
      std::cout << "B fooB" << std::endl;
    }
    int b{ 2 };
  };

  struct C : virtual public A {
    void foo() {
      char a[20]{ "C foo" };
      std::cout << "C foo" << std::endl;
    }
    void fooC() {
      char a[20]{ "C fooC" };
      std::cout << "C fooC" << std::endl;
    }
    int c{ 3 };
  };

  struct D : public B, public C {
    void foo() {
      char a[20]{ "D foo" };
      std::cout << "D foo" << std::endl;
    }

    void fooB() {
      char a[20]{ "D fooB" };
      std::cout << "D fooB" << std::endl;
    }

    void fooC() {
      char a[20]{ "D fooC" };
      std::cout << "D fooC" << std::endl;
    }

    void fooD() {
      char a[20]{ "D fooD" };
      std::cout << "D fooD" << std::endl;
    }
    int d{ 4 };
  };

}


void TestA20() {
  using namespace inherit__example2;
  A a;
  B b;
  C c;
  D d;
  A* pa = &d;
  B* pb = &d;
  C* pc = &d;
 
  std::cout << &a << std::endl;
  std::cout << &a.x << std::endl;

  std::cout << &b << std::endl;
  std::cout << &b.x << std::endl;
  std::cout << &b.b << std::endl;

  std::cout << &c << std::endl;
  std::cout << &c.x << std::endl;
  std::cout << &c.c << std::endl;

  std::cout << &d << std::endl;
  std::cout << &d.x << std::endl;
  std::cout << &d.d << std::endl;

  std::cout << &pa->x << std::endl;
  std::cout << &pb->x << std::endl;
  std::cout << &pc->x << std::endl;
  
  std::cout << sizeof(A) << std::endl;
  std::cout << sizeof(B) << std::endl;
  std::cout << sizeof(C) << std::endl;
  std::cout << sizeof(D) << std::endl;
  std::cout << std::endl;


}



void TestA2() {
  //Test80();
  //Test81();
  TestA20();
}