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

class Solution {
public:
    vector<pair<int, int>> countWords(int n, int m, const vector<vector<int>>& articles) {
        vector<int> a(m + 1, 0); // a[i] = 出现过的文章数
        vector<int> b(m + 1, 0); // b[i] = 出现的总次数

        for (const auto& article : articles) {
            unordered_set<int> seen;
            for (int word : article) {
                b[word]++;           // 总次数统计
                seen.insert(word);   // 本篇中出现的单词集合
            }
            for (int word : seen) {
                a[word]++;           // 每篇中唯一出现一次的单词，a++
            }
        }

        vector<pair<int, int>> result;
        for (int i = 1; i <= m; ++i) {
            result.emplace_back(a[i], b[i]);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> articles(n);
    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        articles[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> articles[i][j];
        }
    }

    Solution sol;
    auto result = sol.countWords(n, m, articles);
    for (auto [ai, bi] : result) {
        cout << ai << " " << bi << '\n';
    }

    return 0;
}