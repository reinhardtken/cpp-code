//
// Created by liuqingping on 2022/6/6.
//
#include <iostream>
namespace test3 {
    struct A
    {
        virtual void foo() {} // 声明虚函数
    };

    struct B : public A
    {
        // 隐式继承了虚函数
    }; 
}

namespace test31 {

    using namespace std;
    class A
    {
    public:
        int a;
    };
    class B : public A
    {
    public:
        int b;
    };
    class C : public A
    {
    public:
        int c;
    };
    class D : public B, public C
    {
    public:
        int d;
    };
    int main()
    {
        D d;
        cout << &d << endl;
        cout << &d.B::a << endl;
        cout << &d.C::a << endl;
        cout << &d.b << endl;
        cout << &d.c << endl;
        cout << &d.d << endl;
        cout<< "sizeof(D): "<<sizeof(D)<<endl;
        return 0;
    }
}

namespace test32 {

    using namespace std;
    class A
    {
    public:
        int a;
    };
    class B : virtual public A
    {
    public:
        int b;
    };
    class C : virtual public A
    {
    public:
        int c;
    };
    class D : public B, public C
    {
    public:
        int d;
    };
    int main()
    {
        D d;
        cout << &d << endl;
        cout << &d.B::a << endl;
        cout << &d.C::a << endl;
        cout << &d.b << endl;
        cout << &d.c << endl;
        cout << &d.d << endl;
        cout<< "sizeof(D): "<<sizeof(D)<<endl;
        return 0;
    }
}

namespace test33 {

    using namespace std;
    class A
    {
    public:
        int a;
    };
    class B : public A
    {
    public:
        int b;
    };
    class C : public A
    {
    public:
        int c;
    };
    class D : virtual public B, virtual public C
    {
    public:
        int d;
    };
    int main()
    {
        D d;
        cout << &d << endl;
        cout << &d.B::a << endl;
        cout << &d.C::a << endl;
        cout << &d.b << endl;
        cout << &d.c << endl;
        cout << &d.d << endl;
        cout<< "sizeof(D): "<<sizeof(D)<<endl;
        return 0;
    }
}


void Test3() {
    using namespace test3;
    B b{};
    A& a_rb = b; // 将b绑定到A的左值引用a_rb上

    std::cout<<typeid(decltype(a_rb)).name()<<std::endl; // decltype产生的是编译时即可确定的声明类型，因此为A
    std::cout<<typeid(a_rb).name()<<std::endl; // 由于a_rb是多态类型的glvalue，typeid在运行时计算，因此为B

    a_rb.foo();  // 这里调用的是B中的foo，其函数地址是运行时确定的
    std::cout<<sizeof(b)<<std::endl;   // 这里的sizeof是编译器决定的，通常为8 (64位)

    test31::main();

    test32::main();

    test33::main();
}

