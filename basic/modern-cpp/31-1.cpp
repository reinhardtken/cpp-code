//
// Created by liuqingping on 2022/6/5.
//

namespace N311 {
    [[deprecated]] void foo() {}
    class [[deprecated]] X {};
}

void ModernCppTest311() {
    using namespace N311;
    X x;
    //warning: 'foo' is deprecated [-Wdeprecated-declarations]
    //    foo();
    foo();
}