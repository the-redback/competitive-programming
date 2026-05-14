class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int gas=0;
        for(auto n: nums){
            if(gas<0)
                return false;
            if(n > gas)
                gas = n;
            gas--;
        }

        return true;
    }
};