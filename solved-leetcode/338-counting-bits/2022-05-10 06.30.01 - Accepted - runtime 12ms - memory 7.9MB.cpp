class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+2);
        
        for(int x=0; x<=n; x++){
            if(x<<1 <=n){
                ans[x<<1] = ans[x];            
                ans[(x<<1) + 1] = ans[x]+1;
            }
        }
        ans.pop_back();
        return ans;
    }
};