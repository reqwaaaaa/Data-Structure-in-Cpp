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
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) { //定义一个 lambda 表达式 cmp 作为优先队列的比较函数。
            return a->val > b->val; //如果返回true，则表明a的优先级比b小，b（更小的数）更靠近堆顶（小顶堆）
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);

        for (ListNode* head : lists) { //遍历 lists，将每个非空链表的头节点（head）压入优先队列 eg lists = [[1,4,5],[1,3,4],[2,6]]，初始堆：[1 (list1), 1 (list2), 2 (list3)]（按值排序）
          if (head) {
            q.push(head);
          }
        }

        ListNode dum(0);
        auto cur = &dum;

        while (!q.empty()) {
            auto node = q.top();  // 当前队列内最小节点(小顶堆)
            q.pop();
            if (node->next) {     // 下一个节点存在，继续入队
                q.push(node->next);
            }
            cur->next = node;     // 将取出的节点链接到结果链表
            cur = cur->next;
        }
        return dum.next;
    }
};

/*
Q:
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
 */

/*
C++ 的 priority_queue：
默认是 大顶堆（Max Heap），即堆顶元素是 最大值。
默认比较器是 std::less<T>，对于两个元素 a 和 b，std::less 返回 a < b。
如果 a < b 为 true，则 a 优先级低，b 优先级高（b 更靠近堆顶）。

自定义比较器：
当提供自定义比较器（如 cmp），priority_queue 会根据比较器的返回值调整堆的顺序。
比较器 cmp(a, b) 返回 true 表示 a 的优先级 低于 b，即 b 应该排在 a 前面（更靠近堆顶）。
 */