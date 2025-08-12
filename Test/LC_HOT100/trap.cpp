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
    int trap(vector<int> &height) {
      int ans = 0;
      int n = height.size();
      int left = 0, right = n - 1;
      int lmax = 0, rmax = 0;

      while (left < right) {
        lmax = max(lmax, height[left]);
        rmax = max(rmax, height[right]);

        ans += (lmax < rmax) ? lmax - height[left++] : rmax - height[right--]; //取矮的一边
      }
      return ans;
    }
};

/*
Q（大名鼎鼎的接雨水）：
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 */