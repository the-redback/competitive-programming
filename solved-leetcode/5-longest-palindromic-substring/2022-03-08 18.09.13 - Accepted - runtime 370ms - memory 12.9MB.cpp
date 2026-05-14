class Solution {
public:
    string longestPalindrome(string s) {
        mx=0;
        start=0;
        memset(dp,-1,sizeof(dp));
        memset(visited,0,sizeof(visited));
        
        findpal(s,0,s.size()-1);
        return s.substr(start,mx);
    }
    
    
private: 
    int dp[1001][1001];
    bool visited[1001][1001];
    
    bool ispal(string &s, int i,int j){
        if(i>=j)
            return true;
        
        int &tc=dp[i][j];
        
        if(tc!=-1)
            return tc;
        
        tc=false;
        if(s[i]==s[j])
            tc=ispal(s,i+1,j-1);
        return tc;
    }
    
    int mx;
    int start;
    
    void findpal(string &s, int i,int j){
        if(i>j)
            return;
        visited[i][j]=1;
        if(ispal(s,i,j))
        {
            if(j-i+1 > mx){
                mx=j-i+1;
                start=i;
            }
            return;
        }
        if(!visited[i+1][j])
            findpal(s,i+1,j);
        if(!visited[i][j-1])
            findpal(s,i,j-1);
        return;
    }
    
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
