//
// Created by Naiweilanlan on 25-8-14.
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
    bool searchMatrix(vector<vector<int>>&matrix, int target) {
      // 从矩阵左下角开始遍历,类似BST
      int i = matrix.size() - 1;
      int j = 0;
      if (i >= 0 && j < matrix[0].size()) {
        if (matrix[i][j] < target) j++; //小了加列（左到右升序）
        else if (matrix[i][j] > target) i--; //大了减行（上到下升序）
        else return true;
      }
      return false;
    }
};

/*
Q:
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
 */