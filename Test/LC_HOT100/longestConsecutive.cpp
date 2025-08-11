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
    int longestConsecutive(vector<int> &nums) {
      int ans = 0;
      unordered_set<int> set(nums.begin(), nums.end()); //输入的数组 nums 转换为一个无序集合以去除重复元素，并支持 O(1) 平均时间复杂度的查找操作。
      for (auto x : set) {
        if (set.contains(x - 1)) { //避免了对非起点的数字进行冗余计算，只处理可能是序列开头的数字
          continue;
        }
        int y = x + 1;
        while (set.contains(y)) {
          y++;
        }
        ans = max(ans, y - x);
      }
      return ans;
    }
};

/*
Q:给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 */

/*
哈希集合允许以常数时间检查某个数字是否在集合中（通过 hashset.contains()）
hashset.contains(x-1) 替换为 hashset.find(x-1) != hashset.end() 是等效的
 */