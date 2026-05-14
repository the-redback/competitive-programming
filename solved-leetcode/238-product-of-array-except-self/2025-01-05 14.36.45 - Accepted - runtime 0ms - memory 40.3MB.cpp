class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        ans[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] * nums[i];
        }

        int left = 1;
        for (int i = 0; i < n - 1; i++) {
            ans[i] = left * ans[i + 1];
            left *= nums[i];
        }
        ans[ans.size() - 1] = left;

        return ans;
    }
};