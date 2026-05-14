class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, result);
            }
        }
        return result;
    }

    void twoSum(vector<int>& nums, int k, vector<vector<int>>& result) {
        for (int i = k + 1, j = nums.size() - 1; i < j;) {
            int sum = nums[k] + nums[i] + nums[j];
            if (sum == 0) {
                result.push_back({nums[k], nums[i], nums[j]});
                i++;
                j--;
                while (nums[i] == nums[i - 1] && i < j) i++;
            } else if (sum < 0)
                i++;
            else
                j--;
        }
        return;
    }
};