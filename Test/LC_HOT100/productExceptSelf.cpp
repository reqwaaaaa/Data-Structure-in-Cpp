//
// Created by Naiweilanlan on 25-8-13.
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
    vector<int> productExceptSel(vector<int> &nums) {
      int n = nums.size();
      vector<int> pre(n, 1); //前缀积
      vector<int> suf(n, 1); //后缀积
      vector<int> ans;

      for (int i = 1; i < n; i++) {
        pre[i] = pre[i-1] * nums[i-1];
      }
      for (int i = n-2; i >= 0; i--) {
        suf[i] = suf[i+1] * nums[i+1];
      }

      for (int i = 0; i < n; i++) {
        ans.push_back(pre[i] * suf[i]);
      }
      return ans;
    }
};

/*
Q:
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

输入: nums = [1,2,3,4]
输出: [24,12,8,6]
 */