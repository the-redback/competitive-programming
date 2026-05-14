#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int ans = 0;
int dp[1005][1005];

int lcs(int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }

    int& tc = dp[i][j];
    if (tc != -1) {
        return tc;
    }

    tc = 0;
    // longest common substring must be contiguous
    if (s1[i] == s2[j]) {
        tc = lcs(i - 1, j - 1) + 1;
    }
    ans = max(ans, tc);

    // still explore other states
    lcs(i - 1, j);
    lcs(i, j - 1);

    return tc;
}

int main() {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    lcs(s1.size() - 1, s2.size() - 1);
    cout << ans << '\n';
    return 0;
}

/*
Input:
abcdxyz
xyzabcd

Output:
4
*/
