#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<string> visited;
    string ans;

    void dfs(string s, int k) {
        for (int i = 0; i < k; i++) {
            string newString = s + char(i + '0');

            if (visited.find(newString) != visited.end()) continue;

            visited.insert(newString);
            dfs(newString.substr(1), k);

            ans.push_back(i + '0');
        }
        return;
    }

    string crackSafe(int n, int k) {
        string start(n - 1, '0');
        visited.clear();
        dfs(start, k);

        return ans + start;
    }
};

// https://www.youtube.com/watch?v=VZvU1_oPjg0&t=41s
// Euler path finding