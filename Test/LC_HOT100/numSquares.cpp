//
// Created by Naiweilanlan on 25-8-30.
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
    int numSquares(int n) {
      vector<int> dp(n + 1, INT_MAX); // dp[i] 表示 i 的最少平方数个数
      dp[0] = 0;

      for (int i = 1; i <= n; i++) {
        for (int j = 1; j*j <= i; j++) {
          dp[i] = min(dp[i], dp[i - j*j] + 1); // 枚举平方数，表示用一个平方数 j * j 加上剩余部分 i - j * j 的最优解。
        }
      }
      return dp[n];
    }
};

/*
Q:
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

输入：n = 12
输出：3
解释：12 = 4 + 4 + 4

输入：n = 13
输出：2
解释：13 = 4 + 9
 */
