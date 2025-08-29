//
// Created by Naiweilanlan on 25-8-29.
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
    int canJump2(vector<int>& nums) {
      int jumps = 0;       // 总跳跃次数
      int end = 0;         // 当前跳跃能到达的最大边界
      int farthest = 0;    // 下一跳的最远距离

      for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]); // 不断更新下一跳的最远距离
        // 维护当前覆盖范围 和 下一次覆盖范围
        if (i == end) {
          jumps++;
          end = farthest;
        }
      }
      return jumps;
    }
};

/*
Q:
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：
0 <= j <= nums[i] 且
i + j < n
返回到达 n - 1 的'最小跳跃次数'。测试用例保证可以到达 n - 1。

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 */