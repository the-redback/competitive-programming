#include <iostream>
using namespace std;

class NumMatrix {
    vector<vector<int>> pre;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        pre = matrix;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                pre[i][j] = matrix[i][j];

                if (i != 0) pre[i][j] += pre[i - 1][j];
                if (j != 0) pre[i][j] += pre[i][j - 1];
                if (i > 0 && j > 0) pre[i][j] -= pre[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = pre[row2][col2];
        if (row1 != 0) ans -= pre[row1 - 1][col2];
        if (col1 != 0) ans -= pre[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) ans += pre[row1 - 1][col1 - 1];

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
