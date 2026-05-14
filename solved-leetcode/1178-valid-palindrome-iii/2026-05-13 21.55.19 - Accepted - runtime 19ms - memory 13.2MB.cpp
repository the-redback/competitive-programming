#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp[1010][1010];

    int rec(int i, int j, string& s) {
        if (i > j) return 0;
        if (i == j) return 1;

        int& tc = dp[i][j];
        if (tc != -1) {
            return tc;
        }

        tc = 0;
        if (s[i] == s[j]) {
            tc = rec(i + 1, j - 1, s) + 2;
        }
        tc = max(tc, rec(i + 1, j, s));
        tc = max(tc, rec(i, j - 1, s));

        return tc;
    }

    bool isValidPalindrome(string s, int k) {
        memset(dp, -1, sizeof(dp));

        int LPS = rec(0, s.size() - 1, s);
        int op_needed = s.size() - LPS;

        return k >= op_needed;
    }
};