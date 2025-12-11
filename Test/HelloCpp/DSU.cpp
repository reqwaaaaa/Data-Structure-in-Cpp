//
// Created by Naiweilanlan on 25-12-11.
//

#include <iostream>
#include <queue>
#include <set>

using namespace std;

/*
========================================================
=                Disjoint Set Union (DSU)
=  - 路径压缩 + 按大小（size）合并
=  - unite() 返回是否成功合并（用于判断回路）
=  - 支持统计当前连通分量数量 components
========================================================
*/
class DSU {
private:
    int n;                      // 节点数量
    vector<int> parent;         // 父节点
    vector<int> sz;             // 每个根的子树规模
    int components;             // 当前连通分量数量

public:
    DSU(int n = 0) { init(n); }

    /* 初始化，并将所有节点置为单独集合 */
    void init(int n_) {
        n = n_;
        parent.resize(n);
        sz.assign(n, 1);
        components = n;
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    /* 路径压缩 find：尽量缩短树高，使后续查询接近 O(1) */
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    /*
        unite(a, b):
        - 若 a、b 原本不在同一集合，则合并并返回 true
        - 若 a、b 已连通，则返回 false（用于判断是否产生回路）
    */
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        // 让规模小的树挂到规模大的树上
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        components--;
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int count_components() const {
        return components;
    }
};

/*
========================================================
=               图相关算法工具类 GraphUtils
=   功能封装：
=   - 判断连通分量数量
=   - 判断无向图是否存在回路
=   - 判定无向图是否为树
=   - Kruskal 算法求最小生成树
========================================================
*/
class GraphUtils {
public:

    /* 判断图的连通分量数量 */
    static int countConnectedComponents(int n, const vector<pair<int,int>>& edges) {
        DSU dsu(n);
        for (auto &e : edges) dsu.unite(e.first, e.second);
        return dsu.count_components();
    }

    /* 无向图回路检测 —— 若 unite() 返回 false，则产生了环 */
    static bool hasCycleUndirected(int n, const vector<pair<int,int>>& edges) {
        DSU dsu(n);
        for (auto &e : edges) {
            if (!dsu.unite(e.first, e.second))
                return true;    // 两端点原本就连通 → 产生回路
        }
        return false;
    }

    /* 判断是否为树（无向图）：
        必要且充分条件：
        1. 边数 = n - 1
        2. 图无回路（合并时没有冲突） → 或者最终 components == 1
    */
    static bool isTree(int n, const vector<pair<int,int>>& edges) {
        if ((int)edges.size() != n - 1) return false;

        DSU dsu(n);
        for (auto &e : edges) {
            if (!dsu.unite(e.first, e.second))
                return false;    // 出现回路 → 不是树
        }
        return dsu.count_components() == 1;
    }

    /*
        Kruskal 求最小生成树
        - 输入：n 节点数，带权边 {u,v,w}
        - 输出：pair(最小权重和, MST边集)
        - 若图不连通 → 返回 {-1, {}}
    */
    struct Edge {
        int u, v;
        long long w;
    };

    static pair<long long, vector<Edge>>
    kruskalMST(int n, vector<Edge> edges) {
        sort(edges.begin(), edges.end(),
             [](const Edge &a, const Edge &b){ return a.w < b.w; });

        DSU dsu(n);
        long long total = 0;
        vector<Edge> mst;

        for (auto &e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mst.push_back(e);
                total += e.w;
                if ((int)mst.size() == n - 1) break;
            }
        }

        if ((int)mst.size() != n - 1)
            return {-1, {}};  // 不连通，无法形成 MST

        return {total, mst};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== 并查集应用测试 =====\n";

    /* 测试 1：连通分量 */
    vector<pair<int,int>> edges1 = {{0,1},{1,2},{3,4}};
    cout << "连通分量数量: "
         << GraphUtils::countConnectedComponents(5, edges1)
         << "\n\n";

    /* 测试 2：回路检测 */
    vector<pair<int,int>> edges2 = {{0,1},{1,2},{2,0}};
    cout << "图是否有回路: "
         << (GraphUtils::hasCycleUndirected(3, edges2) ? "有" : "无")
         << "\n\n";

    /* 测试 3：是否为树 */
    vector<pair<int,int>> edges3 = {{0,1},{1,2},{2,3},{3,4}};
    cout << "是否是树: "
         << (GraphUtils::isTree(5, edges3) ? "是" : "否")
         << "\n\n";

    /* 测试 4：Kruskal 求 MST */
    vector<GraphUtils::Edge> wedges = {
        {0,1,4},{1,2,8},{2,3,7},{3,4,9},{4,5,10},{2,5,4},{2,6,2},{5,6,6}
    };
    auto res = GraphUtils::kruskalMST(7, wedges);

    if (res.first == -1)
        cout << "MST 不存在（图不连通）\n";
    else {
        cout << "MST 总权重 = " << res.first << "\n边如下：\n";
        for (auto &e : res.second) {
            cout << e.u << " - " << e.v << " (w=" << e.w << ")\n";
        }
    }

    return 0;
}
