class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof(dp));
        prefix.resize(nums.size()+1);
        
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        
        return rec(0,m);
        
    }
    
    vector<int>prefix;
    int dp[1001][51];
    
    int rec(int pos, int m){
        if(m==1)
            return dp[pos][m]=prefix[prefix.size()-1]-prefix[pos];
         int &tc=dp[pos][m];
        if(tc!=-1)
            return tc;
        
        tc=INT_MAX;
        for(int i=pos;i<prefix.size()-m;i++){
            int curr_split=prefix[i+1]-prefix[pos];
            int temp=max(curr_split, rec(i+1,m-1) );
            tc=min(tc,temp);
        }
        return tc;
    }

};