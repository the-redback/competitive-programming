class Solution {
    vector<int> nums;

public:
    int rob(vector<int>& nums) {
        this->nums = nums;
        memset(dp, -1, sizeof(dp));
        return rec(nums.size() - 1);
    }

    int dp[101];

    int rec(int n) {
        if (n < 0) return 0;
        int& tc = dp[n];

        if (tc != -1) return tc;
        tc = rec(n - 1);
        tc = max(tc, rec(n - 2) + nums[n]);
        return tc;
    }
};