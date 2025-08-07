//
// Created by Naiweilanlan on 25-6-8.
//

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;  // 每个元素的父节点
    vector<int> rank;    // 树的“秩”（高度的近似）

public:
    // 初始化：每个节点的父节点是自己，秩为1
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // 查找根节点，带路径压缩优化
    /*
    路径压缩：在查找根节点时，将沿途的所有节点直接挂到根上，降低之后查找的树高。
    调用 find(5) 后：
    5 → 0
    4 → 0
    ...
    压缩后整个链变平，几乎变成“星形结构”，后续查询效率接近 O(1)。
     */
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // 路径压缩
        return parent[x];
    }

    // 合并两个集合，按秩合并优化
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false; // 已经连通，无需合并

        // 小树挂大树，保持树平衡
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++; // 只有秩相同时才增加
        }
        return true;
    }

    // 判断两个节点是否在同一个集合中
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// 测试函数
void testUnionFind() {
    UnionFind uf(10); // 初始化10个元素

    cout << "Union(1, 2)" << endl;
    uf.unite(1, 2);
    cout << "Union(2, 3)" << endl;
    uf.unite(2, 3);
    cout << "Union(4, 5)" << endl;
    uf.unite(4, 5);
    cout << "Union(6, 7)" << endl;
    uf.unite(6, 7);
    cout << "Union(5, 6)" << endl;
    uf.unite(5, 6);

    cout << "\nConnected(1, 3): " << uf.connected(1, 3) << endl; // true
    cout << "Connected(1, 4): " << uf.connected(1, 4) << endl; // false
    cout << "Connected(4, 7): " << uf.connected(4, 7) << endl; // true

    cout << "\nUnion(3, 4)" << endl;
    uf.unite(3, 4);

    cout << "Connected(1, 7): " << uf.connected(1, 7) << endl; // true
}

int main() {
    testUnionFind();
    return 0;
}
