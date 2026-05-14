class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return result;
    }

    int taken[10];
    vector<vector<int>> result;
    vector<int> comb;

    void backtrack(vector<int>& nums) {
        if (comb.size() == nums.size()) {
            result.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (taken[i]) continue;
            if (i != 0 && nums[i] == nums[i - 1] && taken[i - 1]) continue;

            taken[i] = 1;
            comb.push_back(nums[i]);
            backtrack(nums);
            comb.pop_back();
            taken[i] = 0;
        }
        return;
    }
};