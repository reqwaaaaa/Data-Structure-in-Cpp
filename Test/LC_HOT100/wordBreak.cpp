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
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
      int n = s.size();
      vector<bool> dp(n + 1, false);
      dp[0] = true; // 空串可拆分

      // 遍历目标字符串的每一个前缀长度 i
      for (int i = 1; i <= n; i++) {
        // 遍历所有可能的切分点 j
        for (int j = 0; j < i; j++) {
          string word = s.substr(j, i - j);
          if (dp[j] && dict.count(word)) {
            dp[i] = true;
            break;
          }
        }
      }
      return dp[n];
    }
};

/*
Q:
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
 */

/*
如果前 j 个字符（即 s[0...j-1]）可以被字典中的词拼出来（dp[j] == true）
且从 j 到 i-1 这段（s[j...i-1]）正好是一个字典中的词
➜ 那么 s[0...i-1] 也可以被拼出来（dp[i] = true）
 */