class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int val = grid[0][0];
        for (int i = 0; i < col; i++) {
            if (grid[0][i] != val) {
                // Now flip
                for (int j = 0; j < row; j++) grid[j][i] ^= 1;
            }
        }

        for (int i = 1; i < row; i++) {
            val = grid[i][0];
            for (int j = 1; j < col; j++) {
                if (grid[i][j] != val) return false;
            }
        }
        return true;
    }
};