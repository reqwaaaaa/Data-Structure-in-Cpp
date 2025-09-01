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
    int longestCommonSubsequence(string s, string t) {
      int m = s.length(), n = t.length();
      vector<int> dp(n + 1, 0);
      vector<int> prev(n + 1, 0);

      for (int i = 1; i <= m; i++) {
        swap(dp, prev);
        for (int j = 1; j <= n; j++) {
          if (s[i - 1] == t[j - 1]) {
            dp[j] = prev[j - 1] + 1; // dp[i-1][j-1]
          } else {
            dp[j] = max(prev[j], dp[j - 1]); // dp[i-1][j] & dp[i][j-1]
          }
        }
      }
      return dp[n];
    }
};

/*
Q:
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。

输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace" ，它的长度为 3 。
 */

/*
  动态规划思想：
状态定义：dp[i][j] 表示 text1[0..i-1] 和 text2[0..j-1] 的最长公共子序列长度。
  状态转移：
如果 text1[i-1] == text2[j-1]，当前字符匹配，LCS 长度加 1：
dp[i][j] = dp[i-1][j-1] + 1。
如果不匹配，取不包含当前字符的最大值：
dp[i][j] = max(dp[i-1][j], dp[i][j-1])。
  边界条件：
dp[i][0] = 0（text2 为空）。
dp[0][j] = 0（text1 为空）。
  目标：计算 dp[m][n]。

空间优化：
观察：计算 dp[i][j] 只依赖：
上一行：dp[i-1][j] 和 dp[i-1][j-1]。
当前行：dp[i][j-1]。
使用两个一维数组：
prev[j]：存储上一行的状态（dp[i-1][j]）。
dp[j]：存储当前行的状态（dp[i][j]）。
swap(dp, prev)：每行计算后交换，dp 变成上一行，prev 用于新行。
结果：dp[n] 即 dp[m][n]。
 */