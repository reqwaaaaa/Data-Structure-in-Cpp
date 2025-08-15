//
// Created by Naiweilanlan on 25-8-14.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA , *B = headB;
        while(A != B) {
            A = A != NULL ? A->next : headB;
            B = B != NULL ? B->next : headA;
        }
        return A;
    }
};

/*
Q:
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
 */

/*
如果 A 和 B 指向的节点不同，就不断向后走。
当 A 到达链表 A 的尾部（即 A == NULL），它就被重置到 headB。
同样，当 B 到达链表 B 的尾部时，重置为 headA。
*/