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
    string s;
    cin >> s; // 读取形如 #Hello World#
    s = s.substr(1, s.length() - 2); // 提取原始字符串

    int n;
    cin >> n; // 读取字符对数
    unordered_map<char, char> f;
    for (int i = 0; i < n; i++) {
        string pair;
        cin >> pair; // 读取形如 #HH#
        f[pair[1]] = pair[2]; // f(x) = y
    }

    int m;
    cin >> m; // 读取查询数
    vector<int> k(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i]; // 读取每个 k
    }

    string current = s; // 当前字符串
    for (int i = 0; i < m; i++) {
        string result = current;
        int steps = k[i];
        while (steps--) {
            string next = result;
            for (int j = 0; j < result.length(); j++) {
                char ch = result[j];
                next[j] = f.count(ch) ? f[ch] : ch; // 替换或保持不变
            }
            result = next;
        }
        cout << "#" << result << "#" << endl; // 输出形如 #s#
    }

    return 0;
}