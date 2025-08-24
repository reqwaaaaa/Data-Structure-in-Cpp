//
// Created by Naiweilanlan on 25-8-24.
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
    int searchInsert(vector<int>& nums, int target) {
      int n = nums.size();
      int l = 0, r = n - 1;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] >= target) r = m;
        else l = m + 1;
      }
      return nums[l] < target ? l+1 : l;
    }
};

/*
Q:
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

输入: nums = [1,3,5,6], target = 5
输出: 2

输入: nums = [1,3,5,6], target = 7
输出: 4
 */