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
    ListNode *detectCycle(ListNode *head) {
      ListNode *fast = head;
      ListNode *slow = head;

      while (true) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break; //如果有环，快慢指针一定会在环内相遇
      }

      ListNode *start = head;
      while (slow != start) {
        slow = slow->next;
        start = start->next;
      }
      return start;
    }
};

/*
Q:
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
不允许修改 链表。

输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 */

/*
设：
x 是头到环起点的长度
y 是环起点到相遇点的长度
z 是环的长度
相遇时：
快指针走了 x + y + n*z
慢指针走了 x + y
且快指针走的是慢指针的 2 倍：
2(x + y) = x + y + n*z
⟹ x + y = n*z
⟹ x = n*z - y
说明：从头走 x 步，和从相遇点再走 n*z - y 步，会在同一点（环起点）相遇。
*/