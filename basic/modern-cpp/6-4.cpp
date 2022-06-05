//
// Created by liuqingping on 2022/6/3.
//

#include <iostream>
class BigMemoryPool {
public:
    static const int PoolSize = 4096;
    BigMemoryPool() : pool_(new char[PoolSize]) {}
    ~BigMemoryPool()
    {
        if (pool_ != nullptr) {
            delete[] pool_;
        }
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

void ModernCppTest64()
{
    BigMemoryPool my_pool = make_pool();
}
