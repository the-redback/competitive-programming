class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dir = {0, 1, -1};

        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int count = 0;
                for (int xx = 0; xx < 3; xx++) {
                    for (int yy = 0; yy < 3; yy++) {
                        if (xx == 0 && yy == 0) continue;

                        int rr = i + dir[xx];
                        int cc = j + dir[yy];

                        if (rr >= 0 && cc >= 0 && rr < r && cc < c && abs(board[rr][cc]) == 1) {
                            count++;
                        }
                    }
                }

                // Rule 1, 3
                if (board[i][j] == 1 && (count < 2 || count > 3))
                    board[i][j] = -1;
                else if (board[i][j] == 0 && count == 3)  // Rule 4
                    board[i][j] = 2;

                // Rule 2 doesn't need change.
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == -1) board[i][j] = 0;
                if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};