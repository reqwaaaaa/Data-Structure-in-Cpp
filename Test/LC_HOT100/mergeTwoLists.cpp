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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dum(0); // 创建虚拟头节点
        ListNode* cur = &dum; //cur 是一个指针，初始指向 dum，用于动态构建合并链表。

        while (l1 != NULL && l2 != NULL) {
          if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
          }
          else {
            cur->next = l2;
            l2 = l2->next;
          }
          cur = cur->next;
        }
        cur->next = l1 ? l1 : l2; //直接接上剩余非空的那条链
        return dum.next;
    }
};

/*
Q:
将两个 升序 链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
 */

/*
虚拟头节点充当“占位符”，避免处理空链表或头节点的特殊情况。
通过 cur 操作链表，确保合并过程统一（无需单独处理第一个节点）。
 */