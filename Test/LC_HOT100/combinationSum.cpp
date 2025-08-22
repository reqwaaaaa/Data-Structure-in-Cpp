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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> path;
      sort(candidates.begin(), candidates.end());
      int start = 0;
      bfs(path, target, candidates, start, ans);
      return ans;
    }
    void bfs(vector<int>& path, int target, vector<int>& candidates, int start, vector<vector<int>>& ans) {
      if (target == 0) { //组合和达到目标,把当前path记录进ans
        ans.push_back(path);
        return;
      }
      for (int i = start; i < candidates.size(); i++) {
        if (target - candidates[i] < 0) { //构不成目标值，且后续数字更大，直接退出循环（排序过）
          break;
        }
        path.push_back(candidates[i]);
        bfs(path, target - candidates[i], candidates, i, ans); //此处i不+1是因为同一个数可以重复取
        path.pop_back(); //回溯
      }
    }
};

/*
Q：
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
 */