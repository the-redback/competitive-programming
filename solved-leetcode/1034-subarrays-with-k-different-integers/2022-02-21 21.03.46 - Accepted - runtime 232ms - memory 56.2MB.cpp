class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
    
    int atMost(vector<int>&nums, int k){
        int sum=0;
        map<int,int>mp;
        int i=0;
        
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            sum+=right-i+1;
        }
        return sum;
    }
};