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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if (nums.size() == 0) return {};

      vector<int> ans;
      deque<int> dq;

      for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); ////所有比当前值小或相等的队尾元素都不可能成为最大值了，被淘汰（出队）。
        dq.push_back(i); //注意存的是索引而非值

        if (dq.front() < i-k+1) dq.pop_front(); //检查队头索引 dq.front() 是否在当前窗口 [i-k+1, i] 之外。如果不在，就移出以保证队列有效。
        if (dq.front() >= k-1) ans.push_back(nums[dq.front()]); //窗口大小为 k，当 i = k - 1 时，第一个完整窗口是 [0, k-1]。后续每次 i 递增，窗口右移，产生新的最大值。
      }
      return ans;
    }
};

/*
Q:
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回每个滑动窗口中的最大值 。

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 */

/*
单调队列（此处是单调递减队列，队头最大，队尾进队头出）
nums[dq.front()] >= nums[dq[1]] >= nums[dq[2]] >= ... >= nums[dq.back()]
队列存储的是索引（int），而不是值，便于跟踪元素的位置和窗口有效性。
队列头部（dq.front()）始终是当前窗口的最大值索引。
 */