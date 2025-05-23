//
// Created by Naiweilanlan on 25-5-23.
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
#include <numeric>  // for gcd

using namespace std;

class Solution {
public:
    // 求最大公约数
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // 计算总权值（暴力 + 剪枝骗分版）
    long long totalGCDWeight(const vector<int>& a) {
        int n = a.size();
        long long total = 0;

        for (int i = 0; i < n; ++i) {
            int g = 0;

            // 限制区间长度最多看100个（避免超时）
            for (int j = i; j < n && j - i < 100; ++j) {
                g = gcd(g, a[j]);

                // 如果当前gcd等于前一个，就不扩展，剪枝
                if (j > i && gcd(g, a[j]) == g) break;

                total += 1LL * (j - i + 1) * g;
            }
        }

        return total;
    }
};

int main() {
    // IO优化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 读取输入
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    Solution sol;
    // 输出结果
    cout << sol.totalGCDWeight(a) << endl;

    return 0;
}
