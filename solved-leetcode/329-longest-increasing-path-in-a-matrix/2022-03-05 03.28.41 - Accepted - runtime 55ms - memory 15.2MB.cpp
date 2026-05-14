class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int res = 1;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }

    int dp[201][201];
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    int dfs(vector<vector<int>>& mat, int r, int c) {
        int& tc = dp[r][c];
        if (tc != -1) return tc;

        tc = 1;
        for (int i = 0; i < 4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];

            if (x < 0 || y < 0 || x >= mat.size() || y >= mat[r].size() || mat[x][y] <= mat[r][c]) continue;
            tc = max(tc, dfs(mat, x, y) + 1);
        }
        return tc;
    }
};