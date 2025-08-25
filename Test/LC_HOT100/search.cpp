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
    int search(vector<int>& nums, int target) {
      int end = nums.back();
      //判断索引 i 的元素是否可能包含 target
      auto check = [&](this auto&& check, int i) {
        int x = nums[i];
        if (x > end) { //x 在旋转数组的前半部分，值较大
          return target >= end && x >= target; //target 必须也在前半部分（target > end）且 x >= target（因为前半部分升序，需向左搜索）
        } else return x >= target || target > end; //x 在后半部分，值较小;target 可能在后半部分, 也可能在前半部分, 且 x 是候选解
      };
      //二分查找主体
      int left = -1,right = nums.size() - 1;
      while(left + 1 < right) {
        int mid = left + (right - left)/2;
        if(check(mid)) {
          right = mid;
        } else {
          left = mid;
        }
      }
      return nums[right] == target ? right : -1;
    }
};

/*
Q:
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 下标 3 上向左旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
 */

/*
Q:
旋转点处理：
数组旋转后形如 [4,5,6,7,0,1,2]，end = 2，前半部分 [4,5,6,7] > end，后半部分 [0,1,2] ≤ end。
check 判断 nums[mid] 和 target 是否在同一段，指导折半。
 */