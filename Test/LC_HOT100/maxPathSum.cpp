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
    int maxPathSum(TreeNode* root) {
      visit(root);
      return ans;
    }

    int ans = INT_MIN;
    // 子函数返回以当前节点为起点的单侧最大路径和（从 root 到某个子节点）
    int visit(TreeNode* root) {
      if (!root) return 0;

      int left = max(0, visit(root->left)); //返回左子树以左孩子为起点的单侧最大路径和(如果小于0就舍弃)
      int right = max(0, visit(root->right));
      int cur = root->val + left + right; //计算经过当前节点的路径和（左子树 + 根 + 右子树）
      ans = max(ans, cur); //更新结果
      return root->val + max(left, right); //返回以当前节点为起点的单侧最大路径和
    }
};
/*
Q:
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中 至多 出现一次 。该路径 至少 包含一个节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和。

输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 */

/*
需要先知道左右子树的单侧最大路径和，才能计算当前节点的路径和。
后序遍历自然汇总子树信息
 */