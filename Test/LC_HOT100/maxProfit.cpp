//
// Created by Naiweilanlan on 25-8-28.
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

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      int cost = INT_MAX;
      int profit = 0;

      for (int price : prices) {
        cost = min(cost, price);
        profit = max(profit, price - cost);
      }
      return profit;
    }
};

/*
Q:
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 */

/*
贪心：
每一步只关心当前的最优选择（最低买入价和最大利润），不回溯之前的决策。
对于每一天的价格 price，假设在历史最低价格 cost 买入，在当前价格卖出，计算可能的利润 price - cost。
维护历史最低价格 cost（贪心地选择最小的买入点）。
维护最大利润 profit（贪心地选择最大的卖出利润）。
 */