#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int dp[1010][1010];

    bool ispal(int i, int j, string& s) {
        if (i >= j) {
            return true;
        }

        int& tc = dp[i][j];
        if (tc != -1) {
            return tc;
        }

        tc = false;
        if (s[i] == s[j]) {
            tc = ispal(i + 1, j - 1, s);
        }
        return tc;
    }

    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));

        int mxlen = 1;
        int in = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (ispal(i, j, s) && j - i + 1 > mxlen) {
                    mxlen = j - i + 1;
                    in = i;
                }
            }
        }

        return s.substr(in, mxlen);
    }
};

int main() {
    Solution sol;
    string s = "babadda";
    cout << sol.longestPalindrome(s) << endl;
    s = "babcbabcbaccba";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}