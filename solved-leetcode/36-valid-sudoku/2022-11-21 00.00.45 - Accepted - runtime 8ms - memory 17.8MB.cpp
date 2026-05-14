class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10]={0}, col[10]={0}, dia[10]={0};
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int val=board[i][j]-'0';
                int pos=1<<val;
                int di = (i/3)*3 + (j/3); 
                
                if(row[i] & pos) return false;
                if(col[j] & pos) return false;
                if(dia[di] & pos) return false;
                
                row[i] |=pos;
                col[j] |=pos;
                dia[di] |=pos;
            }
        }
        
        return true;
    }
};