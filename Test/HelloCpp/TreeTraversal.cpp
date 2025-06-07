//
// Created by Naiweilanlan on 25-6-7.
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

// 定义二叉树结点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

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
vector<int> inorderTraversal(TreeNode* root) {
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

// 构建测试二叉树
TreeNode* buildTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

void printVec(const vector<int>& vec, const string& label) {
    cout << label << ": ";
    for (int v : vec) cout << v << " ";
    cout << endl;
}

int main() {
    TreeNode* root = buildTestTree();

    auto pre = preorderTraversal(root);
    auto in = inorderTraversal(root);
    auto post = postorderTraversal(root);
    auto level = levelOrderTraversal(root);

    printVec(pre, "Preorder");
    printVec(in, "Inorder");
    printVec(post, "Postorder");
    printVec(level, "Level order");

    return 0;
}

/*
| 遍历方式 | 栈/队列使用            | 要点                   |
| ---- | ----------------- | -------------------- |
| 先序遍历 | 栈（先右后左入栈）         | 根优先，栈结构保持 LIFO 特性    |
| 中序遍历 | 栈（模拟递归压栈左子树）      | 处理完左后访问根，再访问右        |
| 后序遍历 | 双栈 或 修改前序（根右左）再逆转 | 顺序与释放资源类似，用两个栈更直观    |
| 层序遍历 | 队列                | 广度优先遍历，用队列先进先出实现每层访问 |
*/