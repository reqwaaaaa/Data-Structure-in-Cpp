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
    void moveZeroset(vector<int> &nums) {
      int n = nums.size();
      int left = 0, right = 0; //left 跟踪非零元素的目标位置; right 负责遍历整个数组，寻找非零元素。
      while (right < n) { //将非零元素逐步移到数组前面，0 自然被挤到后面
        if (nums[right]) {
          swap(nums[left], nums[right]); //遇到非零元素就交换并让left指向下一个非零元素的目标位置
          left++;
        }
        right++;
      }
    }
};

/*
Q:给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 */

/*
left 最终指向最后一个非零元素之后的位置，数组从 [0, left) 都是非零元素
剩余部分 [left, n) 默认被 0 填充（因为非零元素被移走后，0 留在了后面）
 */