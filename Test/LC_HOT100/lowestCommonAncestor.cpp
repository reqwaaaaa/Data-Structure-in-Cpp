//
// Created by Naiweilanlan on 25-8-20.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == nullptr || root == p || root == q) return root;
      // 递归寻找左/右子树中是否包含 p 或 q，或它们的 LCA
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      TreeNode* right = lowestCommonAncestor(root->right, p, q);

      if (left == nullptr && right == nullptr) return nullptr;
      if (left == nullptr) return right;
      if (right == nullptr) return left;
      return root;
    }

};
/*
Q：
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
最靠下的祖先（深度最大）

输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 */

/*
后序遍历（左 -> 右 -> 根），从底部向上检查子树是否包含 p 或 q。
left 和 right 表示左右子树的递归结果，可能为：
NULL：子树不含 p 或 q。
p 或 q：子树包含目标节点。
其他节点：子树的 LCA。

情况 1：left == NULL && right == NULL：
左右子树都不含 p 或 q，当前子树无 LCA，返回 NULL。
情况 2：left == NULL：
左子树不含 p 或 q，返回右子树结果（可能是 p, q, 或右子树的 LCA）。
情况 3：right == NULL：
右子树不含 p 或 q，返回左子树结果。
情况 4：left != NULL && right != NULL：
左右子树各包含一个目标节点（p 和 q 分居两侧），当前节点 root 是 LCA，返回 root。
 */