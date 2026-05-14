class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;
        vector<int>dir={0, 1, -1};

        int r = board.size();
        int c = board[0].size();

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){

                int count=0;
                for(int dx=0; dx<3; dx++){
                    for(int dy=0; dy<3; dy++){
                        if(dx == 0 && dy == 0 )
                            continue;
                        
                        int rr = i + dir[dx];
                        int cc = j + dir[dy];

                        if(rr>=0 && cc>=0 && rr<r && cc<c && copy[rr][cc]==1){
                            count++;
                        }
                    }
                }

                // Rule 1, 3
                if(count < 2 || count > 3)
                    board[i][j]=0;
                else if(count == 3)
                    board[i][j]=1;

            }
        }
    }
};