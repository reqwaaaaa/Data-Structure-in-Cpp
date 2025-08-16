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
    ListNode *swapPairs(ListNode *head) {
      ListNode *dum = new ListNode(0, head);
      ListNode *n2 = head;
      ListNode *n1 = dum;

      while (n2 && n2->next) {
        ListNode *n3 = n2->next;
        ListNode *n4 = n3->next;

        n1->next = n3; //先把头改了
        n3->next = n2;
        n2->next = n4;

        n1 = n2;
        n2 = n4;
      }
      return dum->next;
    }
};

/*
Q:
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

输入：head = [1,2,3,4]
输出：[2,1,4,3]
 */