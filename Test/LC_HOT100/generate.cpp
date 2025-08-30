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
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans;
      vector<int> prev;

      for (int i = 0; i < numRows; i++) {
        vector<int> curr(i+1, 1); // 当前行，全部初始化为1
        for (int j = 1; j < i; j++) { // 最左侧是1，所以j从1开始
          curr[j] = prev[j-1] + prev[j]; //逐个计算当前行的元素
        }
        ans.push_back(curr);
        prev = curr; // 当前行变成下一次的上一行
      }
      return ans;
    }
};

/*
Q:
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 */