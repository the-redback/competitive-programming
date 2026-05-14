class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        return max(rec(nums, dp, 1, 0), rec(nums, dp, 2, 1) + nums[0]);
    }

    int rec(vector<int>& nums, vector<vector<int>>& dp, int pos, int firstPos) {
        if (pos == nums.size() - 1) {
            if (firstPos == 0) return nums[pos];
            return 0;
        }
        if (pos >= nums.size()) return 0;

        int& tc = dp[pos][firstPos];
        if (tc != -1) return tc;

        tc = rec(nums, dp, pos + 1, firstPos);
        tc = max(tc, rec(nums, dp, pos + 2, firstPos) + nums[pos]);
        return tc;
    }
};