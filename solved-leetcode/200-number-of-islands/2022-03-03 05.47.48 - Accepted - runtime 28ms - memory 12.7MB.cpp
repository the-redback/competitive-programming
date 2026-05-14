#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        dx = {0, -1, 0, 1};
        dy = {-1, 0, 1, 0};

        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (g[i][j] == '1') {
                    rec(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    vector<vector<char>> g;

    vector<int> dx;
    vector<int> dy;

    void rec(int r, int c) {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size()) return;
        if (g[r][c] == '0') return;
        g[r][c] = '0';
        for (int ii = 0; ii < 4; ii++) {
            int rr = r + dx[ii];
            int cc = c + dy[ii];

            rec(rr, cc);
        }
        return;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
