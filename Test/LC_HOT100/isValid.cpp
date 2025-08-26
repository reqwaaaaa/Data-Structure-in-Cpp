//
// Created by Naiweilanlan on 25-8-25.
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
    bool isValid (string s) {
      unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6}};
      stack<char> st;
      bool ans = true;

      for (char c : s) {
        if (m[c] >= 1 && m[c] <= 3) st.push(c);
        else if (!st.empty() && m[st.top()] == m[c] - 3) st.pop();
        else {
          ans = false;
          break;
        }
      }
      if (!st.empty()) return false;
      return ans;
    }
};

/*
Q:
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

输入：s = "()[]{}"
输出：true

输入：s = "([)]"
输出：false
 */