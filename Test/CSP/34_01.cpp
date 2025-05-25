//
// Created by Naiweilanlan on 25-5-25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> reshape(int n, int m, int p, int q, vector<vector<int>>& init) {
    if (n * m != p * q) return {}; // 元素数量不一致无法重构

    vector<int> all;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        all.push_back(init[i][j]); // 展平为一维数组
      }
    }

    vector<vector<int>> res(p, vector<int>(q)); // 初始化目标矩阵
    for (int i = 0; i < p * q; i++) {
      res[i / q][i % q] = all[i];
    }

    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, p, q;
  cin >> n >> m >> p >> q;

  vector<vector<int>> init(n, vector<int>(m)); // 现在 n 和 m 有值了

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> init[i][j]; // 正确读取原始矩阵
    }
  }

  Solution sol;
  vector<vector<int>> ans = sol.reshape(n, m, p, q, init);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
