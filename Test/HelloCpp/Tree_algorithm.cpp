//
// Created by Naiweilanlan on 25-7-12.
//

/*
结点和树的基本定义与构造
统计二叉树中结点个数
统计二叉树中叶子结点个数
统计二叉树中度为 2 的结点个数
统计二叉树的高度
计算二叉树中某数据值是否存在
中序遍历输出所有结点
计算树中最大元素值
交换每个结点的左右子树
先序遍历打印所有结点
从树根到某个节点路径的输出
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 二叉树封装类
class BinaryTree {
private:
    TreeNode* root;

    // 递归函数实现
    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaves(TreeNode* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int countDegree2(TreeNode* node) {
        if (!node) return 0;
        int count = (node->left && node->right) ? 1 : 0;
        return count + countDegree2(node->left) + countDegree2(node->right);
    }

    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    bool find(TreeNode* node, int data) {
        if (!node) return false;
        if (node->val == data) return true;
        return find(node->left, data) || find(node->right, data);
    }

    int getMax(TreeNode* node) {
        if (!node) return INT_MIN;
        return max({node->val, getMax(node->left), getMax(node->right)});
    }

    void swapChildren(TreeNode* node) {
        if (!node) return;
        swap(node->left, node->right);
        swapChildren(node->left);
        swapChildren(node->right);
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void preorder(TreeNode* node) {
        if (!node) return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    bool findPath(TreeNode* node, int data, vector<int>& path) {
        if (!node) return false;
        path.push_back(node->val);
        if (node->val == data) return true;
        if (findPath(node->left, data, path) || findPath(node->right, data, path))
            return true;
        path.pop_back();
        return false;
    }

public:
    BinaryTree() : root(nullptr) {}

    // 创建一棵简单的示例二叉树
    void createSampleTree() {
        root = new TreeNode(10);
        root->left = new TreeNode(6);
        root->right = new TreeNode(12);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(8);
        root->right->left = new TreeNode(11);
        root->right->right = new TreeNode(15);
        root->right->right->left = new TreeNode(13);
        root->right->right->right = new TreeNode(22);
    }

    // 包装公共接口
    int getNodeCount() { return countNodes(root); }
    int getLeafCount() { return countLeaves(root); }
    int getDegree2Count() { return countDegree2(root); }
    int getTreeHeight() { return getHeight(root); }
    bool search(int data) { return find(root, data); }
    int getMaxValue() { return getMax(root); }
    void mirrorTree() { swapChildren(root); }
    void printInorder() { inorder(root); cout << endl; }
    void printPreorder() { preorder(root); cout << endl; }

    void printPathTo(int data) {
        vector<int> path;
        if (findPath(root, data, path)) {
            cout << "Path to " << data << ": ";
            for (int v : path) cout << v << " ";
            cout << endl;
        } else {
            cout << "Value " << data << " not found in tree.\n";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.createSampleTree();  // 构建测试用二叉树

    cout << "结点总数: " << tree.getNodeCount() << endl;
    cout << "叶子结点数: " << tree.getLeafCount() << endl;
    cout << "度为 2 的结点数: " << tree.getDegree2Count() << endl;
    cout << "树的高度: " << tree.getTreeHeight() << endl;
    cout << "是否包含 11? " << (tree.search(11) ? "是" : "否") << endl;
    cout << "最大值: " << tree.getMaxValue() << endl;

    cout << "中序遍历: ";
    tree.printInorder();

    cout << "先序遍历: ";
    tree.printPreorder();

    cout << "路径查找：查找22的路径：" << endl;
    tree.printPathTo(22);

    cout << "交换左右子树..." << endl;
    tree.mirrorTree();

    cout << "中序遍历（已交换）: ";
    tree.printInorder();

    return 0;
}
