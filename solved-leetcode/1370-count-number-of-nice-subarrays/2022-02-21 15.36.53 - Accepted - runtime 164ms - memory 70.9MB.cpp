class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        deque<int>dq(k+1,-1);
        
        // dq.push_back(-1);
        // dq.push_back(-1);
        // dq.push_back(-1);
        
        int ans=0;
        int cnt=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]%2)
            {
                dq.push_back(right);
            }
            if(dq.size()==k+2){
                dq.pop_front();
            }
            if(dq[1]!=-1){
                ans+=dq[1]-dq[0];
            }
        }
        return ans;
    }
};