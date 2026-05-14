class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return rec(text1.size() - 1, text2.size() - 1, text1, text2);
    }

    int dp[1001][1001];

    int rec(int i, int j, string& s1, string& s2) {
        if (i < 0 || j < 0)
            return 0;

        int& tc = dp[i][j];
        if (tc != -1)
            return tc;

        if (s1[i] == s2[j])
            tc = rec(i - 1, j - 1, s1, s2) + 1;
        
        tc = max(tc, rec(i, j - 1, s1, s2));
        tc = max(tc, rec(i - 1, j, s1, s2));
        return tc;
    }
};