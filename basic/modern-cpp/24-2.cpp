//
// Created by liuqingping on 2022/6/5.
//

#include <string>
#include <utility>

int ci_compare(const char* s1, const char* s2)
{
    while (tolower(*s1) == tolower(*s2++)) {
        if (*s1++ == '\0') {
            return 0;
        }
    }
    return tolower(*s1) - tolower(*--s2);
}

class CIString2 {
public:
    CIString2(const char* s) : str_(s) {}

    bool operator < (const CIString2& b) const {
        return ci_compare(str_.c_str(), b.str_.c_str()) < 0;
    }
private:
    std::string str_;
};

using namespace std::rel_ops;

void ModernCppTest242()
{
    CIString2 s1{ "hello" }, s2{ "world" };
    bool r = s1 >= s2;
}
