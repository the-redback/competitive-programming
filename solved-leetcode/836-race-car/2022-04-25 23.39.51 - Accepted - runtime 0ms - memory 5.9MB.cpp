class Solution {
    int dp[10010];
public:
    int racecar(int target) {
        int &tc = dp[target];
        if(tc > 0 )
            return tc;
        
        int n=floor(log2(target)) +1;
        
        if((1<<n) -1 == target)
            return tc=n;
        
         
        tc=racecar( (1<< n) - 1 - target) + n + 1;
        
        for(int m=0; m < n-1 ; m++){
            tc=min(tc, racecar(target  -( (1<<(n-1)) - (1<<m)) ) + n + m + 1);
        }
        return tc;
    }
};