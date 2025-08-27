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
    int largestRectangleArea(vector<int> &heights) {
      int n = heights.size();
      int ans = 0;
      vector<int> left(n, -1), right(n, n); //right[n]：默认 n（数组外），表示右侧无更低柱子。left[n]：默认 -1，表示左侧无更低柱子。
      stack<int> st; //存储索引（注意: 这里两个数组和单调栈都是存的索引），维护单调递增

      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
          right[st.top()] = i;
          st.pop();
        }
        st.push(i);
      }

      st = stack<int>(); //清空栈
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
          left[st.top()] = i;
          st.pop();
        }
        st.push(i);
      }

      for (int i = 0; i < n; i++) {
        ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
      }
      return ans;
    }
};

/*
Q:
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此紧紧相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
 */

/*
思路:
对于每个柱子 heights[i]，最大矩形面积由其高度 heights[i] 和可扩展的宽度决定。
宽度由左右第一个比 heights[i] 低的柱子位置（left[i] 和 right[i]）确定。
使用单调递增栈（单调栈保证栈内高度递增，栈顶高度最小）分别从左到右和从右到左遍历，找到每个柱子的左右边界。
计算每个柱子的矩形面积：heights[i] * (right[i] - left[i] - 1)，取最大值。

right[i] 和 left[i] 是第一个高度 严格小于 heights[i] 的柱子索引，不包含在矩形内。
矩形包含的柱子范围是 [left[i] + 1, right[i] - 1]
 */