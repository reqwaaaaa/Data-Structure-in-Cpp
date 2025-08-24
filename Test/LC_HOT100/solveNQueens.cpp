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
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n, string(n, '.')); // 初始化棋盘,记录当前皇后放置
      vector<bool> col(n, false);              // 某列是否有皇后
      vector<bool> diag1(2 * n - 1, false);     // 主对角线（行 + 列）
      vector<bool> diag2(2 * n - 1, false);     // 副对角线（行 - 列 + n - 1）

      auto backtrack = [&](this auto&& backtrack, int row) { //以行（row）为‘k’进行放置，递归
        if (row == n) {
          res.push_back(board); // 找到一个解
          return;
        }
        for (int j = 0; j < n; ++j) {
          if (col[j] || diag1[row + j] || diag2[row - j + n - 1]) continue; // 剪枝
          // 放置皇后
          board[row][j] = 'Q';
          col[j] = diag1[row + j] = diag2[row - j + n - 1] = true;
          // 递归处理下一行
          backtrack(row + 1);
          // 回溯，撤销选择
          board[row][j] = '.';
          col[j] = diag1[row + j] = diag2[row - j + n - 1] = false;
        }
      };
      backtrack(0);
      return ans;
    }
};

/*
Q:
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 */