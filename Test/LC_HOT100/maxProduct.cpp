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
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      int maxProd = nums[0]; // 全局最大乘积
      int curMax = nums[0]; // 当前最大乘积
      int curMin = nums[0]; // 当前最小乘积

      for (int i = 1; i < n; i++) {
        int tmp = curMax; // 寄存器
        curMax = max({nums[i], curMax * nums[i], curMin * nums[i]}); // 三个元素相比，记得加大括号
        curMin = min({nums[i], curMin * nums[i], curMax * nums[i]});
        maxProd = max(maxProd, curMax);
      }
      return maxProd;
    }
};

/*
Q:
给你一个整数数组 nums ，请你找出数组中乘积最大的 非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

输入: nums = [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 */

/*
正 × 正 = 正（更大）。
正 × 负 = 负（更小）。
负 × 负 = 正（可能更大）。
0 会重置乘积。
 */