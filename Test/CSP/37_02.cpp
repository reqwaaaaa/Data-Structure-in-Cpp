//
// Created by Naiweilanlan on 25-5-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int benefit(int n, int m, const vector<int>& A) {
        vector<int> dp(n + 1, 0);  // dp[i] 表示投喂 i 个苹果的最大快乐值

        for (int i = 1; i <= m; ++i) { // 枚举每天可投喂的苹果数
            for (int j = i; j <= n; ++j) { // 完全背包
                dp[j] = max(dp[j], dp[j - i] + A[i]);
            }
        }

        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> A(m + 1); // A[0] = 0 已默认初始化

    for (int i = 1; i <= m; ++i) {
        cin >> A[i];
    }

    Solution sol;
    cout << sol.benefit(n, m, A) << endl;

    return 0;
}
