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
    int singleNumber(vector<int>& nums) {
      int ans = 0;
      for (int num : nums) {
        ans ^= num; //XOR
      }
      return ans;
    }
};

/*
Q:
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

输入：nums = [4,1,2,1,2]
输出：4
 */

/*
数组中每个数字（除一个外）出现两次，成对的数字异或后为 0：a ^ a = 0。
所有成对数字异或结果为 0，只出现一次的数字（设为 s）与 0 异或：s ^ 0 = s。
因此，整个数组异或的结果是只出现一次的数字。
 */