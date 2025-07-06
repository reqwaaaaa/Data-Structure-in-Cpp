//
// Created by Naiweilanlan on 25-7-6.
//

#include <iostream>
using namespace std;

class Solution {
public:
    // 方式一：函数值返回
    int getSquareValue(int x) {
        return x * x;
    }

    // 方式二：通过参数引用返回
    void getSquareByReference(int x, int &result) {
        result = x * x;
    }
};

int main() {
    Solution sol;

    int number = 5;
    int result1, result2;

    // 使用函数值返回
    result1 = sol.getSquareValue(number);
    cout << "使用函数值返回：" << number << "^2 = " << result1 << endl;

    // 使用参数引用返回
    sol.getSquareByReference(number, result2);
    cout << "使用参数引用返回：" << number << "^2 = " << result2 << endl;

    return 0;
}
