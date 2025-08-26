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
    int majorityElement(vector<int>& nums) {
      int ans = 0;
      int vote = 0;

      for (int num : nums) {
        if (vote == 0) ans = num; //切换候选人
        vote += num == ans ? 1 : -1; //多数元素出现的次数 > 其他所有元素出现的次数的总和
      }
      return ans; //在抵消过程中，它的票数没有完全被其它数字抵消掉。
    }
};

/*
Q:
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

输入：nums = [2,2,1,1,1,2,2]
输出：2
 */