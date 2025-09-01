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
    int minDistance(string s, string t) {
      int m = s.length(), n = s.length();
      vector<vector<int>> dp(m + 1, vector<int>(n + 1));

      // 初始化
      for (int i = 0; i <= m; ++i) dp[i][0] = i;
      for (int j = 0; j <= n; ++j) dp[0][j] = j;

      // 状态转移
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (s[i - 1] == t[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            dp[i][j] = min({
                dp[i - 1][j] + 1,    // 删除
                dp[i][j - 1] + 1,    // 插入
                dp[i - 1][j - 1] + 1 // 替换
            });
          }
        }
      }
      return dp[m][n];
    }
};

/*
Q:
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 */

/*
动态规划思想：
  状态定义：dp[i][j] 表示将 word1[0..i-1] 转换为 word2[0..j-1] 所需的最少操作次数。
  状态转移：
如果 word1[i-1] == word2[j-1]（当前字符相同），无需操作：
dp[i][j] = dp[i-1][j-1]。
如果字符不同，考虑三种操作的最小值：
删除：删除 word1[i-1]，用 dp[i-1][j] + 1。
插入：在 word1 中插入 word2[j-1]，用 dp[i][j-1] + 1。
替换：将 word1[i-1] 替换为 word2[j-1]，用 dp[i-1][j-1] + 1。
  边界条件：
dp[i][0] = i：将 word1[0..i-1] 转换为空字符串，需删除 i 个字符。
dp[0][j] = j：将空字符串转换为 word2[0..j-1]，需插入 j 个字符。
  目标：计算 dp[m][n]，即转换整个 word1 到 word2 的最少操作次数。
 */