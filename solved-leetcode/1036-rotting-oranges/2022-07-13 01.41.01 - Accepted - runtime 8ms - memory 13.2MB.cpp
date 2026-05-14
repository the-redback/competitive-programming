#include <queue>
using namespace std;

class Solution {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int mn = 0;
        while (!q.empty()) {
            int n = q.size();
            mn++;
            while (n--) {
                auto p = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = p.first + dx[i];
                    int y = p.second + dy[i];
                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;
                    if (grid[x][y] == 1) {
                        fresh--;
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }
        if (fresh > 0) return -1;

        return max(0, mn - 1);
    }
};