#include <iostream>

class A {
public:
    A()
    :a(Value()) {
        Construct();
    }

    ~A() {
        Destruct();
    }

    virtual void Construct() {
        std::cout << " A Construct"<<std::endl;
    }

    virtual void Destruct() {
        std::cout << " A Destruct"<<std::endl;
    }

    virtual int Value() {
        return 1;
    }

    int a;
};

class B : public A {
public:
    B()
    :b(Value()) {
        Construct();
    }

    ~B() {
        Destruct();
    }

    virtual void Construct() {
        std::cout << " B Construct"<<std::endl;
    }

    virtual void Destruct() {
        std::cout << " B Destruct"<<std::endl;
    }

    virtual int Value() {
        return 2;
    }
    int b;
};

void Test1() {
    B *b = new B();
    A *p = b;
    std::cout<<"a: "<<b->a<<std::endl;
    std::cout<<"b: "<<b->b<<std::endl;
    std::cout<<"A: "<<sizeof(A)<<std::endl;
    std::cout<<"B: "<<sizeof(B)<<std::endl;
    delete p;
}
