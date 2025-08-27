//
// Created by Naiweilanlan on 25-8-26.
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

class MinStack {
  stack<pair<int,int>> stack;
    /*
    first: 当前入栈的元素；
    second: 当前栈中所有元素的最小值。
    */
  public:
    MinStack() {
      stack.push({0, INT_MAX});
    }

    void push(int val) {
      stack.push({val, min(getMin(), val)}); //每次插入时更新最小值并存储
    }

    void pop() {
      stack.pop();
    }

    int top() {
      return stack.top().first;
    }

    int getMin() {
      return stack.top().second;
    }
};

/*
Q:
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
输出：
[null,null,null,null,-3,null,0,-2]
解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 */