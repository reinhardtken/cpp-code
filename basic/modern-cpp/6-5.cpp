//
// Created by liuqingping on 2022/6/3.
//

#include <chrono>
#include <iostream>
namespace N65 {
    class BigMemoryPool {
    public:
        static const int PoolSize = 40960;
        BigMemoryPool() : pool_(new char[PoolSize]) {}
        ~BigMemoryPool()
        {
            if (pool_ != nullptr) {
                delete[] pool_;
            }
        }

        BigMemoryPool(BigMemoryPool&& other)
        {
            std::cout << "move big memory pool." << std::endl;
            pool_ = other.pool_;
            other.pool_ = nullptr;
        }

        BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize])
        {
            std::cout << "copy big memory pool." << std::endl;
            memcpy(pool_, other.pool_, PoolSize);
        }

    private:

        char *pool_;
    };

    BigMemoryPool get_pool(const BigMemoryPool& pool)
    {
        return pool;
    }

    BigMemoryPool make_pool()
    {
        BigMemoryPool pool;
        return get_pool(pool);
    }

    BigMemoryPool get_pool2(BigMemoryPool&& pool)
    {
        return std::move(pool);
    }

    BigMemoryPool make_pool2()
    {
        BigMemoryPool pool;
        return get_pool2(std::move(pool));
    }
}


void ModernCppTest65()
{
    using namespace N65;
//    {
//        BigMemoryPool my_pool = make_pool();
//    }

//    {
//        auto start = std::chrono::high_resolution_clock::now();
//        for (int i = 0; i < 1000000; i++) {
//            //macbook上
//            //move big memory pool.
//            //Time to call make_pool :2.34937 s
//            BigMemoryPool my_pool = make_pool2();
//            //copy big memory pool.
//            //Time to call make_pool :4.16072 s
////            BigMemoryPool my_pool = make_pool();
//        }
//        auto end = std::chrono::high_resolution_clock::now();
//        std::chrono::duration<double> diff = end - start;
//        std::cout << "Time to call make_pool :" << diff.count() << " s" << std::endl;
//    }
    {
        BigMemoryPool my_pool;
        BigMemoryPool my_pool2 = my_pool;
        BigMemoryPool my_pool3 = static_cast<BigMemoryPool&&>(my_pool);
        //潜在隐患，再已经承诺将亡之后再次使用my_pool
        BigMemoryPool my_pool4 = my_pool;
    }

}
//int main()

