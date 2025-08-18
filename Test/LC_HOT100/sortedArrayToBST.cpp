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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return bst(nums, 0, nums.size()-1);
    }

    TreeNode* bst(vector<int>& nums, int left, int right) {
      if (left > right) return NULL;

      int mid = left + (right - left) / 2; //每次取有序数组中点的值作为当前子树的根，二分递归
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = bst(nums, left, mid - 1);
      root->right = bst(nums, mid + 1, right);
      return root;
    }
};

/*
Q:
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。

输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案
 */