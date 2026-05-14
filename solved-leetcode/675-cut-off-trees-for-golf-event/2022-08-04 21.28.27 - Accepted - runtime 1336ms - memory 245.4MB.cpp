#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.size() == 0 || forest[0].size() == 0) return 0;

        int m = forest.size(), n = forest[0].size();

        vector<vector<int>> trees;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }

        sort(trees.begin(), trees.end());
        int ans = 0;
        for (int i = 0, cr = 0, cc = 0; i < trees.size(); i++) {
            int step = dist(forest, cr, cc, trees[i][1], trees[i][2]);
            if (step == -1) return -1;

            ans += step;
            cr = trees[i][1];
            cc = trees[i][2];
        }
        return ans;
    }

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    int dist(vector<vector<int>>& forest, int cr, int cc, int tr, int tc) {
        if (cr == tr && cc == tc) return 0;

        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> q;
        q.push({cr, cc});

        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[cr][cc] = 1;
        int step = 0;

        while (!q.empty()) {
            step++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto p = q.front();
                q.pop();

                for (int di = 0; di < 4; di++) {
                    int r = p.first + dx[di];
                    int c = p.second + dy[di];

                    if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
                    if (r == tr && c == tc) return step;
                    visited[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
        return -1;
    }
};
