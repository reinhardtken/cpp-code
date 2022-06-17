#include <iostream>
#include <stdio.h>

namespace inherit_example2 {
  //¶à¼Ì³Ð£¬ÓÐvirtual
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
  };

  struct B
  {
    virtual void foo() {
      char a[20]{ "B foo" };
      std::cout << "B foo" << std::endl;
    }
    virtual void fooB() {
      char a[20]{ "B fooB" };
      std::cout << "B fooB" << std::endl;
    }
  };

  struct C : public A, public B {
    void foo() override {
      char a[20]{ "C foo" };
      std::cout << "C foo" << std::endl;
    }
    virtual void fooC() {
      char a[20]{ "C fooC" };
      std::cout << "C fooC" << std::endl;
    }
  };

}


void Test82() {
  using namespace inherit_example2;
  A a;
  B b;
  C c;
  typedef void(*Fun)(void);

  Fun** vt_ptrA = (Fun**)&a;
  Fun** vt_ptrB = (Fun**)&b;
  Fun** vt_ptrC = (Fun**)&c;
  Fun** vt_ptrC2 = vt_ptrC+1;

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

  std::cout << "-----------vt_ptrC2------------" << std::endl;
  printf("&c : %p\n", &c);
  for (int i = 0; i < 4; i++) {
    printf("[c] vptr[%d] : %p\n", i, *(*vt_ptrC2 + i));
  }

  B* pB = &c;
  printf("pB : %p\n", pB);
  pB->foo();

  std::cout << std::endl;

  
}


void Test81() {
  using namespace inherit_example2;
  A a;
  B b;
  C c;
  C c2;
  A* pa = &c;
  B* pb = &c;
  std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(*pa).name() << std::endl;
  std::cout << typeid(*pb).name() << std::endl;
  auto pfun2 = &C::fooC;
  auto pfun1 = &C::foo;
  printf("C::fooC: %x \n", &C::fooC);
  std::cout<< pfun2 << std::endl;
  std::cout << pfun1 << std::endl;

  c.A::foo();
  c.B::foo();
  c.foo();
  std::cout << sizeof(A) << std::endl;
  std::cout << sizeof(B) << std::endl;
  std::cout << sizeof(c) << std::endl;
}

void Test80() {
  using namespace inherit_example2;
  C c;
  A* pa = &c;
  B* pb = &c;
  std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(*pa).name() << std::endl;
  std::cout << typeid(*pb).name() << std::endl;
  c.A::foo();
  c.B::foo();
  c.foo();
  std::cout << sizeof(A) << std::endl;
  std::cout << sizeof(B) << std::endl;
  std::cout << sizeof(c) << std::endl;
}

void Test8() {
  //Test80();
  //Test81();
  Test82();
}