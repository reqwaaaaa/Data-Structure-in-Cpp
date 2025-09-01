//
// Created by Naiweilanlan on 25-9-1.
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
    string longestPalindrome(string s) {
      if (s.size() < 2) return s;

      int n = s.size();
      int maxStart = 0, maxLen = 1;
      vector<vector<bool>> dp(n, vector<bool>(n, false));

      // 所有长度为1的子串都是回文串
      for (int i = 0; i < n; ++i)
        dp[i][i] = true;
      // 枚举子串的右端点 r，从左往右
      for (int r = 1; r < n; ++r) {
        for (int l = 0; l < r; l++) {
          if (s[l] == s[r] && ((r - l) <= 2 || dp[l + 1][r - l])) {
            dp[l][r] = true;
            if (r - l + 1 > maxLen) { // 检查当前子串长度 r - l + 1 是否大于 已知 的最长回文长度 maxLen
              maxLen = r - l + 1; // 记录新的最长回文子串长度
              maxStart = l; // 记录新回文子串的起始索引
            }
          }
        }
      }
      return s.substr(maxStart, maxLen);
    }
};

/*
Q:
给你一个字符串 s，找到 s 中最长的 回文 子串。

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
 */

/*
动态规划思想：
  状态定义：dp[l][r] 表示子串 s[l..r]（包括 l 和 r）是否为回文串（true 表示是，false 表示不是）。
  状态转移：
如果 s[l] == s[r]（两端字符相同），则 s[l..r] 是否为回文取决于内侧子串 s[l+1..r-1]：
若 r - l <= 2（长度为 1 或 2，如 "aa" 或 "a"），则 s[l..r] 是回文。
否则，检查 dp[l+1][r-1] 是否为 true。
  目标：找到最长的回文子串，记录起点 maxStart 和长度 maxLen。
 */