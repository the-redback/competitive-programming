class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        vector<int>dp(s.size(), -1);
        return rec(s, words, 0, dp);
    }

    bool rec(string &s, vector<string>& words, int step, vector<int> &dp){
        if(step >= s.size())
            return true;
        
        int &tc = dp[step];
        if(tc != -1)
            return tc;
        
        tc = 0;
        for(int k = 0; k < words.size(); k++){
            int len = words[k].size();
            if( step + len <= s.size() && s.compare(step, len, words[k]) == 0 ){
                if(rec(s, words, step + len, dp ))
                    return tc = true;
            }

        }
        return tc;
    }
};