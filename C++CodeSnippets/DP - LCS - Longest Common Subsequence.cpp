#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string s1, s2;

int dp[1005][1005];

int lcs(int i, int j) {
    if (i < 0 || j < 0)
        return 0;

    int &tc = dp[i][j];
    if (tc != -1)
        return tc;

    tc = 0;
    if (s1[i] == s2[j]) {
        tc = lcs(i - 1, j - 1) + 1;
    }
    tc = max(tc, lcs(i, j - 1));
    tc = max(tc, lcs(i - 1, j));
    return tc;
}

int main() {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    cout << lcs(s1.size() - 1, s2.size() - 1) << '\n';
    return 0;
}

/*
Input:
abcde
ace

Output:
3
*/