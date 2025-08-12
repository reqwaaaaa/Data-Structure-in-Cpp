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
    int lengthOfLongestSubstring(string s) {
      int ans, left;
      unordered_map<char, int> map; //键是字符 char，值是该字符在字符串 s 中最近出现的索引 int

      for (int i = 0; i < s.length(); i++) {
        if (map.find(s[i]) != map.end()) {
          left = max(left, map[s[i]]+1); //如果窗口[left, i]中出现重复字符，将左边界移动到重复字符的下一个位置
        }
        map[s[i]] = i; //记录或更新 s[i] 的最新索引
        ans = max(ans, i - left + 1);
      }
      return ans;
    }
};

/*
Q:
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串(连续的非空字符序列) 的长度。
 */