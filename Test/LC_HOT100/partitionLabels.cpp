//
// Created by Naiweilanlan on 25-8-29.
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
    vector<int> partitionLabels(string s) {
      int n = s.size();
      int last[26]; // 记录每个字符最后出现的位置
      for (int i = 0; i < 26; i++) {
        last[s[i] - 'a'] = i; // 更新字符的最后出现位置
      }
      vector<int> ans;
      int start = 0, end = 0; // 当前分区起点 和 最远边界
      for (int i = 0; i < n; i++) {
        end = max(end, last[s[i] - 'a']); // 更新分区最远边界，当前字符必须包含到其最后出现位置
        if (i == end) { // 当前位置是分区终点
          ans.push_back(end - start + 1);
          start = i + 1; // 新分区起点
        }
      }
      return ans;
    }
};

/*
Q:
给你一个字符串 s (s 仅由小写英文字母组成) 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。
注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
返回一个表示每个字符串片段的长度的列表。

输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。

输入：s = "eccbbbbdec"
输出：[10]
 */