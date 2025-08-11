//
// Created by Naiweilanlan on 25-8-11.
//
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> a; // 表a存的是下标
    vector<int> b(2, 0); // 用于记录返回的下标对

    for (int i = 0; i < nums.size(); i++) {
      if (a.count(target - nums[i]) > 0) {
        b[0] = a[target - nums[i]];
        b[1] = i;
      }
      else {
        a[nums[i]] = i; // 记录当前没有出现过的值的下标
      }
    }
    return b;
  }
};