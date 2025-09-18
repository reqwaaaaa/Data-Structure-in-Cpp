//
// Created by Naiweilanlan on 25-9-15.
//
//

// 常见模拟题工具函数合集

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>
// #include <bits/stdc++.h>

using namespace std;

// ---------------------------
// 输入输出优化
// ---------------------------
inline void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ---------------------------
// 数位拆解与组合
// ---------------------------

// 1. 拆分整数的各位（高位到低位）
vector<int> getDigits(int n) {
    vector<int> digits;
    if (n == 0) return {0}; // 特殊情况
    while (n > 0) {
        digits.push_back(n % 10); // 从低位取
        n /= 10;
    }
    reverse(digits.begin(), digits.end()); // 转成高位到低位
    return digits;
}

// 2. 反转整数（123 → 321），带溢出检测
long long reverseInt(long long n) {
    long long ans = 0;
    while (n > 0) {
        if (ans > (LLONG_MAX - n % 10) / 10) {
            throw overflow_error("Integer overflow in reverseInt");
        }
        ans = ans * 10 + (n % 10);
        n /= 10;
    }
    return ans;
}

// 3. 数位和
int digitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// 4. 判断是否为回文数
bool isPalindromeNum(long long n) {
    return n == reverseInt(n);
}

// ---------------------------
// 小数位提取
// ---------------------------

// 获取浮点数小数点后第 k 位（k=1 表示第一位）
int getDecimalDigit(double x, int k) {
    return ((long long)(x * pow(10, k))) % 10;
}

// 获取小数点后前 k 位，返回数组
vector<int> getDecimalDigits(double x, int k) {
    vector<int> res;
    for (int i = 1; i <= k; i++) {
        res.push_back(getDecimalDigit(x, i));
    }
    return res;
}

// ---------------------------
// 四舍五入 & 截断
// ---------------------------

// 截断到小数点后 k 位
double truncateDouble(double x, int k) {
    double p = pow(10, k);
    return (long long)(x * p) / p;
}

// 四舍五入到小数点后 k 位
double roundDouble(double x, int k) {
    double p = pow(10, k);
    return round(x * p) / p;
}

// ---------------------------
// 进制转换
// ---------------------------

// 十进制 → 任意进制表示（base <= 16）
string toBase(long long n, int base) {
    if (n == 0) return "0";
    string digits = "0123456789ABCDEF";
    string res;
    while (n > 0) {
        res.push_back(digits[n % base]);
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 任意进制 → 十进制
long long fromBase(const string &s, int base) {
    long long ans = 0;
    for (char c : s) {
        int val = (c >= '0' && c <= '9') ? c - '0' : toupper(c) - 'A' + 10;
        ans = ans * base + val;
    }
    return ans;
}

// ---------------------------
// 字符与数字转换
// ---------------------------

// 字符转数字
int charToDigit(char c) {
    return c - '0'; // '0' 的 ASCII 值是 48
}

// 数字转字符
char digitToChar(int d) {
    return '0' + d;
}

// 字符串转整数（手写版，不依赖 stoi）
long long strToInt(const string &s) {
    long long ans = 0;
    for (char c : s) {
        ans = ans * 10 + (c - '0');
    }
    return ans;
}

// ---------------------------
// 模拟加法（字符串大整数加法）
// ---------------------------

// 输入两个非负整数（字符串形式），返回它们的和
string addStrings(string a, string b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

// ---------------------------
// 测试主函数（可选）
// ---------------------------
int main() {
    fastIO();

    // 测试数位拆解
    int n = 12345;
    auto digits = getDigits(n);
    cout << "Digits of " << n << ": ";
    for (int d : digits) cout << d << " ";
    cout << endl;

    // 测试反转
    cout << "Reverse of " << n << ": " << reverseInt(n) << endl;

    // 测试小数提取
    double x = 4.5678;
    cout << "Decimal digits of " << x << ": ";
    for (int d : getDecimalDigits(x, 3)) cout << d << " ";
    cout << endl;

    // 测试进制转换
    cout << "255 in hex: " << toBase(255, 16) << endl;
    cout << "FF in dec: " << fromBase("FF", 16) << endl;

    // 测试大数加法
    cout << "Big add: " << addStrings("123456789", "987654321") << endl;

    return 0;
}
