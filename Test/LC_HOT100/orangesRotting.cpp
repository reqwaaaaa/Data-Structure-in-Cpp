//
// Created by Naiweilanlan on 25-8-21.
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
    int orangesRotting(vector<vector<int>>& grid) {
      vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //方向数组：右、左、下、上
      queue<pair<int, int>> q;
      int n = grid.size();
      int m = grid[0].size();
      int ans = 0;
      int fresh = 0;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 2) {
            q.push({i, j}); //将腐烂橘子坐标 (i,j) 加入队列
          } else if (grid[i][j] == 1) {
            fresh++; //新鲜橘子计数++
          }
        }
      }
      //使用 BFS 模拟腐烂扩散，每层代表一分钟
      while (!q.empty() && fresh > 0) {
        int size = q.size(); //记录当前层的腐烂橘子数量
        for (int i = 0; i < size; i++) { //遍历当前层每个腐烂橘子
          auto [x, y] = q.front();
          q.pop();
          for (auto [dx, dy] : d) { //四个方向
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
              grid[nx][ny] = 2;
              fresh--;
              q.push({nx, ny}); //将新腐烂橘子加入队列
            }
          }
        }
        ans++;
      }
      return fresh == 0 ? ans : -1; //如果没法腐烂到所有橘子就返回-1
    }
};

/*
Q:
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4

输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。

输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 */