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
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount + 1, amount + 1); //当目标金额为 i 时，至少需要 dp[i] 枚
      dp[0] = 0;
      for (int i = 0; i < dp.size(); i++) {
        for (int coin : coins) {
          if (i - coin < 0) continue; // 金额不足以使用当前面值的硬币
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
      return dp[amount] = amount + 1 ? -1 : dp[amount];
    }
};

/*
Q:
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1

输入：coins = [2], amount = 3
输出：-1
 */