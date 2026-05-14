#include <vector>

using namespace std;

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < col; i++) {
            if (grid[0][i] != grid[0][0]) {
                // Now flip
                for (int j = 0; j < row; j++) grid[j][i] ^= 1;
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (grid[i][j] != grid[i][0]) return false;
            }
        }
        return true;
    }
};