//
// Created by Naiweilanlan on 25-6-12.
//

/*
算法	用途	图类型	适用场景	复杂度
Prim	最小生成树（MST）	无向图	稠密图 MST	O(n²) / O(ElogV)
Kruskal	最小生成树（MST）	无向图	稀疏图 MST	O(ElogE)
Dijkstra	单源最短路径	有向/无向图（无负权）	正权图中的最短路径	O(ElogV)
Floyd	全源最短路径	有向图（允许负边无负环）	多源最短路	O(n³)
拓扑排序	有向无环图 DAG 的排序	有向图	优先级依赖问题/关键路径	O(V+E)
关键路径	项目调度中找最长路径	DAG（有权）	AOE 网络分析、项目管理	O(V+E)
 */

/*
如果关键路径上的活动：
  延长工作时间 → 会直接推迟整个项目工期，等于“瓶颈”。
  缩短工作时间 → 有可能缩短项目总工期，前提是你缩短的是最长路径上的任务。
非关键路径上的活动：
  延长：只要不超过它的“自由时间/松弛时间”，不会影响总工期。
  缩短：不会影响总工期，除非新路径变成了最长路径。
 */

/*
判断目标	可选算法
图中有无环	拓扑排序（有向图）、并查集（无向图）
单源最短路径	Dijkstra（无负边）、Bellman、SPFA
所有点对最短路	Floyd
最长路径（DAG）	拓扑排序 + 关键路径
项目调度	关键路径（CPM）
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <limits>
#include <set>

using namespace std;
const int INF = 1e9;
// prim
int prim(int n, vector<vector<int>>& graph) {
 vector<int> dist(n, INF); // 到 MST 的最短边权
 vector<bool> inMST(n, false);
 dist[0] = 0;

 int total = 0;

 for (int i = 0; i < n; ++i) {
  int u = -1, minD = INF;
  for (int j = 0; j < n; ++j)
   if (!inMST[j] && dist[j] < minD)
    minD = dist[u = j];

  if (u == -1) return -1; // 不连通

  inMST[u] = true;
  total += dist[u];

  for (int v = 0; v < n; ++v)
   if (!inMST[v] && graph[u][v] < dist[v])
    dist[v] = graph[u][v];
 }

 return total;
}
// kruskal
struct Edge {
 int u, v, w;
 bool operator<(const Edge& e) const { return w < e.w; }
};

int find(int x, vector<int>& fa) {
 return fa[x] == x ? x : fa[x] = find(fa[x], fa);
}

int kruskal(int n, vector<Edge>& edges) {
 sort(edges.begin(), edges.end());
 vector<int> fa(n);
 for (int i = 0; i < n; ++i) fa[i] = i;

 int total = 0, count = 0;
 for (auto e : edges) {
  int fx = find(e.u, fa), fy = find(e.v, fa);
  if (fx != fy) {
   fa[fx] = fy;
   total += e.w;
   count++;
   if (count == n - 1) break;
  }
 }
 return (count == n - 1) ? total : -1; // 不连通
}
// dijkstra
vector<int> dijkstra(int n, int start, vector<vector<pair<int, int>>>& adj) {
 vector<int> dist(n, INF);
 dist[start] = 0;
 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
 pq.push({0, start});

 while (!pq.empty()) {
  auto [d, u] = pq.top(); pq.pop();
  if (d > dist[u]) continue;
  for (auto [v, w] : adj[u]) {
   if (dist[u] + w < dist[v]) {
    dist[v] = dist[u] + w;
    pq.push({dist[v], v});
   }
  }
 }
 return dist;
}
// floyd
void floyd(int n, vector<vector<int>>& dist) {
 for (int k = 0; k < n; ++k)
  for (int i = 0; i < n; ++i)
   for (int j = 0; j < n; ++j)
    if (dist[i][k] < INF && dist[k][j] < INF)
     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
// 拓扑排序
vector<int> topo_sort(int n, vector<vector<int>>& adj) {
 vector<int> indegree(n, 0);
 for (int u = 0; u < n; ++u)
  for (int v : adj[u])
   indegree[v]++;

 queue<int> q;
 for (int i = 0; i < n; ++i)
  if (indegree[i] == 0)
   q.push(i);

 vector<int> order;
 while (!q.empty()) {
  int u = q.front(); q.pop();
  order.push_back(u);
  for (int v : adj[u])
   if (--indegree[v] == 0)
    q.push(v);
 }

 return (order.size() == n) ? order : vector<int>{}; // 若不是 n 个点，说明有环
}
// 关键路径
void critical_path(int n, vector<vector<pair<int, int>>>& adj) {
 vector<int> indegree(n, 0), ve(n, 0);
 for (int u = 0; u < n; ++u)
  for (auto [v, w] : adj[u])
   indegree[v]++;

 queue<int> q;
 vector<int> topo;

 for (int i = 0; i < n; ++i)
  if (indegree[i] == 0) q.push(i);

 while (!q.empty()) {
  int u = q.front(); q.pop();
  topo.push_back(u);
  for (auto [v, w] : adj[u]) {
   if (--indegree[v] == 0) q.push(v);
   ve[v] = max(ve[v], ve[u] + w);
  }
 }

 vector<int> vl = ve;
 reverse(topo.begin(), topo.end());

 for (int u : topo) {
  for (auto [v, w] : adj[u]) {
   vl[u] = min(vl[u], vl[v] - w);
  }
 }

 cout << "关键活动边:\n";
 for (int u = 0; u < n; ++u)
  for (auto [v, w] : adj[u]) {
   int e = ve[u], l = vl[v] - w;
   if (e == l)
    cout << u << " -> " << v << " 是关键路径边，持续时间: " << w << '\n';
  }
}
// 主函数
int main() {

}