#include <iostream>
#include <stdio.h>

namespace inherit__example {
  //菱形继承，无virtual继承，有virtual方法
  struct A
  {
    virtual void foo() {
      char a[20]{ "A foo" };
      std::cout << "A foo" << std::endl;
    }
    virtual void fooA() {
      char a[20]{ "A fooA" };
      std::cout << "A fooA" << std::endl;
    }
    int x{ 1 };
  };

  struct B : public A {
    void foo() override {
      char a[20]{ "B foo" };
      std::cout << "B foo" << std::endl;
    }
    virtual void fooB() {
      char a[20]{ "B fooB" };
      std::cout << "B fooB" << std::endl;
    }
    int b{ 2 };
  };

  struct C : public A {
    void foo() override {
      char a[20]{ "C foo" };
      std::cout << "C foo" << std::endl;
    }
    virtual void fooC() {
      char a[20]{ "C fooC" };
      std::cout << "C fooC" << std::endl;
    }
    int c{ 3 };
  };

  struct D : public B, public C {
    void foo() override {
      char a[20]{ "D foo" };
      std::cout << "D foo" << std::endl;
    }

    void fooB() override {
      char a[20]{ "D fooB" };
      std::cout << "D fooB" << std::endl;
    }

    void fooC() override {
      char a[20]{ "D fooC" };
      std::cout << "D fooC" << std::endl;
    }

    virtual void fooD() {
      char a[20]{ "D fooD" };
      std::cout << "D fooD" << std::endl;
    }
    int d{ 4 };
  };

}

void TestA0() {
  using namespace inherit__example;
  A a;
  B b;
  C c;
  D d;
  typedef void(*Fun)(void);

  Fun** vt_ptrA = (Fun**)&a;
  Fun** vt_ptrB = (Fun**)&b;
  Fun** vt_ptrC = (Fun**)&c;
  Fun** vt_ptrD = (Fun**)&d;
  //Fun** vt_ptrC2 = vt_ptrC + 1;

  std::cout << "-----------vt_ptrA------------" << std::endl;
  printf("&a : %p\n", &a);
  for (int i = 0; i < 4; i++) {
    printf("[a] vptr[%d] : %p\n", i, *(*vt_ptrA + i));
  }

  std::cout << "-----------vt_ptrB------------" << std::endl;
  printf("&b : %p\n", &b);
  for (int i = 0; i < 4; i++) {
    printf("[b] vptr[%d] : %p\n", i, *(*vt_ptrB + i));
  }

  std::cout << "-----------vt_ptrC------------" << std::endl;
  printf("&c : %p\n", &c);
  for (int i = 0; i < 4; i++) {
    printf("[c] vptr[%d] : %p\n", i, *(*vt_ptrC + i));
  }

  std::cout << "-----------vt_ptrD------------" << std::endl;
  printf("&c : %p\n", &d);
  for (int i = 0; i < 4; i++) {
    printf("[d] vptr[%d] : %p\n", i, *(*vt_ptrD + i));
  }

  std::cout << d.B::x<<std::endl;
  std::cout << sizeof(A) << std::endl;
  std::cout << sizeof(B) << std::endl;
  std::cout << sizeof(C) << std::endl;
  std::cout << sizeof(D) << std::endl;
  std::cout << std::endl;

}



void TestA() {
  //Test80();
  //Test81();
  TestA0();
}