//
// Created by Naiweilanlan on 25-8-21.
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { //课程数量（图的节点数）依赖关系（图的边）
      vector<vector<int>> graph(numCourses); //邻接表，表示有向图，graph[i] 存储课程 i 的后继课程（依赖 i 的课程）
      vector<int> visited(numCourses, 0); //0 = 未访问，1 = 访问中，-1 = 已访问完毕

      for (const auto& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]); //倒一下，遍历 prerequisites，对于每对 [a, b] 将 a 加入 graph[b]，表示 b 的后继是 a
      }

      // 对每门课程做一次 DFS 判断是否成环
      for (int i = 0; i < numCourses; ++i) {
        if (!dfs(i, graph, visited)) return false;
      }
      return true;
    }

    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited) {
      if (visited[course] == 1) return false; //当前路径已访问，说明有环（循环依赖死锁）
      if (visited[course] == -1) return true; //已访问完毕，无需再搜索

      visited[course] = 1; //标记为访问中
      for (int next : graph[course]) {
        if (!dfs(next, graph, visited)) return false; //对每个后继调用 dfs，如果返回 false（发现环），立即返回 false
      }

      visited[course] = -1; //通过访问，访问完毕
      return true;
    }
};

/*
Q:
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。

输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 */