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
    bool isSymmetric(TreeNode* root) {
      return root == nullptr || recur(root->left, root->right);
    }

    bool recur(TreeNode* left, TreeNode* right) {
      if (left == nullptr && right == nullptr) return true;
      if (left == nullptr || right == nullptr || left->val != right->val) return false;
      return recur(left->left, right->right) && recur(left->right, right->left); //注意此处两个方向
    }
};

/*
Q:
给你一个二叉树的根节点 root ， 检查它是否轴对称。

输入：root = [1,2,2,3,4,4,3]
输出：true
 */