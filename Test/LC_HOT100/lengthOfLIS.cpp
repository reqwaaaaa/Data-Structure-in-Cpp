//
// Created by Naiweilanlan on 25-8-30.
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
    int lengthOfLIS(vector<int> &nums) {
      vector<int> tails;

      for (int num : nums) {
        int left = 0, right = tails.size();
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (tails[mid] < num) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }

        if (tails.size() == left) {
          tails.push_back(num);
        } else {
          tails[left] = num;
        }
      }
      return tails.size();
    }
};

/*
Q:
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。(子序列不用连续，子串需要连续)
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 */

/*
贪心 + 二分查找思想：
贪心策略：为了使递增子序列尽可能长，维护一个数组 tails，其中 tails[i] 表示长度为 i+1 的递增子序列的最小尾部值。(例如，tails[0] 是长度为 1 的子序列的最小末尾值)
保持尾部值最小，以便后续元素更容易接上，形成更长的子序列。(对于 [2,5] 和 [2,10]（长度都是 2），我们选择 [2,5]，因为 5 比 10 小，后续元素（如 7）更容易接在 5 后面)
二分查找：对于每个 num，在 tails 中找到第一个大于或等于 num 的位置（left），将 num 插入或替换该位置的值：
如果 left == tails.size()，说明 num 比所有尾部值大，扩展 tails（增加子序列长度）。
否则，更新 tails[left] = num，保持长度 left+1 的子序列尾部最小。
 */