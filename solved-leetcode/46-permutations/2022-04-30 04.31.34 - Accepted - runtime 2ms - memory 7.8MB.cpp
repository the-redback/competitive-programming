class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            if (!taken[i]) {
                taken[i] = 1;
                comb.push_back(nums[i]);
                backtrack(nums);
                comb.pop_back();
                taken[i] = 0;
            }
        }
        return;
    }
};