class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        if (k >= row + col - 2) return row + col - 2;

        vector<vector<int>> vis(row, vector<int>(col, -1));
        queue<vector<int>> q;

        q.push({0, 0, 0, k});

        while (!q.empty()) {
            auto tp = q.front();

            int x = tp[0], y = tp[1];
            q.pop();

            if (x < 0 || y < 0 || x >= row || y >= col) continue;

            if (x == row - 1 && y == col - 1) return tp[2];  // distance

            if (grid[x][y] == 1) {
                if (tp[3] > 0)
                    tp[3]--;
                else
                    continue;
            }

            if (vis[x][y] != -1 && vis[x][y] >= tp[3]) continue;

            vis[x][y] = tp[3];

            q.push({x + 1, y, tp[2] + 1, tp[3]});
            q.push({x, y + 1, tp[2] + 1, tp[3]});
            q.push({x - 1, y, tp[2] + 1, tp[3]});
            q.push({x, y - 1, tp[2] + 1, tp[3]});
        }

        return -1;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
