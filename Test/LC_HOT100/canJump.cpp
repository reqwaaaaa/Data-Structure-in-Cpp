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
    bool canJump(vector<int> &nums) {
      int cover = 0; //从起始位置开始，通过跳跃能到达的最远位置
      for (int i = 0; i < nums.size() - 1 && i <= cover; i++) {
        cover = max(cover, i + nums[i]); //每一步选择能跳到的最远距离
      }
      return cover >= nums.size() - 1; //只要 cover 能覆盖最后一个位置（nums.size() - 1），返回 true
    }
};

/*
Q:
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标

输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标
 */