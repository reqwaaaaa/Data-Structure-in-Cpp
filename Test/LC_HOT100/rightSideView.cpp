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
    vector<int> ans;
    void dfs(TreeNode* n, int d) { //n：当前节点指针; d：当前深度（从 0 开始，根节点为 0）
      if (n == nullptr) return; //空节点不参与

      if (d == ans.size()) ans.push_back(n->val); //如果当前深度 d 等于 ans 的大小，说明这是该深度的第一个访问节点

      dfs(n->right, d + 1); //右视图，故先递归右子树
      dfs(n->left, d + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
      ans.clear();
      dfs(root, 0);
      return ans;
    }
};

/*
Q:
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

输入：root = [1,2,3,4,null,null,null,5]
输出：[1,3,4,5]
 */