#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        ans[ans.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] * nums[i];
        }

        int left = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans[i] = left * ans[i + 1];
            left *= nums[i];
        }
        ans[ans.size() - 1] = left;

        return ans;
    }
};