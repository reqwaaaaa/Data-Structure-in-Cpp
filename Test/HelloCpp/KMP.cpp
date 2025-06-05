//
// Created by Naiweilanlan on 25-6-5.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 构建部分匹配表（前缀函数）
vector<int> computeNext(const string &pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1]; // 回退
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }

    return next;
}

// 执行KMP搜索，返回匹配起始位置
vector<int> KMP(const string &text, const string &pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();

    if (m == 0) return {};  // 空模式串

    vector<int> next = computeNext(pattern);

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1]; // 回退j
        }

        if (text[i] == pattern[j]) {
            j++;
        }

        if (j == m) {
            result.push_back(i - m + 1); // 匹配成功
            j = next[j - 1]; // 继续寻找下一个
        }
    }

    return result;
}

int main() {
    string text = "ababcababcabc";
    string pattern = "ababc";

    vector<int> matches = KMP(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
