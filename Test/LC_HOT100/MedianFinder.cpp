//
// Created by Naiweilanlan on 25-8-28.
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

class MedianFinder {
  public:
    priority_queue<int, vector<int>, greater<int>> A; //小顶堆，放大半
    priority_queue<int, vector<int>, less<int>> B; //大顶堆，放小半

    MedianFinder() {
    }
    // 确保 B.top() ≤ A.top()，即较小半部分的最大值 ≤ 较大半部分的最小值
    void addNum(int num) {
      if (A.size() != B.size()) {
        A.push(num);
        B.push(A.top());
        A.pop();
      } else {
        B.push(num);
        A.push(B.top());
        B.pop();
      }
    }

    double findMedian() {
      return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0;
    }
};

/*
Q:
实现 MedianFinder 类:
MedianFinder() 初始化 MedianFinder 对象。
void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

输入
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
输出
[null, null, null, 1.5, null, 2.0]
解释
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 */

/*
如果 A.size() != B.size()（A 比 B 多一个元素）：
将新数字 num 插入 A（小顶堆）。
将 A 的堆顶（最小值）弹出并插入 B，确保 B 包含较小的数字。

如果 A.size() == B.size()（两堆大小相等）：
将新数字 num 插入 B（大顶堆）。
将 B 的堆顶（最大值）弹出并插入 A，确保 A 包含较大的数字。
 */