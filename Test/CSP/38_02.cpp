//
// Created by Naiweilanlan on 25-6-8.
//

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int knightMoveCount(int n, int k, int x, int y) {
    int DIR[8][2] = {
        {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1},
        {1, 2}, {1, -2}, {2, 1}, {2, -1}
    };
    set<pair<int, int>> visited;
    queue<tuple<int, int, int>> q;

    q.push({x, y, 0}); // 初始位置
    visited.insert({x, y});

    while (!q.empty()) {
        auto [cx, cy, steps] = q.front();
        q.pop();

        if (steps == k) continue;

        for (int i = 0; i < 8; ++i) {
            int nx = cx + DIR[i][0];
            int ny = cy + DIR[i][1];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                if (visited.find({nx, ny}) == visited.end()) {
                    visited.insert({nx, ny});
                    q.push({nx, ny, steps + 1});
                }
            }
        }
    }
    return visited.size();
}

int main() {
  int n, k;
  cin >> n >> k;
  int x, y;
  cin >> x >> y;

  cout << knightMoveCount(n, k, x, y) << endl;
}