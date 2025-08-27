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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int> ans(n, 0);
      stack<int> st; // 存索引

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()]) { //单增栈（存储索引，栈顶到栈底对应温度递增）
          st.pop(); //若当前温度更高,弹出栈顶（这些天不可能是答案）
        }
        if (!st.empty()) {
          ans[i] = st.top() - i; //若栈不空，栈顶索引是第一个更高温度的日子 (差值 = 等几天)
        }
        st.push(i);
      }
      return ans;
    }
};

/*
Q:
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
 */