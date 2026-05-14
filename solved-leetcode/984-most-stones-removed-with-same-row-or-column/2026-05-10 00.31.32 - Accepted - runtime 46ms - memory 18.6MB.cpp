class Solution {
public:
    int root[2002];

    int find(int u) {
        if (root[u] != u)
            root[u] = find(root[u]);
        return root[u];
    }

    void Union(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v)
            root[root_u] = root_v;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(find(i));
        }

        return stones.size() - st.size();
    }
};