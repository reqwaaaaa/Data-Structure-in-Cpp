//
// Created by Naiweilanlan on 25-8-13.
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
    string minWindow(string s, string t) {
        unordered_map<char, int> need; // 哈希表，统计t中每个字符需要的数量
        int needcnt = t.size();        // 总共还需要匹配的字符个数（按字符总数，而不是种类）
        string ans;                    // 最终返回的最小覆盖子串
        // 初始化need表，记录每个字符在t中出现的次数
        for (char c : t) need[c]++;
        // 定义滑动窗口的左右边界：j是左指针，i是右指针
        for (int i = 0, j = 0; i < s.size(); i++) {
            // 当前右指针s[i]是t中需要的字符时，匹配所需字符数减少
            if (need[s[i]] > 0) needcnt--;
            // 无论是否需要该字符，都将其计数减一（进入窗口）
            need[s[i]]--;
            // 如果当前窗口包含了 t 的所有字符（即 needcnt == 0）
            if (needcnt == 0) {
                // 当左边界的字符是冗余的（即出现次数多了）
                // 可以安全地将它移出窗口，以缩小窗口大小
                while (need[s[j]] < 0) {
                    need[s[j++]]++; // 移除字符s[j]，同时恢复它在need中的count
                }
                // 现在窗口[j, i]是一个“刚好满足条件”的窗口
                int len = i - j + 1;
                // 如果当前结果为空，或者找到更短的窗口，就更新答案
                if (ans.empty() || len < ans.size()) {
                    ans = s.substr(j, len);
                }
                // 为了继续寻找下一个可能的窗口，将s[j]移出
                // 这意味着又少了一个所需字符
                need[s[j++]]++;
                needcnt++;
            }
        }
        return ans;
    }
};

/*
Q:
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 */