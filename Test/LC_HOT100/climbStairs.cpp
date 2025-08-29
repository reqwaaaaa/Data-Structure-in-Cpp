//
// Created by Naiweilanlan on 25-8-29.
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
    int climbStairs(int n) {
        int a = 1; // f(n-2)，表示爬到第 n-2 级的方法数
        int b = 1; // f(n-1)，表示爬到第 n-1 级的方法数
        int sum;   // f(n)，当前级的方法数
        for (int i = 0; i < n-1; i++) {
            sum = a + b; // f(n) = f(n-1) + f(n-2)
            a = b;       // f(n-2) 更新为 f(n-1)
            b = sum;     // f(n-1) 更新为 f(n)
        }
        return b; // 返回 f(n)，注意返回b而不是sum，sum只是临时变量
    }
};

/*
Q:
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
 */

/*
动态规划思想：
爬到第 n 级的方法数 f(n) 等于：
从第 n-1 级爬 1 级：f(n-1)。
从第 n-2 级爬 2 级：f(n-2)。
因此，状态转移方程：f(n) = f(n-1) + f(n-2)。
初始条件：f(1) = 1（1 级只有 1 种方法），f(2) = 2（2 级有 2 种方法）。
 */