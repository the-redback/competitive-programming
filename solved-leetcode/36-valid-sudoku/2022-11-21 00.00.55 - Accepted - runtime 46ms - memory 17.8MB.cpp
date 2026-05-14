class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10]={0},col[10]={0},boxes[10]={0};
        
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.')
                    continue;
                int value=board[r][c]-'0';
                int pos=1<<value;
                
                if(row[r] & pos) return false;
                if(col[c] & pos) return false;
                row[r] |= pos;
                col[c] |= pos;
                
                int id=(r/3)*3+c/3;
                if(boxes[id] & pos) return false;
                boxes[id] |= pos;
            }
        }
        return true;
        
        
    }
};