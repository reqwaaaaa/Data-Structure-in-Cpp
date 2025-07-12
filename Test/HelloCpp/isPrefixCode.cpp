//
// Created by Naiweilanlan on 25-7-12.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Trie结点定义
struct TrieNode {
    bool isEnd;
    TrieNode* child[2]; // 因为是二进制编码

    TrieNode() {
        isEnd = false;
        child[0] = child[1] = nullptr;
    }
};

// 判断是否为前缀码
bool isPrefixCode(const vector<string>& codes) {
    TrieNode* root = new TrieNode();

    for (const string& code : codes) {
        TrieNode* curr = root;
        for (int i = 0; i < code.size(); ++i) {
            int bit = code[i] - '0';
            if (!curr->child[bit])
                curr->child[bit] = new TrieNode();

            curr = curr->child[bit];

            if (curr->isEnd) // 某个已有码是当前码的前缀
                return false;
        }
        // 当前码插入完，但下面还有其他分支 → 说明它是别人的前缀
        if (curr->child[0] || curr->child[1])
            return false;

        curr->isEnd = true;
    }

    return true;
}

int main() {
    vector<string> codes1 = {"0", "10", "110", "111"};
    vector<string> codes2 = {"0", "01", "011"};

    cout << "codes1 是前缀码吗？" << (isPrefixCode(codes1) ? "是" : "否") << endl;
    cout << "codes2 是前缀码吗？" << (isPrefixCode(codes2) ? "是" : "否") << endl;

    return 0;
}
