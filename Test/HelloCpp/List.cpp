//
// Created by Naiweilanlan on 25-2-18.
//

#include <iostream>
#include <list>
using namespace std;

int main() {
    // 初始化链表
    list<int> lst{1, 2, 3, 4, 5};

    // 插入元素
    lst.push_front(0);
    lst.push_back(6);

    // 获取头尾元素
    cout << "头部: " << lst.front() << ", 尾部: " << lst.back() << endl;

    // 删除头尾
    lst.pop_front();
    lst.pop_back();

    // 在中间插入
    auto it = lst.begin();
    advance(it, 2);
    lst.insert(it, 99);

    // 删除元素
    it = lst.begin();
    advance(it, 1);
    lst.erase(it);

    // 遍历链表
    cout << "遍历链表: ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    // 排序、反转
    lst.sort();
    cout << "排序后: ";
    for (int val : lst) cout << val << " ";
    cout << endl;

    lst.reverse();
    cout << "反转后: ";
    for (int val : lst) cout << val << " ";
    cout << endl;

    return 0;
}