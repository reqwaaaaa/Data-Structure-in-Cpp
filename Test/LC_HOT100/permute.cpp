//
// Created by Naiweilanlan on 25-8-21.
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
    vector<vector<int>> permute(vector<int>& nums) {
      dfs(nums, 0);
      return ans;
    }

    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int x) { //当前处理的索引，表示确定第 x 个位置的数字
      if (x == nums.size() - 1) {
        ans.push_back(nums);
        return;
      }
      for (int i = x; i < nums.size(); i++) {
        swap(nums[i], nums[x]); //将 nums[i] 固定在第 x 个位置
        dfs(nums, i + 1); //处理下一个位置
        swap(nums[i], nums[x]); //回溯，恢复数组状态
      }
    }
};

/*
Q:
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */