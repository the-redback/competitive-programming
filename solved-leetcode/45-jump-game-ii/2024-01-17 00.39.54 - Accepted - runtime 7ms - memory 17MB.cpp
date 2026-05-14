#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // vector<int>dp(nums.size(),0);

        // dp[0]=nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i] + i, nums[i - 1]);
        }

        int pos = 0;
        int ans = 0;

        while (pos < nums.size() - 1) {
            pos = nums[pos];
            ans++;
        }

        return ans;
    }
};