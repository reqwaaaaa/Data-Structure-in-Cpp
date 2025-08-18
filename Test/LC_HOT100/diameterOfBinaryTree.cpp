//
// Created by Naiweilanlan on 25-8-18.
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
    int diameterOfBinaryTree(TreeNode* root) {
      int ans = 0;
      dfs(root, ans); //取的是ans，而不是dfs中返回的单侧最长

      return ans;
    }

    // 返回以当前节点为根的最大链长
    int dfs(TreeNode* root, int& ans) {
      if (!root) return -1;
      int l_len = dfs(root->left, ans) + 1; //返回左子树的最大链长，加上 1（从当前节点到左子节点的边）
      int r_len = dfs(root->right, ans) + 1;

      ans = max(ans, l_len + r_len);
      return max(l_len, r_len); //不返回 l_len + r_len，因为父节点只需要一侧链长（直径可能是跨节点的路径）
    }
};

/*
Q:
给你一棵二叉树的根节点，返回该树的 直径 。
二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
两节点之间路径的 长度 由它们之间边数表示。

输入：root = [1,2,3,4,5]
输出：3
解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
 */