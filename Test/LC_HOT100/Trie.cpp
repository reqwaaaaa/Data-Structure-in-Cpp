//
// Created by Naiweilanlan on 25-8-21.
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

class Trie {
  private:
    bool isEnd; //表示当前节点是否是单词的结尾
    Trie* next[26]; //指针数组，存储指向 26 个小写字母（a-z）的子节点

  public:
    Trie() {
      isEnd = false;
      memset(next, 0, sizeof(next)); //使用 memset 将 next 数组置为 nullptr，表示无子节点
    }

    //插入等价于在 Trie 图中添加路径，节点是字符，边是字符间的连接
    void insert(string word) {
      Trie* node = this; //从根节点（this）开始，遍历单词的每个字符 c
      for (char c : word) {
        if (node->next[c - 'a'] == NULL) { //c - 'a'（将 a-z 映射到 0-25）
          node->next[c - 'a'] = new Trie();
        }
        node = node->next[c - 'a']; //移动到子节点
      }
      node->isEnd = true;
    }

    //检查是否存在完整单词路径，且路径末尾标记为单词
    bool search(string word) {
      Trie* node = this;
      for (char c : word) {
        node = node->next[c - 'a'];
        if (node == NULL) {
          return false;
        }
      }
      return node->isEnd;
    }

    //验证是否存在从根到某节点的有效路径
    bool startsWith(string prefix) {
      Trie* node = this;
      for (char c : prefix) {
        node = node->next[c - 'a'];
        if (node == NULL) {
          return false;
        }
      }
      return true;
    }
};

/*
Q:
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
这一数据结构有相当多的应用情景，例如自动补全和拼写检查。
请你实现 Trie 类：
Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
 */