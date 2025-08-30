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
    bool canPartition(vector<int>& nums) {
      int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2 != 0) {
        return false; // 奇数无法平分
      }

      int target = sum / 2;
      vector<bool> dp(target + 1, false); // dp[j] 表示是否存在子集的和等于 j（布尔值，true 表示存在）。
      dp[0] = true;
      for (int num : nums) {
        for (int j = target; j >= num; j--) {
          dp[j] = dp[j] || dp[j - num];
        }
      }
      return dp[target];
    }
};

/*
Q:
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 */

/*
0/1 背包问题：
问题等价于：从 nums 中选出若干元素（每个元素只能选一次），使其和等于 sum/2（目标和）。
状态转移：
对于每个元素 num，从大到小遍历目标和 j（从 target 到 num）。
dp[j] = dp[j] || dp[j - num]，表示：
如果不选 num，则 dp[j] 保持不变。
如果选 num，则检查是否存在子集和为 j - num（即 dp[j - num]）。

逆序遍历（j 从大到小）确保每个 num 只被使用一次，符合 0/1 背包的约束。
 */