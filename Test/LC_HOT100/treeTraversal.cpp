//
// Created by Naiweilanlan on 25-8-17.
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
  //递归遍历模版
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> ans;
        traversal(root,ans);
        return ans;
    }
    void traversal(TreeNode* cur, vector<int>& vector) {
        if(cur == nullptr) return;
        traversal(cur->left,vector);
        vector.push_back(cur->val); //‘操作’在哪就是哪序遍历模版
        traversal(cur->right,vector);
    }

   //非递归遍历

    // 先序遍历：根 -> 左 -> 右
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            res.push_back(node->val);
            if (node->right) st.push(node->right); // 先右再左
            if (node->left) st.push(node->left);
        }
        return res;
    }

    // 中序遍历：左 -> 根 -> 右
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }

    // 后序遍历：左 -> 右 -> 根（借助前序逆序实现 or 双栈）
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            TreeNode* node = st1.top(); st1.pop();
            st2.push(node);
            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }
        while (!st2.empty()) {
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }

    // 层序遍历：按层从左到右
    vector<int> levelOrderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            res.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return res;
    }
};

/*
Q:
二叉树的各种递归/非递归遍历。
 */

/*
pre:栈模拟递归，先访问根，后处理左右（右先进左后进，确保左先处理）
in:栈压左到底，弹出根值后处理右，模拟递归中序
post:双栈模拟先序变体st1（根-右-左），然后用st2逆序得到左-右-根
level:队列 BFS，按层从左到右访问，先入先出确保层序。
 */