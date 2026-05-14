class Solution {
public:
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        this->s=s;
        this->p=p;
        
        return rec(0,0);
    }
    
    int dp[31][31];
    string s;
    string p;
    
    int rec(int i, int j){
        if(j == p.size()){
            if(i==s.size())
                return true;
            return false;
        }
        
        int &tc=dp[i][j];
        if(tc !=-1)
            return tc;
        
        bool match=0;
        if(i<s.size() && (s[i] == p[j] || p[j]=='.'))
            match=true;
        
        tc=false;
        if(j +1 <p.size() && p[j+1]=='*'){
            tc=rec(i,j+2);
            if(match){
                tc |=rec(i+1,j);
            }
        } else if (match){
            tc |=rec(i+1, j+1);
        }
        
        return tc;
    }
};