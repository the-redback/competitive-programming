class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int result = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for( int j = 0; j < matrix[i].size(); j++) {
                result = max(result, dfs(matrix, i, j));
            }
        }

        return result;
    }

    int dp[201][201];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int dfs(vector<vector<int>> &mat, int r, int c){
        int &tc = dp[r][c];
        if (tc != -1) {
            return tc;
        }

        tc = 1;
        for (int i = 0; i < 4; i++){
            int xx = r + dx[i];
            int yy = c + dy[i];

            if(xx < 0 || yy < 0 || xx >= mat.size() || yy >= mat[r].size() || mat[xx][yy] <= mat[r][c]) {
                continue;
            }

            tc = max(tc, dfs(mat, xx, yy) + 1);
        }

        return tc;
    }
};