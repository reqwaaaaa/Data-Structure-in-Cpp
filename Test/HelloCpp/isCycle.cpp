//
// Created by Naiweilanlan on 25-6-11.
//

#include <iostream>
#include <vector>
using namespace std;

// ---------- DFS 判连通 ----------
void dfs_connected(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs_connected(v, adj, visited);
    }
}

// ---------- DFS 判有向图是否有环 ----------
bool dfs_cycle(int u, vector<vector<int>>& adj, vector<int>& state) {
    state[u] = 1; // 标记为访问中

    for (int v : adj[u]) {
        if (state[v] == 0) {
            if (dfs_cycle(v, adj, state)) return true;
        } else if (state[v] == 1) {
            // 遇到访问中的点，说明有环
            return true;
        }
    }

    state[u] = 2; // 离开节点
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // 顶点数、边数
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // 有向图：u -> v
    }

    // 1. 检查是否从 0 出发能访问所有节点（弱连通）
    vector<bool> visited(n, false);
    dfs_connected(0, adj, visited);
    bool isConnected = true;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            isConnected = false;
            break;
        }
    }

    // 2. 检查图中是否存在有向环
    vector<int> state(n, 0); // 0=未访问，1=访问中，2=访问完
    bool hasCycle = false;
    for (int i = 0; i < n; ++i) {
        if (state[i] == 0) {
            if (dfs_cycle(i, adj, state)) {
                hasCycle = true;
                break;
            }
        }
    }

    // 输出结果
    cout << "From node 0, all nodes reachable? " << (isConnected ? "YES" : "NO") << "\n";
    cout << "Does the graph contain a cycle? " << (hasCycle ? "YES" : "NO") << "\n";

    return 0;
}