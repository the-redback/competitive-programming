class Solution{
    public:

    vector<vector<int>> threeSum(vector<int>&nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;

        for(int i=0; i<nums.size() && nums[i] <= 0; i++ ){
            if(i==0 || nums[i] != nums[i-1])
                twoSum(nums, i, result);
        }
        return result;
    }

    void twoSum(vector<int>&nums, int k, vector<vector<int>>&result){
        for(int i=k+1, j=nums.size()-1; i<j; ){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum == 0){
                result.push_back({nums[i], nums[j], nums[k]});
                i++;
                j--;
                while(nums[i] == nums[i-1] && i<j)
                    i++;
            } else if(sum < 0){
                i++;
            } else {
                j--;
            }
        }
    }
};