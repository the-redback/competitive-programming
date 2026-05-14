#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> indegree(numCourses);

        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (auto v : g[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
        if (ans.size() != numCourses) return {};
        return ans;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
