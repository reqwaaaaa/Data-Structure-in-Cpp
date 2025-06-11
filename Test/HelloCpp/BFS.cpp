//
// Created by Naiweilanlan on 25-6-11.
//

/*
最短路径（如迷宫）
层级问题（如感染、信号扩散）
多源 BFS（多个起点同时搜索）
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// 可传入坐标、编号、状态等作为节点表示
struct Node {
    int x, y;
    int step;
};

int bfs(int startX, int startY, int n, int m, vector<vector<int>>& grid) {
    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        // 终点判定
        if (grid[cur.x][cur.y] == 9) return cur.step;

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 判边界 + 障碍 + 去重
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] && grid[nx][ny] != 1) {
                visited[nx][ny] = true;
                q.push({nx, ny, cur.step + 1});
                }
        }
    }
    return -1; // 无法到达
}
