#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 20;
const int MAXMASK = 1 << 16;

int n;
int a[MAXN][MAXN];
int dp[MAXMASK];

int go(int x, int mask) {
    if (x >= n) {
        return 0;
    }

    int& tc = dp[mask];
    if (tc != -1) {
        return tc;
    }

    tc = 0;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            tc = max(tc, go(x + 1, mask | 1 << i) + a[x][i]);
        }
    }
    return tc;
}

int main() {
    int testCases;
    cin >> testCases;

    for (int tc = 1; tc <= testCases; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        int sum = go(0, 0);
        cout << "Case " << tc << ": " << sum << '\n';
    }
    return 0;
}
