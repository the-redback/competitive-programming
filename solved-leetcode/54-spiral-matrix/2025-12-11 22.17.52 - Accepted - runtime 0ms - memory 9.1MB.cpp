class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int up=0, left=0, down = rows - 1, right = cols - 1;

        while(result.size() < rows * cols){
            for(int j=left; j<=right; j++)
                result.push_back(matrix[up][j]);

            for(int i = up +1; i<=down; i++)
                result.push_back(matrix[i][right]);

            if(up != down){
                for(int j=right-1; j>=left; j--)
                    result.push_back(matrix[down][j]);
            }

            if(left != right){
                for(int i=down-1; i>up; i--)
                    result.push_back(matrix[i][left]);
            }

            left++;
            right--;
            up++;
            down--;
        }

        return result;
    }
};