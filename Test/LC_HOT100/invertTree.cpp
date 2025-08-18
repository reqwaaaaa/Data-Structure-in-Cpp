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
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr)   return root;
      //只要把每一个节点的左右孩子翻转一下，就可以达到整体翻转的效果
      swap(root->left, root->right);
      invertTree(root->left);
      invertTree(root->right);

      return root;
    }
};

/*
Q:
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 */