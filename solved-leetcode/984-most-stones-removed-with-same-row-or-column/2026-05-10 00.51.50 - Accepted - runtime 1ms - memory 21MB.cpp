#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int root[2002];

    int find(int u) {
        if (root[u] != u) root[u] = find(root[u]);
        return root[u];
    }

    void Union(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) root[root_u] = root_v;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        n *= 2;
        int delta = 100000;  // Add delta to columns, so that it stays different.

        for (int i = 0; i < n; i++) {
            root[i] = i;
        }

        unordered_map<int, int> mp;
        for (auto& stone : stones) {
            int x = stone[0];
            int y = stone[1] + delta;

            if (mp.find(x) == mp.end()) mp[x] = mp.size();
            if (mp.find(y) == mp.end()) mp[y] = mp.size();

            Union(mp[x], mp[y]);
        }

        unordered_set<int> st;
        for (auto& stone : stones) {
            int x = stone[0];
            int y = stone[1] + delta;

            st.insert(find(mp[x]));
        }

        return stones.size() - st.size();
    }
};