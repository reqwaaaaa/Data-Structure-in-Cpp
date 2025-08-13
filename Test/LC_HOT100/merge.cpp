//
// Created by Naiweilanlan on 25-8-13.
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if (intervals.empty()) return {};
      vector<vector<int>> ans;

      sort(intervals.begin(), intervals.end()); //将 intervals 按起始点（intervals[i][0]）升序排序。如果起始点相同，则按结束点（intervals[i][1]）排序
      ans.push_back(intervals[0]); //将排序后的第一个区间加入 ans 作为初始区间。后续区间将与 ans 的最后一个区间比较，决定是否合并。

      for (int i = 1; i < intervals.size(); i++) {
        vector<int>& last = ans.back(); //获取 ans 的最后一个区间（引用类型，允许直接修改）
        if (last[1] > intervals[i][0]) {
          last[1] = max(last[1], intervals[i][1]);
        }
        else ans.push_back(intervals[i]);
      }
      return ans;
    }

};

/*
Q:
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 */