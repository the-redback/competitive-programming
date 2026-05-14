#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool impossible;
        vector<vector<int>> g(numCourses);
        vector<int> ans, indegree(numCourses);

        for (auto e : prerequisites) {
            g[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            ans.push_back(u);
            q.pop();

            for (auto v : g[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (ans.size() != numCourses) return {};
        return ans;
    }
};
