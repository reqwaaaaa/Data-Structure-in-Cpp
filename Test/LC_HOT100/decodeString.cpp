//
// Created by Naiweilanlan on 25-8-27.
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
    string decodeString(string s) {
      string ans = "";
      stack<int> nums; //存储括号前的数字（重复次数）
      stack<string> strs; //存储括号前的字符串（外层结果）
      int num = 0;
      int len = s.length();

      for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0'; //输入可能包含多位数字（如 "123"），不能简单将字符转为单个数
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ans = ans + s[i];
        else if (s[i] == '[') {
          nums.push(num);
          num = 0;
          strs.push(ans);
          ans = "";
        } else {
          int times = nums.top();
          nums.pop();
          for (int j = 0; j < times; j++) {
            strs.top() += ans;
          }
          ans = strs.top();
          strs.pop();
        }
      }
      return ans;
    }
};

/*
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

输入：s = "3[a]2[bc]"
输出："aaabcbc"

输入：s = "3[a2[c]]"
输出："accaccacc"
 */

/*
[：保存当前状态（num 和 ans）入栈，重置 num 和 ans。
]：弹出数字和外层字符串，重复当前 ans 并拼接。
 */