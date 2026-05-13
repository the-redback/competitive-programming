#include <bits/stdc++.h>
using namespace std;

long long dp[70][70];

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || n == r) return 1;
    if (r == 1) return n;

    long long &memo = dp[n][r];
    if (memo != -1)
        return memo;

    memo = nCr(n - 1, r) + nCr(n - 1, r - 1);
    return memo;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cout << nCr(20, 2) << '\n';
    return 0;
}
