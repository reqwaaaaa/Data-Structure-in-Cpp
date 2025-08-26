//
// Created by Naiweilanlan on 25-8-26.
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
    int findDuplicate(vector<int> &nums) {
      int slow = 0, fast = 0;
      while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (fast == slow) break;
      }
      int finder = 0;
      while (true) {
        slow = nums[slow];
        finder = nums[finder];
        if (slow == finder) break;
      }
      return finder;
    }
};

/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

输入：nums = [1,3,4,2,2]
输出：2
 */

/*
核心思想：
将数组视为一个 有向图，索引 i 指向值 nums[i]，形成一个 有环链表。
重复数字导致环的存在（如 nums[i] = nums[j] = k，指向相同节点 k）。
使用 Floyd 判圈算法（快慢指针）找到环的入口，即重复数字。

找环内相遇点：
快指针：fast = nums[nums[fast]]（两步）。
慢指针：slow = nums[slow]（一步）。
当 fast == slow，找到环内相遇点。

找环入口：
重置 finder = 0，从起点和相遇点各走一步。
当 finder == slow，找到环入口，即重复数字。
 */