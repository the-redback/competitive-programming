#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++)
                if (backtrack(board, word, i, j, 0)) return true;
        }
        return false;
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int ind) {
        if (ind >= word.size()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[ind]) return false;

        board[r][c] = '#';

        for (int d = 0; d < 4; d++) {
            int x = r + dx[d];
            int y = c + dy[d];
            if (backtrack(board, word, x, y, ind + 1)) return true;
        }

        board[r][c] = word[ind];
        return false;
    }
};