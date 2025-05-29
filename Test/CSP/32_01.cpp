//
// Created by Naiweilanlan on 25-5-28.
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

class Solution {
public:
    // 判断 b 是否是 a 的上级：即 b 每一维都比 a 大
    bool isStrictlyGreater(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (b[i] <= a[i]) return false;
        }
        return true;
    }

    vector<int> fuc(int n, int m, vector<vector<int>>& index) {
        vector<int> res(n, 0); // 默认是 0，表示无上级

        for (int i = 0; i < n; ++i) {
            int minIdx = -1;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isStrictlyGreater(index[i], index[j])) { //判断仓库 j 的编码是否“每一维都严格大于” 仓库 i 的编码
                    if (minIdx == -1 || j < minIdx) { //如果这是第一个候选上级，或者比当前记录的上级编号更小，就更新 minIdx
                        minIdx = j;
                    }
                }
            }
            res[i] = (minIdx == -1) ? 0 : (minIdx + 1); // 转换为 1-based 编号（题目从1开始编号）
        }
        return res;
    }
};

int main() {
    // IO优化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> index(n, vector<int>(m)); // 需要初始化行数和列数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> index[i][j];
        }
    }

    Solution sol;
    vector<int> ans = sol.fuc(n, m, index);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
