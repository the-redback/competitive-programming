class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses);
        visit = vector<int>(numCourses);
        ans.clear();
        impossible = 0;

        for (auto uv : prerequisites) g[uv[1]].push_back(uv[0]);

        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == 0) dfs(i);
        }

        if (impossible) return {};

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool impossible;
    vector<vector<int>> g;
    vector<int> ans;
    vector<int> visit;

    void dfs(int u) {
        visit[u] = 1;
        for (auto v : g[u]) {
            if (visit[v] == 0) {
                dfs(v);
            } else if (visit[v] == 1) {
                impossible = 1;
                return;
            }
        }

        visit[u] = 2;
        ans.push_back(u);
    }
};