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
    int findMin(vector<int> &nums) {
      int left = -1, right = nums.size() - 1;
      while (left+1 < right) {
        int mid = left + (right - left) / 2;
        // 普通的二分是和目标数比较，这里是和数组末数比较
        if (nums[mid] < nums.back()) { //mid 在后半部分(旋转后的较小段)
          right = mid; //最小值在 [mid, right)，更新 right = mid
        } else { //mid 在前半部分（较大段）
          left = mid; //最小值在 (left, mid]，更新 left = mid
        }
      }
      return nums[right];
    }
};

/*
Q:
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转(其实就是SHR逻辑右移) 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
 */