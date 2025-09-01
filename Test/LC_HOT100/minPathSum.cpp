//
// Created by Naiweilanlan on 25-9-1.
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
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<int> dp(n, 0);

      dp[0] = grid[0][0];
      for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j]; // 循环 1：初始化第一行
      for (int i = 1; i < m; i++) { // 循环 2：遍历行
        dp[0] += grid[i][0];  // 第一列只能往下
        for (int j = 1; j < n; j++) { // 循环 3：遍历列
          dp[j] = min(dp[j], dp[j - 1] + grid[i][j]);
        }
      }
      return dp[n - 1];
    }
};

/*
Q:
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
 */

/*
动态规划思想：
  状态定义：dp[i][j] 表示从 (0,0) 到 (i,j) 的最小路径和。
  状态转移：
机器人只能从上方 (i-1,j) 或左方 (i,j-1) 到达 (i,j)。
转移方程：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]。
  边界条件：
第一行（i=0）：只能从左向右，dp[0][j] = dp[0][j-1] + grid[0][j]。
第一列（j=0）：只能从上向下，dp[i][0] = dp[i-1][0] + grid[i][0]。
  目标：计算 dp[m-1][n-1]。

空间优化：
观察：计算 dp[i][j] 只依赖上一行 dp[i-1][j] 和当前行前一列 dp[i][j-1]。
使用一维数组 dp：(dp[j] 表示当前行的路径和)
初始化：dp[0] = grid[0][0]，第一行 dp[j] = dp[j-1] + grid[0][j]。
每轮迭代（行 i）：
dp[j] 初始为上一行的 dp[i-1][j]，dp[j-1] 为当前行已更新的 dp[i][j-1]。
结果：dp[n-1] 即 dp[m-1][n-1]。
 */