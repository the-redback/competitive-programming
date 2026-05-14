#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return rec(s, words, 0, dp);
    }

    bool rec(string& s, unordered_set<string>& words, int step, vector<int>& dp) {
        if (step == s.size()) return true;

        int& tc = dp[step];
        if (tc != -1) return tc;

        tc = 0;
        for (int start = step; start <= s.size() - 1; start++) {
            string str = s.substr(step, start - step + 1);
            if (words.find(str) != words.end()) tc |= rec(s, words, start + 1, dp);
            if (tc) return tc;
        }
        return tc;
    }
};