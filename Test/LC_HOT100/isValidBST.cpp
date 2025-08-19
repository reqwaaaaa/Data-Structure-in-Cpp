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
    bool isValidBST(TreeNode* root) {
        return inordered(root);
    }
private:
    long long pre = LLONG_MIN; //避免 INT_MIN 边界问题
    //对 BST 进行中序遍历（左 -> 根 -> 右），结果是一个 严格递增 的序列
    bool inordered(TreeNode* root) {
        if(root == nullptr) return true;

        if(!inordered(root->left)) return false;
        if(root->val <= pre) { //严格递增
            return false;
        }
        pre = root->val; //下一轮比较初始化
        return inordered(root->right); //返回右子树递归结果
    }
};

/*
Q:
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
 */