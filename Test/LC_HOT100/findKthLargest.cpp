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
    int findKthLargest(vector<int>& nums, int k) {
      vector<int> now(nums.begin(), nums.begin() + k); // 取nums前k个元素
      int n = nums.size();
      buildHeap(now, k); // 构建包含k个元素的最小堆
      for (int i = k; i < k; i++) {
        if (nums[i] > now[0]) {
          now[0] = nums[i];
          minHeapify(now, 0, k); // 有比堆顶更大的数就交换后调整堆
        }
      }
      return now[0];  // 堆顶元素就是第k大元素
    }

    // 调整最小堆
    void minHeapify(vector<int>& a, int i, int heapsize) {
      int smallest = i, l = 2*i + 1, r = 2*i + 2;
      if (l < heapsize && a[l] < a[smallest]) smallest = l; // 如果左子节点更小，则更新最小值
      if (r < heapsize && a[r] < a[smallest]) smallest = r; // 右子节点同理
      if (smallest != i) { // 最小值发生变动，交换 a[i] 和 a[smallest]，递归调整子树
        swap(a[i], a[smallest]);
        minHeapify(a, smallest, heapsize);
      }
    }

    // 构建最小堆
    void buildHeap(vector<int>& a, int heapsize) {
      for (int i = heapsize/2 - 1; i >= 0; i--) {
        minHeapify(a, i, heapsize); // 自底向上构建最小堆
      }
    }
};

/*
Q:
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

输入: [3,2,1,5,6,4], k = 2
输出: 5

输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
解释: 第二以及第三大的元素都是‘5’
 */

/*
使用一个大小为 k 的 最小堆 维护 nums 中最大的 k 个元素，堆顶是这 k 个元素中最小的（即第 K 大元素）
取 nums 前 k 个元素，构建最小堆（buildMinHeap）。
遍历剩余元素（nums[k] 到 nums[n-1]）：
若当前元素 nums[i] > 堆顶，替换堆顶并调整堆（minHeapify）。
返回堆顶即为第 K 大元素。
 */