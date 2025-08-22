//
// Created by Naiweilanlan on 25-8-22.
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
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> path; //当前递归路径，记录正在构建的子集
      dfs(0, nums, path, ans);
      return ans;
    }

    void dfs(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
      ans.push_back(path); //每个节点的路径都是一个子集,初始为空
      // 做选择 → 递归 → 撤销选择
      for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        dfs(i + 1, nums, path, ans); //此处的start和permute（全排列）中的x一样，用于递归进入下一层
        path.pop_back(); //相当于一对swap
      }
    }
};

/*
Q:
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 */