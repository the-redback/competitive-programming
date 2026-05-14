#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        // build adjacency list
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            graph[u][v] = val;
            graph[v][u] = 1.0 / val;
        }

        vector<double> results;
        for (auto q : queries) {
            string u = q[0];
            string v = q[1];

            if (graph.find(u) == graph.end() || graph.find(v) == graph.end()) {
                results.push_back(-1.0);
                continue;
            }

            visited.clear();
            results.push_back(dfs(u, v));
        }
        return results;
    }

    unordered_map<string, unordered_map<string, double>> graph;
    unordered_set<string> visited;

    double dfs(string u, string& dest) {
        if (visited.find(u) != visited.end()) return -1.0;

        if (u == dest) return 1.0;

        visited.insert(u);
        for (auto [v, weight] : graph[u]) {
            double res = dfs(v, dest);

            if (res != -1) {
                return res * weight;
            }
        }

        return -1.0;
    }
};