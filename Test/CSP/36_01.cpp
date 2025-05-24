//
// Created by Naiweilanlan on 25-5-24.
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
#include <utility>

using namespace std;

class Solution {
public:
    int DIR[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}; //f、b、l 和 r
    struct point{
      int x;
      int y;
      point(int _x, int _y):x(_x),y(_y){}
      };

  void loc(int& x, int& y, int n, string operation) {
    for (char op : operation) {
      int new_x = x, new_y = y;
      if (op == 'f') { // 右
        new_x += DIR[0][0];
        new_y += DIR[0][1];
      } else if (op == 'b') { // 左
        new_x += DIR[1][0];
        new_y += DIR[1][1];
      } else if (op == 'l') { // 上
        new_x += DIR[2][0];
        new_y += DIR[2][1];
      } else if (op == 'r') { // 下
        new_x += DIR[3][0];
        new_y += DIR[3][1];
      }
      // 检查边界
      if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n) {
        x = new_x;
        y = new_y;
      }
    }
  }
    // 题目要求的返回值类型 和方法名
    // 根据题目定义参数
    // 示例: vector<int> twoSum(vector<int>& nums, int target) {
    //     // 实现算法逻辑
    //     return result; // 返回结果
    // }
};

int main() {
    // IO优化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,x,y;
    string operation;
    cin>>n>>k;

    vector<tuple<int, int, string>> queries;
      for (int i = 0; i < k; i++) {
        cin >> x >> y >> operation;
        queries.emplace_back(x, y, operation);
    }

    Solution sol;
    for (auto [x, y, op] : queries) {
      sol.loc(x, y, n, op);
      cout << x << " " << y << endl;
    }
    // 调用方法，获取结果
    // 示例: auto result = sol.twoSum(nums, target);

    // 输出结果，根据题目要求
    // 示例: for(int x : result) cout << x << " "; cout << endl;

    return 0;
}
