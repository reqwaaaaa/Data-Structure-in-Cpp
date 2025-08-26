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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();

    // 确保 nums1 是较短的那个
    if (n > m) return findMedianSortedArrays(nums2, nums1);

    int lo = 0, hi = 2 * n;  // 对 nums1 进行二分（加上虚拟位置）

    while (lo <= hi) {
      int c1 = (lo + hi) / 2;
      int c2 = n + m - c1;

      // 计算 LMax 和 RMin，注意处理边界（INT_MIN, INT_MAX）
      int LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2]; //若 c1 == 0（无左部分），设为 INT_MIN
      int RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2]; //若 c1 == 2*n（无右部分），设为 INT_MAX

      int LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
      int RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

      // 进行二分调整
      if (LMax1 > RMin2) {
        hi = c1 - 1;  // 左边太大，往左缩，减少 c1，使 nums1 左部分元素减少（LMax1 变小）
      } else if (LMax2 > RMin1) {
        lo = c1 + 1;  // 左边太小，往右扩，增加 c1，使 nums1 左部分元素增加（RMin1 变大）
      } else {
        // 找到合法划分
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
      }
    }
    return -1; // 理论上不会走到这里
  }
};

/*
Q:
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 */

/*
对 nums1 和 nums2 分别进行分割：
nums1 分割点 c1：左部分有 c1/2 个元素，右部分有 n-c1/2 个。
nums2 分割点 c2：左部分有 c2/2 个元素，右部分有 m-c2/2 个。
总长度 n+m，左右部分平衡：c1/2 + c2/2 ≈ (n+m)/2。
为简化索引，定义虚拟位置：c1 表示 nums1 左部分的虚拟索引（0 到 2*n），c2 = n+m-c1。

中位数：(max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0。

为何 2*n：
每个元素有左右两个分割点（如 nums1[0] 前后），加上数组两端，共有 2*n+1 个虚拟位置。
二分查找范围设为 [0, 2*n]，覆盖所有可能分割点。
整数除法 (c1-1)/2 和 c1/2 将虚拟索引映射到实际元素索引。

合法条件：
LMax1 ≤ RMin2：nums1 左部分最大值 ≤ nums2 右部分最小值。
LMax2 ≤ RMin1：nums2 左部分最大值 ≤ nums1 右部分最小值。
这保证合并数组左半部分所有元素 ≤ 右半部分。
 */