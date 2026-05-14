#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class TicTacToe {
    int N;
    vector<int> rows;
    vector<int> cols;
    int diagonal, antidiagonal;

public:
    TicTacToe(int n) {
        N = n;
        rows = vector<int>(n);
        cols = vector<int>(n);
        diagonal = 0;
        antidiagonal = 0;
    }

    int move(int row, int col, int player) {
        int val = 1;
        if (player == 2) val = -1;

        rows[row] += val;
        cols[col] += val;
        if (row == col) diagonal += val;
        if (col == N - row - 1) antidiagonal += val;

        if (abs(rows[row]) == N || abs(cols[col]) == N || abs(diagonal) == N || abs(antidiagonal) == N) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */