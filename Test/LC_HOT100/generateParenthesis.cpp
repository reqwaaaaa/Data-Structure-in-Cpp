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
    vector<string> generateParenthesis(int n) {
      int m = n * 2; //生成字符串的总长度（n 个左括号 + n 个右括号）
      vector<string> ans;
      string path(m, 0);

      auto dfs = [&](this auto&& dfs, int i, int left) { //left:已使用的左括号 ( 数量，跟踪括号匹配状态
        if (i == m) {
          ans.push_back(path);
          return;
        }
        //左括号数 ≤ n，右括号数 ≤ 未匹配的左括号数
        if (left < n) {
          path[i] = '(';
          dfs(i + 1, left + 1);
        }
        if (i - left < left) { //若当前未匹配的左括号数 (i - left) < left
          path[i] = ')';
          dfs(i + 1, left);
        }
      };
      dfs(0, 0);
      return ans;
    }
};

/*
Q:
数字 n 代表生成括号(限定小括号‘（）’)的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
 */