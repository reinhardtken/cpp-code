//
// Created by liuqingping on 2022/6/5.
//

namespace N312 {
    class X {
    public:
        [[nodiscard]] X() {}
        X(int a) {}
    };
}

void ModernCppTest312() {
    using namespace N312;
    X x;
    //warning: ignoring temporary created by a constructor declared with 'nodiscard' attribute [-Wunused-value]
    //    X{};
    X{};
    X{ 42 };
}