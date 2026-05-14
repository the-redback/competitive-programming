#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    rec(i, j, grid);
                    ans++;
                }
            }
        }

        return ans;
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    void rec(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size()) return;

        if (grid[r][c] == '0') return;
        grid[r][c] = '0';

        for (int i = 0; i < 4; i++) {
            int rr = r + dx[i];
            int cc = c + dy[i];

            rec(rr, cc, grid);
        }

        return;
    }
};