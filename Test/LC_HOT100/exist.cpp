//
// Created by Naiweilanlan on 25-8-22.
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
    bool exist(vector<vector<char>>& board, string word) {
      int rows = board.size();
      int cols = board[0].size();
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          if (dfs(board, word, i, j, 0)) {
            return true;
          }
        }
      }
      return false;
    }
  private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
      if (i < 0 || i >= rows || j < 0 || j >= cols || word[k] != board[i][j]) return false;

      if (k == word.size() - 1) return true;
      board[i][j] = '\0'; // 已访问,避免重复使用
      bool ans = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1); //递归遍历上下左右
      board[i][j] = word[k]; // 还原
      return ans;
    }
};

/*
Q:
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
 */