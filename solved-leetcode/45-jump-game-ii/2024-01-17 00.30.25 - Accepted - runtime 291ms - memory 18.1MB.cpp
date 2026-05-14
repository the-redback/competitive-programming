#include <vector>
using namespace std;

class Solution {
public:
    int rec(vector<int>& nums, vector<int>& dp, int pos) {
        if (pos >= nums.size() - 1) return 0;

        int& tc = dp[pos];

        if (tc != -1) return tc;

        tc = 10000000;
        for (int i = pos + 1; i <= pos + nums[pos]; i++) {
            tc = min(tc, rec(nums, dp, i) + 1);
        }
        return tc;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int steps = rec(nums, dp, 0);
        return steps;
    }
};