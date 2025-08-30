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
  int rob(vector<int>& nums) {
    int pre = 0; // dp[i-1]，表示抢到第 i-1 个房子的最大金额
    int cur = 0; // dp[i]，表示抢到第 i 个房子的最大金额
    int temp;    // 临时变量，用于保存 cur 的值
    for (int num : nums) {
      temp = cur;              // 保存 dp[i]
      cur = max(pre + num, cur); // dp[i+1] = max(dp[i-1] + num, dp[i])
      pre = temp;              // dp[i-1] = dp[i]
    }
    return cur;
  }
};

/*
Q:
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 */

/*
动态规划思想：
定义状态：dp[i] 表示抢到第 i 个房子（包括不抢第 i 个房子）时的最大金额。
状态转移方程：
抢第 i 个房子：dp[i] = dp[i-2] + nums[i]（不能抢第 i-1 个）。
不抢第 i 个房子：dp[i] = dp[i-1]。
因此：dp[i] = max(dp[i-2] + nums[i], dp[i-1])。
初始条件：dp[0] = nums[0]，dp[1] = max(nums[0], nums[1])。
 */