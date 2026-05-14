#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        memset(dp, -1, sizeof(dp));
        backtrack(s, 0);
        return result;
    }

    vector<vector<string>> result;
    vector<string> comb;

    void backtrack(string& s, int start) {
        if (start >= s.size()) {
            result.push_back(comb);
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                comb.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
                comb.pop_back();
            }
        }
        return;
    }

    int dp[17][17];

    bool isPalindrome(string& s, int i, int j) {
        if (i >= j) return true;

        int& tc = dp[i][j];
        if (tc != -1) return tc;

        tc = false;

        if (s[i] == s[j]) return tc = isPalindrome(s, i + 1, j - 1);
        return tc;
    }
};