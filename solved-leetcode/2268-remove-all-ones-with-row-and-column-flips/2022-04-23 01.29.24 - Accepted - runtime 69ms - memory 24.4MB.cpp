class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < col; i++){
            if(grid[0][i] == 1){
                // Now flip
                for(int j = 0; j < row; j++)
                    grid[j][i] ^= 1;
            }
        }
        
        for(int i = 1; i < row; i++){
            int sum = 0;
            for(int j = 0; j < col; j++){
                sum += grid[i][j];
            }
            if(sum != 0 && sum  != col)
                return false;
        }
        return true;
    }
};