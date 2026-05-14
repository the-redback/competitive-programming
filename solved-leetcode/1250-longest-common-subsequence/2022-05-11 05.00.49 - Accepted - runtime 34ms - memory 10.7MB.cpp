#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        s1 = text1;
        s2 = text2;
        return rec(s1.size() - 1, s2.size() - 1);
    }

    string s1, s2;
    int dp[1001][1001];

    int rec(int i, int j) {
        if (i < 0 || j < 0) return 0;

        int& tc = dp[i][j];
        if (tc != -1) return tc;

        if (s1[i] == s2[j]) tc = rec(i - 1, j - 1) + 1;
        tc = max(tc, rec(i, j - 1));
        tc = max(tc, rec(i - 1, j));

        return tc;
    }
};