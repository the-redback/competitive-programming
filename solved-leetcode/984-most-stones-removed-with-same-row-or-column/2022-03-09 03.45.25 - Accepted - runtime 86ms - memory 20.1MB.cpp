#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

#define delta 100000
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        n *= 2;
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }

        map<int, int> mp;
        for (auto stone : stones) {
            int x = stone[0];
            int y = stone[1] + delta;

            if (mp.find(x) == mp.end()) mp[x] = mp.size();
            if (mp.find(y) == mp.end()) mp[y] = mp.size();

            Union(mp[x], mp[y]);
        }

        map<int, int> g;
        for (auto stone : stones) {
            int x = stone[0];
            int y = stone[1] + delta;

            int xpar = find(mp[x]);
            int ypar = find(mp[y]);

            g[xpar]++;
            g[ypar]++;
        }

        return stones.size() - g.size();
    }

    int par[2002];
    int rank[2002];

    int find(int u) {
        if (par[u] != u) par[u] = find(par[u]);
        return par[u];
    }

    void Union(int a, int b) {
        int u = find(a);
        int v = find(b);

        if (rank[u] > rank[v])
            par[v] = u;
        else {
            par[u] = v;
            if (rank[u] == rank[v]) rank[v]++;
        }
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
