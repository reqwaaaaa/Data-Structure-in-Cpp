//
// Created by Naiweilanlan on 25-8-24.
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
  vector<vector<string>> partition(string s) {
    int n = s.length();
    vector<vector<string>> ans;
    vector<string> path;

    auto dfs = [&](this auto&& dfs, int i) {
      if(i == n) {
        ans.push_back(path);
        return;
      }
      for(int j = i; j<n; j++) {
        if(isPalindrome(s,i,j)) {
          path.push_back(s.substr(i,j-i+1));
          dfs(j+1);
          path.pop_back();
        }
      }
    };
    dfs(0);
    return ans;
  }
private:
  bool isPalindrome(string& s, int left, int right) {
    while(left < right) {
      if(s[left++] != s[right--]) return false;
    }
    return true;
  }
};

/*
Q:
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
 */