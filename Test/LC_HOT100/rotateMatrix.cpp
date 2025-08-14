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
  void rotate(vector<vector<int>>& matrix) {
    n = matrix.size();

    // 上下对称 + 主对角线对称
    upDownSymmetry(matrix);
    mainDiagSymmetry(matrix);

    // 主对角线对称 + 左右对称
    // mainDiagSymmetry(matrix);
    // leftRightSymmetry(matrix);

    // 左右对称 + 副对角线对称
    // leftRightSymmetry(matrix);
    // subdiagSymmetry(matrix);

    // 副对角线对称 + 上下对称
    // subdiagSymmetry(matrix);
    // upDownSymmetry(matrix);
  }

private:
  int n;

  // 上下对称
  void upDownSymmetry(vector<vector<int>>& matrix) {
    for (int i = 0; i < n/2; ++i) {
      for (int j = 0; j < n; ++j) {
        swap(matrix[i][j], matrix[n-i-1][j]);
      }
    }
  }

  // 左右对称
  void leftRightSymmetry(vector<vector<int>>& matrix) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n/2; ++j) {
        swap(matrix[i][j], matrix[i][n-j-1]);
      }
    }
  }

  // 主对角线对称
  void mainDiagSymmetry(vector<vector<int>>& matrix) {
    for (int i = 0; i < n-1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }

  // 副对角线对称
  void subdiagSymmetry(vector<vector<int>>& matrix) {
    for (int i = 0; i < n-1; ++i) {
      for (int j = 0; j < n-i-1; ++j) {
        swap(matrix[i][j], matrix[n-j-1][n-i-1]);
      }
    }
  }
};

/*
Q:
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 */

/*
上下对称：matrix[i][j] -> matrix[n-i-1][j]，（列不变）
左右对称：matrix[i][j] -> matrix[i][n-j-1]，（行不变）
主对角线对称：matrix[i][j] -> matrix[j][i]，（行列互换）
副对角线对称：matrix[i][j] -> matrix[n-j-1][n-i-1] （行列均变，且互换）
*/