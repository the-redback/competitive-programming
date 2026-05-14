class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> result;

        if(nums.size() == 0)
            return {{lower, upper}};
        
        if(nums[0] != lower)
            result.push_back({lower, nums[0]-1});
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1] + 1){
                result.push_back({nums[i-1] + 1, nums[i] - 1});
            }
        }

        if(nums[nums.size()-1 ] != upper)
            result.push_back({nums[nums.size()-1]+1, upper});
        
        return result;

    }
};