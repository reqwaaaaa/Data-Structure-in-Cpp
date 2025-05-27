//
// Created by Naiweilanlan on 25-5-23.
//

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<string, string> value;                 // 已求值的变量
    unordered_map<string, vector<string>> expr;          // 延迟表达式
    unordered_set<string> visiting;                      // 检测循环依赖

    // 递归求变量的值
    string eval(const string& var) {
        if (value.count(var)) return value[var];
        if (visiting.count(var)) return ""; // 防止死循环（题目保证无环）

        visiting.insert(var);
        string res;
        for (auto& token : expr[var]) {
            if (token[0] == '$') res += eval(token.substr(1));
            else res += token;
        }
        visiting.erase(var);
        return value[var] = res; // 缓存结果
    }

    // 处理一条语句
    void process(int type, const string& var, const vector<string>& tokens) {
        if (type == 1) { // 立即赋值
            string res;
            for (auto& token : tokens)
                res += (token[0] == '$') ? eval(token.substr(1)) : token;
            value[var] = res;
        } else if (type == 2) { // 延迟赋值
            expr[var] = tokens;
        } else if (type == 3) { // 输出变量值长度
            cout << eval(var).length() % 1000000007 << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    Solution sol;
    vector<int> results; // 用于存储所有 3 类型语句的结果

    while (n--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int op; string var, token;
        ss >> op >> var;

        vector<string> tokens;
        while (ss >> token) tokens.push_back(token);

        if (op == 3) {
            string val = sol.eval(var);
            results.push_back(val.length() % 1000000007); // 收集结果
        } else {
            sol.process(op, var, tokens);
        }
    }

    // 统一输出所有结果
    for (int res : results) {
        cout << res << '\n';
    }

    return 0;
}

