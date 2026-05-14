class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return rec(s, words, 0, dp);
    }

    bool rec(string& s, unordered_set<string>& words, int step, vector<int>& dp) {
        if (step >= s.size()) return true;

        int& tc = dp[step];
        if (tc != -1) return tc;

        tc = 0;
        for (int i = step + 1; i <= s.size(); i++) {
            string str = s.substr(step, i - step);  // doesn't include i into substr
            if (words.find(str) != words.end() && rec(s, words, i, dp)) {
                return tc = true;
            }
        }
        return tc;
    }
};