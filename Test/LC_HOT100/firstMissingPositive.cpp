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
    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size();

      for (int num : nums) {
        if (num <= 0) num = n+1; //把所有非正数（<= 0）以及超过n的数，替换成n+1
      }

      for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        if (num <= n) nums[num - 1] = -abs(nums[num - 1]); //如果num出现过，就把num下标对应的数组值标为负
      }

      for (int i = 0; i < n; i++) {
        if (nums[i] > 0) return i + 1; //第一个正数对应的下标
      }
      return n + 1; //如果 [1, n] 都出现了，那最小缺失正整数就是 n+1
    }
};

/*
Q:
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

输入：nums = [3,4,-1,1]
输出：2
解释：1 在数组中，但 2 没有。
 */