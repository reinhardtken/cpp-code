//
// Created by liuqingping on 2022/6/3.
//

class X {
public:
    X() {}
    X(const X&) {}
    X& operator = (const X&) { return *this; }
};

X make_x()
{
    return X();
}

class Y {
public:
    Y() {}
    Y(Y&) {}
    Y& operator = (Y&) { return *this; }
};

Y make_y()
{
    return Y();
}

void ModernCppTest62()
{
    X x1;
    X x2(x1);
    X x3(make_x());
    x3 = make_x();

    Y y1;
    Y y2(y1);
    // set(CMAKE_CXX_STANDARD 20)，set(CMAKE_CXX_STANDARD 17)下面的代码不会报错
    // set(CMAKE_CXX_STANDARD 14)，会报错
    // note: candidate constructor not viable: expects an l-value for 1st argument
    Y y3(make_y());
    //下面的代码会报错，因为 Y& operator = (Y&)的函数签名需要一个左值，但是make_y返回的是右值
    //note: candidate function not viable: expects an l-value for 1st argument
    //    Y& operator = (Y&) { return *this; }
    //y3 = make_y();
}