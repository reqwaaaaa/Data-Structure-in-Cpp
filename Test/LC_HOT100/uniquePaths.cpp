//
// Created by Naiweilanlan on 25-8-31.
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
    int uniquePaths(int m, int n) {
      vector<int> cur(n, 1);

      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          cur[j] += cur[j - 1];
        }
      }
      return cur[n - 1];
    }
};

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？

输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
 */

/*
动态规划思想：
  状态定义：dp[i][j] 表示从 (0,0) 到 (i,j) 的不同路径数。
  状态转移：
机器人只能向右或向下移动，到达 (i,j) 的路径来自：
从上方 (i-1,j) 向下：dp[i-1][j]。
从左方 (i,j-1) 向右：dp[i][j-1]。
转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]。
  边界条件：
第一行（i = 0）：只能从左向右，dp[0][j] = 1。
第一列（j = 0）：只能从上向下，dp[i][0] = 1。
  目标：计算 dp[m-1][n-1]。

空间优化：
观察：计算 dp[i][j] 只依赖上一行 dp[i-1][j] 和当前行的前一列 dp[i][j-1]。
使用一维数组 cur[j] 表示到达 当前行 的路径数：
初始化：cur[j] = 1（第一行全为 1）。
每轮迭代（行 i）：
进入内层循环前，cur[j] 保存的是上一行的值，即 dp[i-1][j]。
在内层循环中，cur[j] 被更新为当前行的值 dp[i][j]。
cur[j] 初始为上一行的 dp[i-1][j]。
cur[j-1] 是当前行已更新的 dp[i][j-1]。
更新：cur[j] += cur[j-1]，等价于 dp[i][j] = dp[i-1][j] + dp[i][j-1]。
结果：cur[n-1] 即 dp[m-1][n-1]。
 */