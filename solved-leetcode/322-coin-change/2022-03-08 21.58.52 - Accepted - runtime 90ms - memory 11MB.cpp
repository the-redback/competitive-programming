#define inf 10000007

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int temp=rec(coins,0,amount);
        if(temp>=inf)
            return -1;
        return temp;
    }
    
    int dp[13][10001];
    
    int rec(vector<int>& coins, int pos, int rem){
        if(rem ==0 )
            return 0;
        if(rem<0 || pos==coins.size())
            return inf;
        
        int &tc=dp[pos][rem];
        
        if(tc!=-1)
            return tc;
        
        tc=rec(coins,pos,rem-coins[pos])+1;
        tc=min(tc,rec(coins,pos+1, rem-coins[pos])+1);
        tc=min(tc,rec(coins,pos+1,rem));
        
        return tc;
    }
};