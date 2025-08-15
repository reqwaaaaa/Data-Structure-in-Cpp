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
    ListNode *reverseList(ListNode *head) {
      ListNode *a = head; //指向当前处理的节点，初始为链表头节点 head。
      ListNode *b = NULL; //指向反转后的链表的头节点,初始为 nullptr，因为反转开始时还没有任何节点被反转。

      while (a != NULL) {
        ListNode *tmp = a->next; //暂存下一节点，因为后续要动 a->next 指针
        a->next = b; // 当前节点反向指向前面，就是指向头 b
        b = a; //b 从 nullptr 更新为 1，表示反转链表现在以 1 开头。
        a = tmp; //将 a 移到下一个节点（之前保存的 tmp），继续处理
      }
      return b; //返回头节点
    }
};

/*
Q:
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
 */