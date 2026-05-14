class Solution {
public:
    bool isMatch(string s, string p) {
        // string str=""
        // for(int i=0;i<p.size();i++){
        //     if(i!=0 || )
        // }
        vector<vector<int>> dp(s.length()+1,vector<int> (p.length()+1,-1));

        this->s=s;
        this->p=p;
        
        return rec(0,0, dp);
    }

    string s;
    string p;
    
    int rec(int i, int j, vector<vector<int>> &dp){
        if(j == p.size()){
            if(i==s.size())
                return true;
            return false;
        }
        
        int &tc=dp[i][j];
        if(tc !=-1)
            return tc;
        
        // if(i==s.size()){
        //     if(p[j]=='*')
        //         return tc=rec(i,j+1,dp);
        //     return tc=false;
        // }
        
        bool match=false;
        if(i<s.size() && (s[i] == p[j] || p[j]=='?'))
            match=true;
        
        tc=false;
        if (match){
            tc |=rec(i+1, j+1, dp);
        }else if(p[j]=='*'){
            tc=rec(i,j+1, dp);
            if(i<s.size())
                tc |=rec(i+1,j, dp);
        } 
        
        return tc;
    }
};