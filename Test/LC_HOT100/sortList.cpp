//
// Created by Naiweilanlan on 25-8-17.
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
    ListNode *merge(ListNode *l1, ListNode *l2) {
      ListNode *dum = new ListNode(0);
      ListNode *cur = dum;

      while (l1 && l2) {
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
      cur->next = l1 ? l1 : l2; //剩余部分

      return dum->next;
    }
  public:
    ListNode *sortList(ListNode *head) {
      if (head == NULL || head->next == NULL) return head;

      ListNode *fast = head->next;
      ListNode *slow = head;
      // 找中点
      while (fast && fast->next) { //确保 fast 可以移动两步
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode *mid = slow->next; //中点划分，mid是后半段的起点
      slow->next = NULL; //断开左右两部分
      // 归并排序左右递归后合并
      ListNode *left = sortList(head);
      ListNode *right = sortList(mid);

      return merge(left, right);
    }
};

/*
Q:
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
 */

/*
初始化 fast = head->next 让 fast 提前一步，确保 slow 停在偏左的中点（前半段的最后一个节点），使分割更均匀;

为什么链表适合归并排序？
归并排序不依赖随机访问，只需要顺序访问节点。
链表分割（找中点）快慢指针可以做到 O(n)。
链表合并很自然：不用移动元素，只修改 next 指针，非常快，真正的 O(1) 插入。
而快速排序不适合链表，因为快速排序需要频繁随机访问元素做 pivot 对比，链表访问很慢。
 */