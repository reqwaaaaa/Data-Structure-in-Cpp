//
// Created by Naiweilanlan on 25-8-12.
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
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans;

      int e[26];
      for(char c : s) e[c-'a']++; //c - 'a'将字符转换为 0 到 25 的索引（例如，'a' = 0, 'b' = 1, ...）

      int left;
      for (int right = 0; right < s.size(); right++) { //使用 [left, right] 表示当前窗口
        int c = s[right] - 'a'; //将当前字符转换为数组索引
        e[c]--; //将 s[right] 纳入窗口，减少对应字符的频率计数

        while(e[c] < 0) { //如果小于0，说明这个字符在窗口中出现次数比在p中多
          e[s[left++] - 'a']++; // 把左边字符移出窗口，恢复频次,直到e[c]>=0,即窗口中字符 c 的频率不再超标
        }

        if (right - left + 1 ==  p.size()) ans.push_back(left);
      }
      return ans;
    }
};

/*
Q:
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
(字母异位词是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。)

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 */