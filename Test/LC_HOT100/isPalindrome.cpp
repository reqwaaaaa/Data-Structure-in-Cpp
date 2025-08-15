//
// Created by Naiweilanlan on 25-8-15.
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

// Definition for singly-linked list(单链表).
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool isPalindrome(ListNode *head) {
      vector<int> vals; //用于将单链表中的所有节点的数值存在线性表中

      while (head) {
        vals.push_back(head->val);
        head = head->next;
      }

      for (int i = 0, j = vals.size() - 1; i < j; i++, j--) {
        if (vals[i] != vals[j]) return false;
      }
      return true;
    }
};

/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

输入：head = [1,2,2,1]
输出：true
 */