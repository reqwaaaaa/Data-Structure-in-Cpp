//
// Created by 86138 on 2025/1/3.
//

// 这是 HelloWorld 类的实现部分，定义了 sayHello() 方法
#include "HelloWorld.h"
#include <iostream>
using namespace std;

void HelloWorld::sayHello() {
    cout << "Hello World!" << endl;
}

// main 函数
int main() {
    HelloWorld obj;   // 创建 HelloWorld 类的对象
    obj.sayHello();   // 调用 sayHello 方法
    return 0;         // 程序正常结束
}