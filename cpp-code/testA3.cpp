#include <iostream>
#include <stdio.h>

namespace inherit__example3 {
  //菱形继承，有virtual继承，有virtual方法
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

  struct B : virtual public A {
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

  struct C : virtual public A {
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


void TestA30() {
  using namespace inherit__example3;
  A a;
  B b;
  C c;
  D d;
  A* pa = &d;
  B* pb = &d;
  C* pc = &d;

  typedef void(*Fun)(void);

  Fun** vt_ptrA = (Fun**)&a;
  Fun** vt_ptrB = (Fun**)&b;
  Fun** vt_ptrC = (Fun**)&c;
  Fun** vt_ptrD = (Fun**)&d;
  A* paa = &b;
  Fun** vt_ptrBA = (Fun**)paa;

  std::cout << "-----------vt_ptrB------------" << std::endl;
  printf("&b : %p\n", &b);
  for (int i = 0; i < 4; i++) {
    printf("[b] vptr[%d] : %p\n", i, *(*vt_ptrB + i));
  }

  std::cout << "-----------vt_ptrBA------------" << std::endl;
  printf("&ba : %p\n", paa);
  for (int i = 0; i < 4; i++) {
    printf("[a] vptr[%d] : %p\n", i, *(*vt_ptrBA + i));
  }
  int z;
  z = a.x;
  z = b.x;
  z = d.x;


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

void TestA31() {
  using namespace inherit__example3;
  A a;
  B b;
  D d;
  int z;
  A* ba = &b;
  A* da = &d;
  B* db = &d;
  //A中访问x
  z = a.x;
  //B中访问x
  z = b.x;
  z = ba->x;
  //D中访问x
  z = d.x;
  z = da->x;
  z = db->x;
}



void TestA3() {
  //Test80();
  //Test81();
  //TestA30();
  TestA31();
}