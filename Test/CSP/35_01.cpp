//
// Created by Naiweilanlan on 25-5-24.
//

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

using namespace std;

int main() {
    int n;
    cin >> n; // 读取密码数量
    while (n--) {
        string s;
        cin >> s; // 读取每个密码

        // 统计字符类型
        bool hasLetter = false, hasDigit = false, hasSpecial = false;
        for (char c : s) {
            if (isalpha(c)) hasLetter = true; // 检查是否有字母
            else if (isdigit(c)) hasDigit = true; // 检查是否有数字
            else if (c == '*' || c == '#') hasSpecial = true; // 检查是否有特殊字符
        }

        // 统计每个字符的出现次数
        int freq[128] = {0}; // ASCII 范围，覆盖所有可能字符
        bool exceedFreq = false;
        for (char c : s) {
            freq[c]++;
            if (freq[c] > 2) exceedFreq = true; // 某字符出现超过2次
        }

        // 判别安全等级
        if (!hasLetter || !hasDigit || !hasSpecial) {
            cout << 0 << endl; // 低：缺少某种类型字符
        } else if (exceedFreq) {
            cout << 1 << endl; // 中：有字符出现超过2次
        } else {
            cout << 2 << endl; // 高：满足所有条件
        }
    }
    return 0;
}
