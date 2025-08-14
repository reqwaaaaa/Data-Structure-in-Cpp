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
    void setZeros(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<int> r(n, 0), c(m, 0); //用于标记需要置0的位置

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (!matrix[i][j]) r[i] = c[j] = 1; //原矩阵中有0，则该位置的行列对应的r、c矩阵标为1，表示该行/列需要被置零
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (r[i] || c[j]) matrix[i][j] = 0; //如果该位置的r、c矩阵有一个1，说明是在0的行/列上
        }
      }
    }
};

/*
Q:
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 */