class Solution {
public:
    int skip[10][10];
    bool visited[10];
    int M, N;

    void prepare() {
        memset(skip, 0, sizeof(skip));
        memset(visited, false, sizeof(visited));

        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[7][9] = skip[9][7] = 8;
        skip[9][3] = skip[3][9] = 6;

        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
    }

    int backtrack(int curr, int len) {
        int count = 0;

        if (len >= M) {
            count++;
        }

        if (len == N) {
            return count;
        }

        visited[curr] = true;
        for (int i = 1; i <= 9; i++) {
            if (visited[i]) continue;

            int mid = skip[curr][i];
            if (mid == 0 || visited[mid]) {
                count += backtrack(i, len + 1);
            }
        }
        visited[curr] = false;
        return count;
    }

    int numberOfPatterns(int m, int n) {
        prepare();
        M = m, N = n;

        int ans = 0;

        // 1, 3, 7, 9 are symmetrical
        ans += backtrack(1, 1) * 4;

        // 2, 4, 6, 8 are symmetrical too
        ans += backtrack(2, 1) * 4;

        // 5 is unique
        ans += backtrack(5, 1);

        return ans;
    }
};