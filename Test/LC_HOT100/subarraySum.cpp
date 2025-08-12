//
// Created by Naiweilanlan on 25-8-12.
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
    int subarraySum(vector<int>& nums, int k) {
      vector<int> prefixsum; //前缀和数组
      prefixsum.resize(nums.size() + 1);
      for (int i = 0; i < nums.size(); i++) {
        prefixsum[i + 1] = prefixsum[i] + nums[i];
      }

      int ans = 0;
      unordered_map<int, int> map; //键（int）：前缀和的值 s[j]。值（int）：该前缀和出现的次数。
      for (int j : prefixsum) { //对于当前前缀和 s[j+1]，检查是否存在前缀和 s[i] 等于 s[j+1] - k
        ans += map.contains(j - k) ? map[j - k] : 0;
        map[j]++;
      }
      return ans;
    }

};

/*
Q:
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
(子数组是数组中元素的连续非空序列。)

输入：nums = [1,1,1], k = 2
输出：2
 */

/*
前缀和是指数组从起始位置到某个索引的元素和。对于数组 nums，前缀和数组 s 定义为：
s[0] = 0（空前缀的和）。
s[i] = nums[0] + nums[1] + ... + nums[i-1]（前 i 个元素的和）。

sum[i, j] = nums[i] + nums[i+1] + ... + nums[j] = prefixsum[j+1] - prefixsum[i]
如果要找和为 k 的子数组 [i, j]，则需要：prefixsum[j+1] - prefixsum[i] == k

 */