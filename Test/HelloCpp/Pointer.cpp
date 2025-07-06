//
// Created by Naiweilanlan on 25-7-6.
//

#include <iostream>
using namespace std;

class PointerAndReferenceDemo {
public:
    // 一、引用基本用法：ref 是 x 的别名，修改 ref 就等于修改 x
    void referenceBasic() {
        int x = 10;
        int &ref = x; // ref 是 x 的引用（别名）

        cout << "[引用] 初始值 x = " << x << ", ref = " << ref << endl;
        ref = 20;
        cout << "[引用] 修改 ref 后 x = " << x << endl;
    }

    // 二、指针基本用法：通过 *p 解引用来修改原始值
    void pointerBasic() {
        int y = 30;
        int* p = &y; // p 是指向 y 的指针

        cout << "[指针] 初始值 y = " << y << ", *p = " << *p << endl;
        *p = 40; // 解引用修改 y 的值
        cout << "[指针] 修改 *p 后 y = " << y << endl;

        // 指针还可以重新指向别的变量
        int z = 50;
        p = &z;
        cout << "[指针] p 现在指向 z，*p = " << *p << endl;
    }

    // 三、使用引用参数修改主调函数变量
    void setByReference(int &ref) {
        ref = 100; // 直接修改主调函数传进来的变量
    }

    // 四、使用指针参数修改主调函数变量
    void setByPointer(int* ptr) {
        if (ptr != nullptr) {
            *ptr = 200; // 解引用修改原值
        }
    }
};

int main() {
    PointerAndReferenceDemo demo;

    // （1）引用的基本使用
    demo.referenceBasic();
    cout << "--------------------------" << endl;

    // （2）指针的基本使用
    demo.pointerBasic();
    cout << "--------------------------" << endl;

    // （3）引用参数修改变量
    int a = 1;
    cout << "[主函数] 初始 a = " << a << endl;
    demo.setByReference(a);
    cout << "[主函数] setByReference 后 a = " << a << endl;

    // （4）指针参数修改变量
    int b = 2;
    cout << "[主函数] 初始 b = " << b << endl;
    demo.setByPointer(&b); // 传地址
    cout << "[主函数] setByPointer 后 b = " << b << endl;

    return 0;
}
