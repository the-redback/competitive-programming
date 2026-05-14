class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    vector<vector<int>> result;
    vector<int> comb;

    void backtrack(vector<int>& nums, int start) {
        result.push_back(comb);
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i - 1]) {
                comb.push_back(nums[i]);
                backtrack(nums, i + 1);
                comb.pop_back();
            }
        }
        return;
    }
};