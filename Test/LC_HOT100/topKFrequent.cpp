//
// Created by Naiweilanlan on 25-8-28.
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> ans;

      unordered_map<int, int> freq; // 统计出现频率
      for (int num : nums) {
        freq[num]++;
      }
      // 用最小堆维护前K个频率最高的元素，堆中的元素是 pair<频率, 数值>
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
      // 构造&维护
      for (const auto& [num, count] : freq) {
        if (minHeap.size() < k) {
          minHeap.emplace(count, num);  // 频率在前，保证堆顶是频率最小的
        } else if (count > minHeap.top().first) {
          minHeap.pop(); //移除当前最小频率
          minHeap.emplace(count, num); //加上新的
        }
      }

      while (!minHeap.empty()) {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
      }
      return ans;
    }
};

/*
Q:
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

输入：nums = [1,1,1,2,2,3], k = 2
输出：[1,2]
 */