//
// Created by Naiweilanlan on 25-5-27.
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

// 将字符串转换为全小写
string to_lower(const string& s) {
    string res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<string> A, B;
    string word;

    // 读入第一篇文章
    for (int i = 0; i < n; ++i) {
        cin >> word;
        A.insert(to_lower(word)); // 转小写后加入 set
    }

    // 读入第二篇文章
    for (int i = 0; i < m; ++i) {
        cin >> word;
        B.insert(to_lower(word)); // 转小写后加入 set
    }

    // 求交集大小
    vector<string> intersection;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                     back_inserter(intersection));

    // 求并集大小
    vector<string> uni;
    set_union(A.begin(), A.end(), B.begin(), B.end(),
              back_inserter(uni));

    cout << intersection.size() << '\n';
    cout << uni.size() << '\n';

    return 0;
}
