#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    void preCal(vector<vector<int>>& v, int m, int n, vector<vector<int>>& p) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                p[i + 1][j + 1] = v[i][j] + p[i + 1][j] + p[i][j + 1] - p[i][j];
            }
        }
        return;
    }

    int calcSum(vector<vector<int>>& p, int r1, int c1, int r2, int c2) {
        return p[r2 + 1][c2 + 1] - p[r2 + 1][c1] - p[r1][c2 + 1] + p[r1][c1];
    }

public:
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> stamp(m, vector<int>(n));
        vector<vector<int>> pref1(m + 1, vector<int>(n + 1));
        vector<vector<int>> pref2(m + 1, vector<int>(n + 1));

        preCal(grid, m, n, pref1);
        for (int i = h - 1; i < m; i++) {
            for (int j = w - 1; j < n; j++) {
                stamp[i][j] = calcSum(pref1, i - h + 1, j - w + 1, i, j) == 0;
            }
        }

        preCal(stamp, m, n, pref2);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && calcSum(pref2, i, j, min(i + h - 1, m - 1), min(j + w - 1, n - 1)) == 0)
                    return false;
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/stamping-the-grid/solutions/1676509/bag-of-tricks/