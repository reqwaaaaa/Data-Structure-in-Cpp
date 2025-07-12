//
// Created by Naiweilanlan on 25-7-9.
//

// 栈与队列的核心算法实现合集
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;

// ------------------- 1. 双栈模拟队列 -------------------
class MyQueue {
private:
    stack<int> inStack, outStack;

    // 将 inStack 元素倒入 outStack 以实现先进先出
    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    void push(int x) {
        inStack.push(x);
    }

    void pop() {
        if (outStack.empty()) transfer();
        if (!outStack.empty()) outStack.pop();
    }

    int front() {
        if (outStack.empty()) transfer();
        return outStack.empty() ? -1 : outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

// ------------------- 2. 循环队列 size / tag 判断法 -------------------
class CircularQueueSize {
private:
    int *data, front, rear, size, capacity;
public:
    CircularQueueSize(int cap) : capacity(cap), size(0), front(0), rear(0) {
        data = new int[cap];
    }
    ~CircularQueueSize() { delete[] data; }

    bool enqueue(int val) {
        if (size == capacity) return false; // 满
        data[rear] = val;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool dequeue() {
        if (size == 0) return false; // 空
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int getFront() {
        return size == 0 ? -1 : data[front];
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};

class CircularQueueTag {
private:
    int *data, front, rear, capacity;
    bool tag;
public:
    CircularQueueTag(int cap) : capacity(cap), front(0), rear(0), tag(false) {
        data = new int[cap];
    }
    ~CircularQueueTag() { delete[] data; }

    bool enqueue(int val) {
        if (front == rear && tag) return false; // 满
        data[rear] = val;
        rear = (rear + 1) % capacity;
        tag = true;
        return true;
    }

    bool dequeue() {
        if (front == rear && !tag) return false; // 空
        front = (front + 1) % capacity;
        tag = false;
        return true;
    }

    int getFront() {
        return (front == rear && !tag) ? -1 : data[front];
    }

    bool isEmpty() { return front == rear && !tag; }
    bool isFull() { return front == rear && tag; }
};

// ------------------- 3. 括号匹配 -------------------
bool isValidBracket(const string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
        }
    }
    return st.empty();
}

// ------------------- 4. 中缀转后缀 -------------------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string &expr) {
    stack<char> ops;
    string output;
    for (char c : expr) {
        if (isdigit(c)) output += c;
        else if (c == '(') ops.push(c);
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output += ops.top();
                ops.pop();
            }
            if (!ops.empty()) ops.pop(); // pop '('
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                output += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) {
        output += ops.top();
        ops.pop();
    }
    return output;
}

// ------------------- 5. 后缀表达式求值 -------------------
int evalPostfix(const string &postfix) {
    stack<int> st;
    for (char c : postfix) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

// ------------------- 6. 递归调用所用的栈 -------------------
int factorial(int n) {
    if (n <= 1) return 1;  // 系统用栈存储函数调用帧
    return n * factorial(n - 1);
}

// ------------------- 7. 单调队列：求滑动窗口最大值 -------------------
vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq;
    /*
    dq 是一个双端队列（deque），我们用它来存下标而不是数值，
    保证里面的下标对应的数值是 单调递减 的（从队头到队尾），
    队头 dq.front() 对应窗口内最大值。
     */
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        // 保证单调递减，当前元素大于末尾则弹出
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
            /*
            当前 nums[i] 比队列尾部小/等，就不需要管，因为 nums[i] 会“遮住”它们（它们永远不会是最大值）
            所以我们把它们全部从队尾 pop_back() 掉
             */
        }
        dq.push_back(i); // 再把当前元素 下标 加入队尾

        // 移出窗口外元素
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        // 从第 k-1 开始记录窗口最大值
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

// ------------------- 主函数测试 -------------------
int main() {
    cout << "1. 双栈模拟队列\n";
    MyQueue mq;
    mq.push(1); mq.push(2); mq.push(3);
    mq.pop();
    cout << "Front: " << mq.front() << endl;  // 输出2

    cout << "\n2. 循环队列Size判断\n";
    CircularQueueSize q1(3);
    q1.enqueue(10); q1.enqueue(20);
    q1.dequeue();
    cout << "Front: " << q1.getFront() << endl;  // 输出20

    cout << "\n3. 括号匹配\n";
    cout << isValidBracket("{[()]}()") << endl;  // 输出1（true）

    cout << "\n4. 中缀转后缀\n";
    string infix = "1+(2*3)";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;  // 输出123*+

    cout << "5. 后缀求值\n";
    cout << "Result: " << evalPostfix(postfix) << endl;  // 输出7

    cout << "\n6. 递归调用：阶乘(5) = " << factorial(5) << endl; // 输出120

    cout << "\n7. 单调队列：滑动窗口最大值\n";
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> max_vals = maxSlidingWindow(nums, 3);
    for (int val : max_vals) cout << val << " ";
    cout << endl;

    return 0;
}
