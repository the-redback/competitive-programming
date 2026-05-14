class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        graph = vector<vector<int>>(n);

        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0);

        return seen.size() == n;
    }

    unordered_set<int> seen;
    vector<vector<int>> graph;
    bool ans;

    void dfs(int u) {
        seen.insert(u);
        for (auto v : graph[u]) {
            if (seen.find(v) == seen.end()) dfs(v);
        }
    }
};