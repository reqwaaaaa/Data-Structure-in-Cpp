//
// Created by Naiweilanlan on 25-8-11.
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
    int maxArea(vector<int> &height) {
      int n = height.size();
      int left = 0, right = n - 1;
      int ans = 0;

      while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        ans = max(ans, area);
        if (height[left] < height[right]) left++;
        else right--;
      }
      return ans;
    }
};

/*
Q：
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
 */