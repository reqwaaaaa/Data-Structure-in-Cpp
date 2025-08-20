//
// Created by Naiweilanlan on 25-8-19.
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

// 定义二叉树结点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long,int> cnt{{0,1}}; //键为路径前缀和，值为该前缀和出现的次数，初始化 cnt[0] = 1（空路径和为 0）
        // Lambda 函数实现 DFS，简化递归定义
        auto dfs = [&](this auto&& dfs,TreeNode* node,long long s) {
            if(node == nullptr) return;
            s += node->val; //从根到当前节点（包括当前节点）的路径前缀和
            ans += cnt.count(s - targetSum) ? cnt[s - targetSum] : 0; //如果存在前缀和 s' = s - targetSum，则路径 [s', s] 的和为 (s - s') = targetSum；cnt[s - targetSum] 是此前缀和出现的次数，即路径数
            cnt[s]++;
            dfs(node->left,s);
            dfs(node->right,s);
            cnt[s]--; //当前路径前缀和 s 只对当前子树有效，离开当前节点后需撤销（回溯）
        };
        dfs(root,0);
        return ans;
    }
};

/*
Q:
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条
 */