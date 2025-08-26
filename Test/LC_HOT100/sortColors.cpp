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
    void sortColors(vector<int>& nums) {
      int i = 0;
      int p0 = 0, p2 = nums.size() - 1;

      while (i <= p2) {
        if (nums[i] == 0) {
          swap(nums[i], nums[p0]);
          p0++;
          i++;
        } else if (nums[i] == 2) {
          swap(nums[i], nums[p2]);
          p2--; // 注意：i 不++，因为换过来的可能是 0 或 2
        } else {
          i++; // 中间值‘1’不需要移动
        }
      }
    }
};

/*
Q:
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
 */