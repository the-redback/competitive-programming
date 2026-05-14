class Solution {
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(s, 0);
    }
    
    int dp[101];
    int rec(string &s, int index){
        if(index == s.size())
            return 1;
        
        if(s[index] == '0')
            return 0;
        
        int &tc=dp[index];
        if(tc != -1)
            return tc;
        
        tc=rec(s, index+1);
        if( index +1 < s.size() && stoi(s.substr(index, 2))<=26)
            tc+=rec(s, index+2);
        
        return tc;
    }
};