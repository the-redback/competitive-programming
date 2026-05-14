class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool>mp;
        int i,n=nums.size();
        for(i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()) return true;
            mp[nums[i]]=1;
        }
        return false;
    }
};