//
// Created by liuqingping on 2022/6/6.
//

#include <iostream>
#include <new>

namespace N342 {

    struct X {
        X() {}
        ~X()
        {
            std::cout << "call dtor" << std::endl;
        }
        void* operator new(size_t s)
        {
            return ::operator new(s);
        }

        void operator delete(void* ptr)
        {
            std::cout << "call delete" << std::endl;
            ::operator delete(ptr);
        }
    };

    struct X2 {
        X2() {}
        ~X2()
        {
            std::cout << "call X2 dtor" << std::endl;
        }
        void* operator new(size_t s)
        {
            return ::operator new(s);
        }

        void operator delete(X2* ptr, std::destroying_delete_t)
        {
            std::cout << "call X2 delete" << std::endl;
            ptr->~X2();
            ::operator delete(ptr);
        }
    };

}

void ModernCppTest342() {
    using namespace N342;
    X* x = new X;
    delete x;

    X2* x2 = new X2;
    delete x2;
}