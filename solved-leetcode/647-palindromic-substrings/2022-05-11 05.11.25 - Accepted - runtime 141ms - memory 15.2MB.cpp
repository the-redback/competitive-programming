#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));

        str = s;

        return rec(0, str.size() - 1);
    }

    int dp2[1001][1001];
    int dp[1001][1001];

    string str;

    int rec(int i, int j) {
        if (i == j) return 1;
        if (i > j) return 0;

        int& tc = dp[i][j];
        if (tc != -1) return tc;

        tc = 0;
        if (isPal(i, j)) tc = 1;
        tc += rec(i + 1, j);
        tc += rec(i, j - 1);
        tc -= rec(i + 1, j - 1);

        return tc;
    }

    bool isPal(int i, int j) {
        if (i >= j) return true;

        int& tc = dp2[i][j];
        if (tc != -1) return tc;

        if (str[i] != str[j]) return tc = false;

        return tc = isPal(i + 1, j - 1);
    }
};