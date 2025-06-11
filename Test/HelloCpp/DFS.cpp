//
// Created by Naiweilanlan on 25-6-11.
//

/*
图的连通分量
岛屿数量（LeetCode 岛屿类题）
全路径遍历（如数独、八皇后）
DFS + 回溯（组合、排列、路径总数）
 */

#include <iostream>
#include <vector>
using namespace std;

int dfs(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    // 边界或访问过/障碍
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == 1)
        return 0;

    visited[x][y] = true;

    int count = 1; // 当前格子

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        count += dfs(x + dx[i], y + dy[i], n, m, grid, visited);
    }
    return count;
}


/*
回溯：

void backtrack(vector<int>& path, int step) {
    if (step == targetStep) {
        // 处理结果
        return;
    }

    for (int i = 0; i < options.size(); ++i) {
        if (used[i]) continue;
        path.push_back(options[i]);
        used[i] = true;

        backtrack(path, step + 1);

        // 回溯：撤销选择
        path.pop_back();
        used[i] = false;
    }
}

 */