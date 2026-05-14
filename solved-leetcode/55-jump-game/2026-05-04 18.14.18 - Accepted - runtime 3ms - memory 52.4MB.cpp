class Solution {
public:
    bool canJump(vector<int>& nums) {
        int gas = 0;

        for (int i = 0; i < nums.size(); i++, gas--) {
            if (gas < 0) return false;
            gas = max(gas, nums[i]);
        }

        return true;
    }
};