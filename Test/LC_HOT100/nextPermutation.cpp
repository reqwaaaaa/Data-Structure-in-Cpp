//
// Created by Naiweilanlan on 25-8-26.
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
    void nextPermutation(vector<int>& nums) {
      int len = nums.size();
      int i = len - 2;
      // 1. 从后往前找第一个“升序对”(nums[i] < nums[i+1])
      while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
      }
      // 2. 如果找到了（即不是完全降序），找一个比它大的数来交换
      if (i >= 0) {
        int j = len - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
          j--;
        }
        swap(nums[i], nums[j]);
      }
      // 3. 将 i 之后的部分翻转（变成升序）
      reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
Q:
  整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
  整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
  给你一个整数数组 nums ，找出 nums 的下一个排列。必须 原地 修改，只允许使用额外常数空间。

输入：nums = [1,2,3]
输出：[1,3,2]
 */