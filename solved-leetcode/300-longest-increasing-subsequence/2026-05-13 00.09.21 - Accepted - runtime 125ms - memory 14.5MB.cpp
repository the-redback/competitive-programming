class Solution {
public:
    int LIS(int u, vector<int>& nums, vector<int>& dp) {
        int& tc = dp[u];
        if (tc != -1) return tc;

        tc = 1;
        for (int i = u + 1; i < nums.size(); i++) {
            if (nums[i] > nums[u]) tc = max(tc, LIS(i, nums, dp) + 1);
        }
        return tc;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, LIS(i, nums, dp));
        }

        return ans;
    }
};