#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, -1));

        int top = 0, down = n - 1, left = 0, right = n - 1;
        int k = 1;
        while (k <= n * n) {
            for (int i = left; i <= right; i++) {
                v[top][i] = k++;
            }
            for (int i = top + 1; i <= down; i++) {
                v[i][right] = k++;
            }

            if (top != down) {
                for (int i = right - 1; i >= left; i--) {
                    v[down][i] = k++;
                }
            }
            if (left != right) {
                for (int i = down - 1; i > top; i--) {
                    v[i][left] = k++;
                }
            }
            left++;
            right--;
            top++;
            down--;
        }
        return v;
    }
};