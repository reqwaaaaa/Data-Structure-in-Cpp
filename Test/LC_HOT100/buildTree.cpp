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
    unordered_map<int,int> index; //键为中序遍历中的节点值，值为该值在中序数组中的索引
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }

    TreeNode* build(vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright) {
        if(preleft > preright) return nullptr;

        int rootval = preorder[preleft]; //前序遍历的第一个元素是当前子树的根节点值
        int rootindex = index[rootval]; //通过哈希表查找当前根节点值在中序遍历中的索引
        int leftnum = rootindex - inleft; //计算左子树节点数（中序遍历中根节点左侧的节点数）

        TreeNode* root = new TreeNode(rootval);
        root->left = build(preorder, preleft+1, preleft+leftnum, inorder, inleft, rootindex-1);
        root->right = build(preorder, preleft+leftnum+1, preright, inorder, rootindex+1, inright);
        return root;
    }
};

/*
Q:
给定两个整数数组 preorder 和 inorder
其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
 */

/*
递归构造子树：

左子树：
前序范围：[preleft+1, preleft+leftnum]（根后到左子树结束）。
中序范围：[inleft, rootindex-1]（根前所有节点）。

右子树：
前序范围：[preleft+leftnum+1, preright]（左子树后到结束）。
中序范围：[rootindex+1, inright]（根后所有节点）。
 */