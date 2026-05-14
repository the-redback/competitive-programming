#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses);

        for (auto e : prerequisites) {
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            count++;
            int u = q.front();
            q.pop();

            for (auto v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return numCourses == count;
    }
};