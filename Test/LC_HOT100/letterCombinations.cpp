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
  //静态数组，存储数字到字母的映射（0-9），如 MAPPING[2] = "abc", MAPPING[3] = "def"。
    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  public:
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
      int n = digits.length();
      string path(n, 0); //当前递归路径，长度为 n，记录正在构建的组合

      if (n == 0) return {};
      auto dfs = [&](this auto dfs, int i) {
        if (i == n) { //// 长度和输入一致就记录一组
          ans.push_back(path);
          return;
        }
        for (char c : MAPPING[digits[i] - '0']) {
          path[i] = c;
          dfs(i + 1);
        }
      };
      dfs(0);
      return ans;
    }
};

/*
Q:
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合(类似于笛卡尔积)。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 */