//
// Created by Naiweilanlan on 25-8-11.
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
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      int n = nums.size();
      sort(nums.begin(), nums.end()); //升序排列

      for (int a = 0; a < n; a++) {
        if (a > 0 && nums[a] == nums[a - 1]) continue; //如果当前 nums[a] 与前一个 nums[a-1] 相同，跳过当前 a。目的是避免重复三元组。例如，nums = [-1, -1, 0, 1] 中，第一个 -1 和第二个 -1 会产生相同的三元组，跳过第二个 -1。
        int b = a + 1;
        int c = n - 1;
        int target = -nums[a];

        for (b; b < n; b++) {
          if (b > a+1 && nums[b] == nums[b-1]) continue;
          while (b < c && nums[b] + nums[c] > target) c--;

          if (b == c) break;

          if (nums[b] + nums[c] == target) ans.push_back({nums[a], nums[b], nums[c]});
        }
      }
      return ans;
    }
};

/*
Q：
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 */