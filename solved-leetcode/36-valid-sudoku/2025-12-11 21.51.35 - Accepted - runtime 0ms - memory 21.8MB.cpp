class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[10][10] = {false};
        bool cols[10][10] = {false};
        bool boxes[10][10] = {false};

        for(int i=0; i<9 ; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0';
                    int id = (i/3)*3 + j/3;

                    if(rows[i][num] || cols[j][num] || boxes[id][num])
                        return false;
                    rows[i][num] = cols[j][num] = boxes[id][num] = true;
                }
            }
        }

        return true;
    }
};