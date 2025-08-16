//
// Created by Naiweilanlan on 25-8-16.
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
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode *dum = new ListNode(0, head);
      ListNode *left = dum;
      ListNode *right = dum;

      while (n--) {
        right = right->next;
      }

      while (right->next) {
        right = right->next;
        left = left->next;
      }

      ListNode *del = left->next;
      left->next = left->next->next;
      delete del;
      return dum->next;
    }
};

/*
Q:
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
 */

/*
0 -> 1 -> 2 -> 3 -> 4 -> 5
↑
dummy
哨兵节点，其下一节点指向head，避免单独处理 head 为空的情况
*/