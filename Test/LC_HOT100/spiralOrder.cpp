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
  private:
    static constexpr int DIR[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //顺时针，故此处方向是‘右、下、左、上’
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      int i = 0; //row
      int j = 0; //col
      int d = 0; //dir
      vector<int> ans;

      for (int k = 0; k< n*m; k++) {
        ans.push_back(matrix[i][j]);
        matrix[i][j] = INT_MAX; //标记为走过
        // 从i、j按照DIR方向出发遍历，注意x、y不是坐标轴方向，而是行/列，同时x、y并不是真的移动，只是用于检测
        int x = i + DIR[d][0];
        int y = j + DIR[d][1];
        if(x<0 || y<0 || x>=n || y>=m || matrix[x][y] == INT_MAX) d = (d+1) % 4; //遇到这几种情况，变换d
        //往后移动i、j
        i += DIR[d][0];
        j += DIR[d][1];
      }
      return ans;
    }
};

/*
Q:
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 */