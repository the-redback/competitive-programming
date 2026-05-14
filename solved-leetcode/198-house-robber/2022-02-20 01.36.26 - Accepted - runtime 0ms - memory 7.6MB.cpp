class Solution {
    vector<int>nums;
public:
    int rob(vector<int>& nums) {
        int robNextPlusOne = 0;
        int robNext=0;
        
        for(int i=nums.size()-1;i>=0;i--){
            int curr = max(robNextPlusOne+nums[i],robNext);
            
            robNextPlusOne=robNext;
            robNext=curr;
        }
        return robNext;
    }
};