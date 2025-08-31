//
// Created by Naiweilanlan on 25-8-30.
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
    int longestValidParentheses(string s) {
      int n = s.size();
      vector<int> dp(n, 0); //dp[i] = 以 i 结尾的最长有效括号长度
      int ans = 0;

      for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
          if (s[i - 1] == '(') { // 情况 1: ...()
            dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
          } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') { // 情况 2: ...))
            dp[i] = dp[i - 1] + 2;
            if (i - dp[i - 1] >= 2) {
              dp[i] += dp[i - dp[i - 1] - 2];
            }
          }
          ans = max(ans, dp[i]);
        }
      }
      return ans;
    }
};

/*
Q:
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号 子串 的长度。
左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如 "(()())"。

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
 */

/*
动态规划思想：
  状态定义：dp[i] 表示以索引 i 结尾的子串中最长有效括号的长度。
  初始化：dp[i] = 0，因为以 '(' 结尾的子串无法形成有效括号（有效括号必须以 ')' 结束）。
状态转移：只在 s[i] == ')' 时更新 dp[i]，考虑以下两种情况：
  情况 1：当前是 ')'，前一个是 '('（即 ...()）：
形如 ...()，形成一个有效括号对，长度为 2。
加上前面的有效括号长度：dp[i] = dp[i - 2] + 2（若 i >= 2）。
例如：s = "()"，i = 1，dp[1] = dp[-1] + 2 = 0 + 2 = 2。
  情况 2：当前是 ')'，前一个也是 ')'（即 ...))）：
前一个 ')' 结尾的有效子串长度为 dp[i - 1]，检查 i - dp[i - 1] - 1 处的字符是否为 '('。
如果是 '('，则形成新的有效括号对，长度为 dp[i - 1] + 2。
再加上 i - dp[i - 1] - 2 处的有效括号长度（若存在）：dp[i] += dp[i - dp[i - 1] - 2]。
例如：s = "(())"，i = 3，dp[2] = 2，检查 i - dp[2] - 1 = 3 - 2 - 1 = 0，s[0] = '('，则 dp[3] = dp[2] + 2 + dp[0] = 2 + 2 + 0 = 4。
  全局结果：ans = max(ans, dp[i])，记录所有 dp[i] 的最大值。
 */