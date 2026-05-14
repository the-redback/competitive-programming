#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        unordered_map<string, bool> supp;

        for (auto rec : recipes) indegree[rec] = 0;

        for (auto s : supplies) supp[s] = true;

        for (int i = 0; i < recipes.size(); i++) {
            for (auto element : ingredients[i]) {
                if (supp.find(element) == supp.end()) {
                    graph[element].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for (auto rec : recipes) {
            if (indegree[rec] == 0) {
                q.push(rec);
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            ans.push_back(u);

            for (auto v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return ans;
    }
};