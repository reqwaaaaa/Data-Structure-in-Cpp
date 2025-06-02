//
// Created by Naiweilanlan on 25-5-31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> reshape(int n, int m, vector<pair<int, int>>& fuc, vector<pair<int, int>>& init) {
    // 计算一次函数累加和
    int dx = 0, dy = 0;
    for (int i = 0; i < n; ++i) {
      dx += fuc[i].first;
      dy += fuc[i].second;
    }

    vector<pair<int, int>> res(m);
    for (int i = 0; i < m; ++i) {
      res[i].first = init[i].first + dx;
      res[i].second = init[i].second + dy;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> fuc(n);
  vector<pair<int, int>> init(m);

  for (int i = 0; i < n; i++) {
    cin >> fuc[i].first >> fuc[i].second;
  }

  for (int i = 0; i < m; i++) {
    cin >> init[i].first >> init[i].second;
  }

  Solution sol;
  auto ans = sol.reshape(n, m, fuc, init);

  for (auto& p : ans) {
    cout << p.first << " " << p.second << "\n";
  }

  return 0;
}
