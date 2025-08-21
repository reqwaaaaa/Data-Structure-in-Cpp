//
// Created by Naiweilanlan on 25-8-20.
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
    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty()) return 0;

      int n = grid.size();
      int m = grid[0].size();
      int ans = 0;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == '1') {
            bfs(grid, i, j); //淹掉这块岛
            ans++;
          }
        }
      }
      return ans;
    }
    // BFS 遍历，从 (i, j) 开始，把连在一起的所有 '1' 全部标记为 '0'
    void bfs(vector<vector<char>>& grid, int i, int j) {
      int n = grid.size();
      int m = grid[0].size();
      queue<pair<int, int>> q;
      q.push({i, j});

      while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == '0') continue;
        grid[row][col] = '0';
        // 向四个方向扩展
        q.push({row + 1, col});
        q.push({row - 1, col});
        q.push({row, col + 1});
        q.push({row, col - 1});
      }
    }
};

/*
Q:
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 */