//
// Created by Naiweilanlan on 25-8-11.
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> a; //0放排序后串，1放原串
      vector<vector<string>> ans;
      for (string s : strs) {
        string ex = s; //一个一个串检查
        sort(ex.begin(), ex.end());
        a[ex].push_back(s); //排序好的结果放入first，对应的second放其原串
      }

      for (auto it = a.begin(); it != a.end(); it++) {
        ans.push_back(it->second); //将排序后相同的串所对应的多个原串放入一组向量中，a有几行结果就几组
      }

      return ans;
    }
};
/*
将向量中每个字符串按照字母表顺序排序，排序结果一样的放在一组里：
输入：["eat", "tea", "tan", "ate", "nat", "bat"]
排序后：
"eat" → "aet"
"tea" → "aet"
"tan" → "ant"
"ate" → "aet"
"nat" → "ant"
"bat" → "abt"

map_a:
{
  "aet": ["eat", "tea", "ate"],
  "ant": ["tan", "nat"],
  "abt": ["bat"]
}

*/