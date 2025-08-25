//
// Created by Naiweilanlan on 25-8-24.
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();
      int m = matrix[0].size();
      int left = -1;
      int right = n * m; //将矩阵视为一维数组，范围 [0, m*n-1]
      while (left + 1 < right) { //确保左右指针不重叠，找到精确位置
        int mid = left + (right - left) / 2;
        int x = matrix[mid / m][mid % m]; //整除得行号,取余得列号
        if (x == target) {
          return true;
        }
        (x < target ? left : right) = mid;
      }
      return false;
    }
};

/*
Q:
给你一个满足下述两条属性的 m x n 整数矩阵：
1、每行中的整数从左到右按非严格递增顺序排列。
2、每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
 */