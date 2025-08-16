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
  private:
    ListNode *reverse(ListNode *head) {
      ListNode *pre = NULL;
      ListNode *cur = head;

      while (cur != NULL) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      return pre;
    }
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
      if (k == 1 || head == NULL) return head;

      ListNode *dum = new ListNode(0, head);
      ListNode *pre = dum;
      ListNode *end = dum;

      while (end->next != NULL) {
        for (int i = 0; i<k && end != NULL; i++) {
          end = end->next;
          // 确保 k 个一组
        }
        if (end == NULL) break; //如果移动不足 k 步（end == nullptr），说明剩余节点不足 k 个，跳出循环，不反转剩余部分
        // 翻转一组
        ListNode *next = end->next; //保存下一组的起始节点，便于反转后连接回链表
        ListNode *start = pre->next; //指向当前组的第一个节点（pre->next）。反转后，start 会成为该组的新末尾
        end->next = NULL; //临时断开子链,使[start, end]成为独立链表，便于反转
        pre->next = reverse(start);  // 反转这一组
        start->next = next;  // 连接后续部分,start作为这一组的末节点，充当下一组的前置节点
        // 开始下一组指针初始化
        pre = start;
        end = pre;
      }
      return dum->next;
    }
};

/*
Q:
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
 */

/*
pre：指向当前组的前一个节点（Previous）。初始指向 dummy，表示第一组的前置占位。
作用：用于连接反转后的组。每次处理完一组后，pre 更新到该组的末尾（反转前的起始节点）。

end：指向当前组的最后一个节点（End）。
作用：用于定位一组 k 个节点的末尾，便于断开并反转子链表。初始也指向 dummy，作为循环起点。

reverse中：
循环：保存 next，反转 cur->next = pre，更新 pre = cur，cur = next。
返回 pre：反转后的头节点（原 end）e.g:反转 [1,2,3] → 返回 3，链表 3->2->1
 */