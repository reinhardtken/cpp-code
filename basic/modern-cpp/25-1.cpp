//
// Created by liuqingping on 2022/6/5.
//

thread_local int tv;
static int sv;

void ModernCppTest251()
{
    constexpr int *sp = &sv;	// 编译成功，sv的地址在编译时确定
    //error: constexpr variable 'tp' must be initialized by a constant expression
    //    constexpr int *tp = &tv;    // 编译失败，tv的地址在运行时确定
//    constexpr int *tp = &tv;	// 编译失败，tv的地址在运行时确定
}