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
    int kthSmallest(TreeNode* root, int k) {
      this->k = k;
      dfs(root);
      return ans;
    }

    int ans, k;
    void dfs(TreeNode* root) { //中序遍历，故判断逻辑写在中间部分
      if (root == nullptr) return;
      dfs(root->left);
      if (--k == 0) ans = root->val; //从1开始计数，故先-再比较
      dfs(root->right);
    }
};

/*
Q:
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

输入：root = [3,1,4,null,2], k = 1
输出：1

输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
 */