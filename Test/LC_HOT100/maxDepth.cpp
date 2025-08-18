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
    //非递归（层序遍历）
    int maxDepth1(TreeNode* root) {
      if (root == nullptr) return 0;

      int depth = 0;
      queue<TreeNode*> q;
      q.push(root);

      while (!q.empty()) {
        int size = q.size(); //当前层节点数
        depth++; //队列不空说明到下一层了
        for (int i = 0; i < size; i++) {
          TreeNode* node = q.front();
          q.pop();
          if (node->left != nullptr) q.push(node->left);
          if (node->right != nullptr) q.push(node->right);
        }
      }
      return depth;
    }

    //递归（对左右子树进行递归，取大再+根）
    int maxDepth2(TreeNode* root) {
      if (root == nullptr) return 0;

      return max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
    }
};

/*
Q:
给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

输入：root = [3,9,20,null,null,15,7]
输出：3
 */