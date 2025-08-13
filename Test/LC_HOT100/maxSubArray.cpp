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
    int maxSubArray(vector<int>& nums) {
      int pre = 0; //表示以当前元素 num 结尾的最大子数组和（前缀和）。
      int ans = nums[0]; //选择 nums[0] 而非 0 是为了正确处理全负数数组（如 [-1]，应返回 -1 而非 0）

      for (int num : nums) {
        pre = max(pre + num, num); //确保 pre 是以当前元素结尾的最大子数组和
        ans = max(ans, pre);
      }
      return ans;
    }
};

/*
Q:
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 */